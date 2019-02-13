
var StoreOfflineUpdates = function(selectedItems){
    var dbPromise = idb.open('offline-db', 1, function(upgradeDb) {
      if (!upgradeDb.objectStoreNames.contains('offlineSelected')) {
        var offlineSelected = upgradeDb.createObjectStore('offlineSelected');
        offlineSelected.createIndex('id', 'id', {unique: true});
      }
    });
  
  
    dbPromise.then(function(db) {
      var tx = db.transaction('offlineSelected', 'readwrite');
      var store = tx.objectStore('offlineSelected');
      // id is currently unused
  
      var diff_items = diffSelected(selectedItems);
      store.put(diff_items);
      return tx.complete;
    });
  
  }


var StoreOfflineExtras = function(extras){
    var dbPromise = idb.open('offline-extras-db', 1, function(upgradeDb) {
        if (!upgradeDb.objectStoreNames.contains('offlineExtras')) {
        var offlineSelected = upgradeDb.createObjectStore('offlineExtras');
        offlineSelected.createIndex('id', 'id', {unique: true});
        }
    });


    return dbPromise.then(function(db) {
        var tx = db.transaction('offlineExtras', 'readwrite');
        var store = tx.objectStore('offlineExtras');
        // id is currently unused

        var diff_items = diffExtras(extras);
        store.put(diff_items);
        return tx.complete;
    });

}

var GetOfflineExtras = function(){

    var dbPromise = idb.open('offline-db', 1, function(upgradeDb) {
        if (!upgradeDb.objectStoreNames.contains('offlineExtras')) {
        var offlineSelected = upgradeDb.createObjectStore('offlineExtras');
        offlineSelected.createIndex('id', 'id', {unique: true});
        }
    });


    return dbPromise.then(function(db) {
        var tx = db.transaction('offlineExtras', 'readwrite');
        var store = tx.objectStore('offlineExtras');
        // id is currently unused

        return store.getAll();
    });

}

var GetOfflineSelected = function(){

    var dbPromise = idb.open('offline-extras-db', 1, function(upgradeDb) {
        if (!upgradeDb.objectStoreNames.contains('offlineSelected')) {
        var offlineSelected = upgradeDb.createObjectStore('offlineSelected');
        offlineSelected.createIndex('id', 'id', {unique: true});
        }
    });


    return dbPromise.then(function(db) {
        var tx = db.transaction('offlineSelected', 'readwrite');
        var store = tx.objectStore('offlineSelected');
        // id is currently unused

        return store.getAll();
    });

}


var CacheServerSelected = function(selectedItems){
    var dbPromise = idb.open('selected-db', 1, function(upgradeDb) {
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
    });
  
  }


var CacheServerExtras = function(extras){
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
  