function Count_Articles() {
  let next_btn = document.getElementsByClassName("next");
  let no_of_articles = 0;

  while (next_btn !== null) {
    no_of_articles += document.querySelectorAll(".entry-title").length;
    document.getElementsByClassName("next").click();
    next_btn = document.getElementsByClassName("next");
  }
  console.log(no_of_articles);
}
