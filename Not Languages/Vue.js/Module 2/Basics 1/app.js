const app = Vue.createApp({
  data() {
    return {
      goals: [],
      goal_data: "",
    };
  },
  methods: {
    addGoal() {
      this.goals.push(this.goal_data);
      this.goal_data = "";
      console.log(this.goals);
    },
  },
});

app.mount("#user-goals");
