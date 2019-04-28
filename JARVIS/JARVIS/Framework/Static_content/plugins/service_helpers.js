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

var GetDataCacheThenUpdate = function(cachePromise, storeFn, request){
    cachePromise.then(result =>{
        
        let req = fetch(request).then(responce=>{
            storeFn(responce);
        });
        
        if(result !== undefined){
            req();

            return new Response(JSON.stringify(result), {
                headers: {'Content-Type': 'text/plain'}
            });

        } else {
            return req();
        }
    });
}