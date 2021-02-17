const app = Vue.createApp({
  data() {
    //same as data: function(){}
    return {
      goal: "Learn Vue", //this variable can be anything
      vueLink: "https://nuxtjs.org/",
    }; //returns an object
  },
  methods: {
    outputgoal() {
      const randomNumber = Math.random();
      if (randomNumber < 0.5) {
        return "Learn Vue";
      } else {
        return "Master Vue";
      }
    },
  },
});

app.mount("#user-goal");
