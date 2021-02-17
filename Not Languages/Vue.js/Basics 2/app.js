const app = Vue.createApp({
  data() {
    return {
      counter: 0,
      name: "Elusive",
    };
  },
  methods: {
    add_counter(num) {
      this.counter += num;
    },
    subtract_counter(num) {
      this.counter -= num;
    },
  },
});

app.mount("#events");
