function gimmeData(){
    let dataPromise = new Promise((resolve, reject) => {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200) {
                resolve(this.responseText);
            }
        };

        xhttp.onerror = function () {
            reject("No ajax");
        };

        xhttp.open("GET", "/plugins/Bev/Check", true);
        xhttp.send();
    })

    return dataPromise;
}