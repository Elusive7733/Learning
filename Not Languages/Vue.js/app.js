const app = Vue.createApp({
  data() {
    //same as data: function(){}
    return {
      goal: "Learn Vue", //this variable can be anything
    }; //returns an object
  },
});

app.mount("#user-goal");
