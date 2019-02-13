
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
self.importScripts('WorkerFiles/Storeage.js');

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

// this function adds the pending changes onto 
// the suplpied base layer
var AddLayersForExtras = function(base){

  GetOfflineExtras().then((offline_extras)=>{

    var addLayer = (base, layer)=>{

      $.each(layer.add, (index, ingred)=>{
        base.push(ingred);
      });


      $.each(layer.del, (index, ingred)=>{
        base.push(ingred);
      });
      return base;
    }

    let result = base;
    $.each(offline_extras, (index, layer)=>{
      result = addLayer(result, layer);
    })
    return result;
  });
}

var AddLayersForSelected = function(base){

  GetOfflineSelected().then((offline_Selected)=>{

    var addLayer = (base, layer)=>{

      


    };

    let result = base;
    $.each(offline_extras, (index, layer)=>{
      result = addLayer(result, layer);
    })
    return result;


  });

}

var diffObj = function(obj1, obj2){

  let result = {};
  $.each(obj1, (index, val)=>{

    if(typeof(val) == "object"){
      result[index] = diffObj(obj1[index], obj2[index])
    } else if(!obj2.hasOwnProperty(index) || val !== obj2[index]){
      result[index] = val
    }

  });
}

var diffSelected = function(target){

  GetStoredSelected().then((selected)=>{

    let difs = diffObj(target, selected);
    return difs;
  });

}

var diffExtras = function(taret){

  GetStoredExtras().then((extras)=>{

    let stored_state = AddLayersForExtras(extras);
    let difs ={add:[], del:[]};
    // populate a list of names of ingredients in both lists
    let stored_ingreds = [];
    let target_ingreds = [];
    
    $.each(stored_state, (index, extra)=>{
      stored_ingreds.push(extra.ingreds);
    });

    $.each(target, (index, extra)=>{
      target_ingreds.push(extra.ingreds);
    });

    // now check for deletions and addidions using the arrays
    // as keys for the objects
    $.each(target, (index, extra)=>{
      if(!stored_ingreds.includes(extra.ingred))
      {
        difs.add.push(extra);
      }
    });

    $.each(stored_state, (index, extra)=>{
      if(!target_ingreds.includes(extra.ingred))
      {
        difs.del.push(extra);
      }
    });
  });

}

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
    //event.waitUntil(doSync());
    // sync is currently disabled to prevent 
    // ofline updates from screwing the server
  }
});


var doGetServerState = function(event){

  console.log("getting server state");

  return fetch(event.request).then(responce => {

    let serverState = responce.clone();
    // store the responce from the server incase we need to use it
    serverState.json().then((json)=>{
      CacheServerSelected(json);
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
      StoreOfflineUpdates(json);
    });


  });

}

var doUpdateExtras = function(event){

  // incase we need it when the request fails
  let request_copy = event.request.clone();

  return fetch(event.request).then(responce => {


    // store the data incase we need it later
    request_copy.json().then((json)=>{

      StoreExtras(json);

    }).catch((e)=>{
      console.log(e);
    });

    return responce;

  }).catch((e)=>{

    // store the new extras for sync later
    request_copy.json().then((json)=>{

      StoreOfflineExtras(json);

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

      CacheServerExtras(json);

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
    //event.waitUntil(doSync());
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