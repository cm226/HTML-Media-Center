var GetFromCacheThenUpdate = function(cache, request){

    return caches.open(cache).then(cache => {
        return caches.match(request).then(function(responce){
            return responce || fetch(request).then(function(resonce){
                cache.put(request, responce.clone());
                return responce;
            })
        })
      })
}