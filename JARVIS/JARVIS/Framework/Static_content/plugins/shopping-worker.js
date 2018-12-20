
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

// The install handler takes care of precaching the resources we always need.
self.addEventListener('install', event => {
  event.waitUntil(
    caches.open(PRECACHE)
      .then(cache => cache.addAll(PRECACHE_URLS))
      .then(self.skipWaiting())
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

// The fetch handler serves responses for same-origin resources from a cache.
// If no response is found, it populates the runtime cache with the response
// from the network before returning it to the page.
self.addEventListener('fetch', event => {
  // Skip cross-origin requests, like those for Google Analytics.
    event.respondWith(
      caches.match(event.request).then(cachedResponse => {
        
        // get selected should always attempt server first
        // to get the latest selected even if its cached
        if(event.request.url.includes("GetSelected")){
          console.log("getting selected");

          return fetch(event.request);
        }

        if (cachedResponse) {
          return cachedResponse;
        }

        if(event.request.url.includes("UpdateSelected")){
          console.log("updating selected, skipping cache");

          // you need to do this dumb clone thing, 
          // because reading the json counts as 'using' the request 
          // which the browser gets grumpy about.
          let requestclone = event.request.clone();
          requestclone.json().then((json)=>{
            console.log(json);
          });
          
          return fetch(event.request);
        }

        return caches.open(RUNTIME).then(cache => {

          return fetch(event.request).then(response => {
            // Put a copy of the response in the runtime cache.
            return cache.put(event.request, response.clone()).then(() => {
              return response;
            });
          });
        });
      })
    );
});