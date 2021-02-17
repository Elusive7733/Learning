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
    set_name(event) {
      console.log(event);
      console.log(event.target);
      this.name = event.target.value;
    },
  },
});

app.mount("#events");
