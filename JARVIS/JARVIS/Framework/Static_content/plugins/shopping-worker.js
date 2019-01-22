
// Names of the two caches used in this version of the service worker.
// Change to v2, etc. when you update any of the local resources, which will
// in turn trigger the install event again.
const PRECACHE = 'precache-v1';
const RUNTIME = 'runtime';

// A list of local resources we always want to be cached.
const PRECACHE_URLS = [
  'Shopping.html',
  'ShoppingList',
  'Shopping_content/js/script.js',
  'Shopping_content/js/jquery.min.js',
  'Shopping_content/js/jquery-ui.min.js',
  'Shopping_content/css/styles.css',
  'Shopping_content/css/jquery-ui.min.css',
];

var lastSelected = {}; 

self.importScripts('Shopping_content/js/idb.js');

// The install handler takes care of precaching the resources we always need.
self.addEventListener('install', event => {
  event.waitUntil(
    caches.open(PRECACHE)
      .then(cache => cache.addAll(PRECACHE_URLS))
      .then(self.skipWaiting())
      .catch((error)=>{console.error(error)})
  );
});

// The activate handler takes care of cleaning up old caches.
self.addEventListener('activate', event => {
  const currentCaches = [PRECACHE, RUNTIME];
  event.waitUntil(
    caches.keys().then(cacheNames => {
      return cacheNames.filter(cacheName => !currentCaches.includes(cacheName));
    }).then(cachesToDelete => {
      return Promise.all(cachesToDelete.map(cacheToDelete => {
        return caches.delete(cacheToDelete);
      }));
    }).then(() => self.clients.claim())
  );
});

var StoreSelectedItems = function(selectedItems){
  var dbPromise = idb.open('selected-db', 1, function(upgradeDb) {
    console.log("creating Selected ingredients store")
    if (!upgradeDb.objectStoreNames.contains('selectedIngreds')) {
      var selectedIngreds = upgradeDb.createObjectStore('selectedIngreds');
      selectedIngreds.createIndex('id', 'id', {unique: true});
    }
  });


  dbPromise.then(function(db) {
    var tx = db.transaction('selectedIngreds', 'readwrite');
    var store = tx.objectStore('selectedIngreds');
    // id is currently unused
    store.put(selectedItems, 1);
    return tx.complete;
  }).then(function() {
    console.log('added item to the store os!');
  });

}

var GetStoredSelected = function(){
  
  var dbPromise = idb.open('selected-db', 1, function(upgradeDb) {
    console.log("creating Selected ingredients store")
    if (!upgradeDb.objectStoreNames.contains('selectedIngreds')) {
      var selectedIngreds = upgradeDb.createObjectStore('selectedIngreds');
      selectedIngreds.createIndex('id', 'id', {unique: true});
    }
  });

  // return a promice which resolves with the value of the selected
  return dbPromise.then(function(db) {
    var tx = db.transaction('selectedIngreds', 'readonly');
    var store = tx.objectStore('selectedIngreds');
    return store.get(1);
  });

};

var ClearPendingSelected = function(){
  var dbPromise = idb.open('selected-db', 1, function(upgradeDb) {
    console.log("creating Selected ingredients store")
    if (!upgradeDb.objectStoreNames.contains('selectedIngreds')) {
      var selectedIngreds = upgradeDb.createObjectStore('selectedIngreds');
      selectedIngreds.createIndex('id', 'id', {unique: true});
    }
  });

  // return a promice which once resolved clears db
  return dbPromise.then(function(db) {
    var tx = db.transaction('selectedIngreds', 'readwrite');
    var store = tx.objectStore('selectedIngreds');
    return store.clear();
  });
}

var SendMessageToClient = function(msg){
  var msg_chan = new MessageChannel();
  client.postMessage(msg, [msg_chan.port2]);
}

self.addEventListener('sync', function(event) {
  if (event.tag == 'sync') {

    var doSync = ()=>{
      return GetStoredSelected().then(
        (selected)=>{
          if(selected === undefined){
            return new Promise();
          }
          return fetch("/plugins/ShoppingList/PendingSelected",{
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify(selected),
          });
        }
      ).then(()=>{
        ClearPendingSelected();
      }).catch(()=>{
        ClearPendingSelected();
      });
    }

    event.waitUntil(doSync());
  }
});


var doGetSelected = function(event){

  console.log("getting selected");

  return fetch(event.request).then(responce => {

    let newSelected = responce.clone();
    // store the responce from the server incase we need to use it
    newSelected.json().then((json)=>{
      StoreSelectedItems(json);
    });

    return responce;

  }).catch(()=>{

    // the request failed, we are probb offline so we need
    // to fake this request with our latest available knowledge. 
    return GetStoredSelected().then(selected => {
      return new Response(JSON.stringify(selected), {
        headers: {'Content-Type': 'text/plain'}
      });
    })
  });

}

var doUpdateSelected = function(event){

  console.log("updating selected, skipping cache");

  // you need to do this dumb clone thing, 
  // because reading the json counts as 'using' the request 
  // which the browser gets grumpy about.
  let newSelected = event.request.clone();
  newSelected.json().then((json)=>{
    StoreSelectedItems(json);
    lastSelected = json;
  });

  return fetch(event.request).then((responce)=>{
    return responce;
  }).catch(()=>{

    // this request requires no responce from the server
    // we do this because this request dosnt need to fail
    // we have stored the state of the selected and itll be 
    // synced when we connect again
    return new Response("", {
      headers: {'Content-Type': 'application/json'}
    });


  });
}
// The fetch handler serves responses for same-origin resources from a cache.
// If no response is found, it populates the runtime cache with the response
// from the network before returning it to the page.
self.addEventListener('fetch', event => {
  // Skip cross-origin requests, like those for Google Analytics.

  // handle specific requests
  if(event.request.url.includes("GetSelected")){ event.respondWith(doGetSelected(event)); return; }
  if(event.request.url.includes("UpdateSelected")){ event.respondWith(doUpdateSelected(event)); return; }

  // try get from server first

  event.respondWith(
    fetch(event.request).then(response => {

    // Put a copy of the response in the runtime cache.
    return cache.put(event.request, response.clone()).then(() => {
      return response;
    });

  }).catch((e)=>{

    return caches.open(RUNTIME).then(cache => {
      return caches.match(event.request)
    })

  }));
});