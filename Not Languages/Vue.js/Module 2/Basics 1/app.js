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
    },
    removeGoal(index) {
      this.goals.splice(index, 1);
    },
  },
});

app.mount("#user-goals");
