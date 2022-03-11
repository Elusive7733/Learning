//creating an XMLHttpRequest object
const http = new XMLHttpRequest();

//sending our request to the api
http.open("GET", "https://jsonplaceholder.typicode.com/posts");
http.send();

//handling the returned data
http.onreadystatechange = (e) => {
  if (this.readyState == 4 && this.status == 200) {
    //do something...
  }
};
