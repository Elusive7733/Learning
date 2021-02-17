const app = Vue.createApp({
  data() {
    //same as data: function(){}
    return {
      goal: "Learn Vue", //this variable can be anything
      goal_2: "<h2>Tf nigga</h2>",
      vueLink: "https://nuxtjs.org/",
    }; //returns an object
  },
  methods: {
    outputgoal() {
      const randomNumber = Math.random();
      if (randomNumber < 0.5) {
        return this.goal;
      } else {
        return "Master Vue";
      }
    },
  },
});

app.mount("#user-goal");
