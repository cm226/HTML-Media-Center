
// Names of the two caches used in this version of the service worker.
// Change to v2, etc. when you update any of the local resources, which will
// in turn trigger the install event again.
const PRECACHE = 'precache-v1';
const RUNTIME = 'runtime';

// A list of local resources we always want to be cached.
const PRECACHE_URLS = [
  'Shopping.html',
  'Shopping_content/js/script.js',
  'Shopping_content/js/jquery.min.js',
  'Shopping_content/js/jquery-ui.min.js',
  'Shopping_content/js/jquery.mobile-1.4.5.min.js',
  'Shopping_content/css/styles.css',
  'Shopping_content/css/jquery-ui.min.css',
  'Shopping_content/css/jquery.mobile-1.4.5.min.css'
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

var StoreExtras = function(extras){
  var dbPromise = idb.open('extras-db', 1, function(upgradeDb) {
    console.log("creating extras ingredients store")
    if (!upgradeDb.objectStoreNames.contains('extras')) {
      var selectedIngreds = upgradeDb.createObjectStore('extras');
      selectedIngreds.createIndex('id', 'id', {unique: true});
    }
  });


  dbPromise.then(function(db) {
    var tx = db.transaction('extras', 'readwrite');
    var store = tx.objectStore('extras');
    // id is currently unused
    store.put(extras, 1);
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


var GetStoredExtras = function(){
  
  var dbPromise = idb.open('extras-db', 1, function(upgradeDb) {
    console.log("creating extras ingredients store")
    if (!upgradeDb.objectStoreNames.contains('extras')) {
      var selectedIngreds = upgradeDb.createObjectStore('extras');
      selectedIngreds.createIndex('id', 'id', {unique: true});
    }
  });

  // return a promice which resolves with the value of the selected
  return dbPromise.then(function(db) {
    var tx = db.transaction('extras', 'readonly');
    var store = tx.objectStore('extras');
    return store.get(1);
  });

};


var SendMessageToClient = function(msg){

  // broadcast our message
  self.clients.matchAll().then(
    all => all.map(client => client.postMessage(msg)));
}

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
  ).catch((e)=>{
    console.error(e);
  });
}

self.addEventListener('sync', function(event) {
  if (event.tag == 'sync') {
    event.waitUntil(doSync());
  }
});


var doGetServerState = function(event){

  console.log("getting server state");

  return fetch(event.request).then(responce => {

    let serverState = responce.clone();
    // store the responce from the server incase we need to use it
    serverState.json().then((json)=>{
      StoreSelectedItems(json);
    });

    // inform the client that we are connected to the server
    SendMessageToClient("connected");
    return responce;

  }).catch((e)=>{

    // the request failed, we are probb offline so we need
    // to fake this request with our latest available knowledge. 
    return GetStoredSelected().then(selected => {
      if(selected === undefined){
        console.error ("got undefined responce from selected indexDB query");
        selected = "";
      }
      return new Response(JSON.stringify(selected), {
        headers: {'Content-Type': 'text/plain'}
      });
    })
  });
}

var doUpdateServerState = function(event){

  // incase we need it when the request fails
  let request_copy = event.request.clone();

  return fetch(event.request).then(responce => {

    // update local representation as well
    request_copy.json().then((json)=>{
      StoreSelectedItems(json);
    });

    return responce;

  }).catch((e)=>{

    // store the new state for when we are online again
    request_copy.json().then((json)=>{
      StoreSelectedItems(json);
    });


  });

}

var doUpdateExtras = function(event){

  // incase we need it when the request fails
  let request_copy = event.request.clone();

  return fetch(event.request).then(responce => {

    let extras = responce.clone();
    // store the responce from the server incase we need to use it
    extras.json().then((json)=>{

      StoreExtras(json);

    }).catch((e)=>{
      console.log(e);
    });

    return responce;

  }).catch((e)=>{

    // store the new extras for sync later
    request_copy.json().then((json)=>{

      StoreExtras(json);

    }).catch((e)=>{
      console.log(e);
    });

    return new Response("", {
      headers: {'Content-Type': 'text/plain'}
    });

  });


}

var doGetExtras = function(event){

  return fetch(event.request).then(responce => {

    let extras = responce.clone();
    // store the responce from the server incase we need to use it
    extras.json().then((json)=>{

      StoreExtras(json);

    }).catch((e)=>{
      console.log(e);
    });

    return responce;

  }).catch((e)=>{

    return GetStoredExtras().then(selected => {
      if(selected === undefined){
        console.error ("got undefined responce from selected indexDB query");
        selected = "";
      }
      return new Response(JSON.stringify(selected), {
        headers: {'Content-Type': 'text/plain'}
      });
    })
    
  });


}

// The fetch handler serves responses for same-origin resources from a cache.
// If no response is found, it populates the runtime cache with the response
// from the network before returning it to the page.
self.addEventListener('fetch', event => {
  // Skip cross-origin requests, like those for Google Analytics.

  // handle specific requests
  if(event.request.url.includes("UpdateSelected")){ event.respondWith(doUpdateServerState(event)); return; }

  if(event.request.url.includes("UpdateExtras")){ event.respondWith(doUpdateExtras(event)); return; }
  if(event.request.url.includes("GetExtras")){ event.respondWith(doGetExtras(event)); return; }

  if(event.request.url.includes("ShoppingList")){ 
    event.waitUntil(doSync());
    event.respondWith(doGetServerState(event));
    return;
  }
  

  // try get from server first

  event.respondWith(
    fetch(event.request).then(response => {

    // Put a copy of the response in the runtime cache.
    var new_responce = response.clone();
    caches.open(RUNTIME).then(
        cache => {
          cache.put(event.request, new_responce)
    });

    return response;

  }).catch((e)=>{

    return caches.open(RUNTIME).then(cache => {
      return caches.match(event.request)
    })

  }));
});