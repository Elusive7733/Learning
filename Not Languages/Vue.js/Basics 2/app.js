const app = Vue.createApp({
  data() {
    return {
      counter: 0,
    };
  },
  methods: {
    add_counter() {
      this.counter += 1;
    },
    subtract_counter() {
      this.counter -= 1;
    },
  },
});

app.mount("#events");
