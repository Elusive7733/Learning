const app = Vue.createApp({
  data() {
    return {
      counter: 100,
      name: "Elusive",
    };
  },
  computed: {}, // calculate output value dynamically
  watch: {
    // execute code because something changed
    counter(value) {
      if (value > 500) {
        this.counter = 0;
      }
    },
  },
  methods: {
    add_counter(num) {
      this.counter += num;
    },
    subtract_counter(num) {
      this.counter -= num;
    },
    set_name(event) {
      this.name = event.target.value;
    },
    submitForm() {
      alert("Form Submitted");
    },
  },
});

app.mount("#events");
