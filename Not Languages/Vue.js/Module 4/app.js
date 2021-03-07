const app = Vue.createApp({
  data() {
    return {
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
});

app.mount("#app");
