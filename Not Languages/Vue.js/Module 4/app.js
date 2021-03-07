const app = Vue.createApp({
  data() {
    return {
      details_visible: false,
      friends: [
        {
          id: "Abdullah",
          name: "Abdullah Raheel",
          gamer_tag: "Elusive",
          email: "Abdullaharaheel@gmail.com",
        },
        {
          id: "Hiba",
          name: "Hiba Abdullah",
          gamer_tag: "Ms_birb",
          email: "Hiba_razzaq00@gmail.com",
        },
      ],
    };
  },
  methods: {
    toggleDetails() {
      this.details_visible = !this.details_visible;
    },
  },
});

//custom html elements (use dash to avoid clash for example dont name components h2)
app.component("friend-contact");
app.mount("#app");
