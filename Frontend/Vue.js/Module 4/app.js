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
          id: "Saitama",
          name: "One Punch Man",
          gamer_tag: "OPM",
          email: "OPM@gmail.com",
        },
      ],
    };
  },
});

//custom html elements (use dash to avoid clash for example dont name components h2)
//mini apps
app.component("friend-contact", {
  template: `    
    <li>
          <h2>{{ friend.name }}</h2>
          <button @click="toggleDetails">
            {{ details_visible ? 'Hide' : 'Show'}} Details
          </button>
          <ul v-if="details_visible">
            <li><strong>Gamer Name:</strong> {{ friend.gamer_tag }}</li>
            <li><strong>Email:</strong> {{ friend.email }}</li>
          </ul>
    </li>`,
  data() {
    return {
      details_visible: false,
      friend: {
        id: "Hiba",
        name: "Hiba Abdullah",
        gamer_tag: "Ms_birb",
        email: "Hiba_razzaq00@gmail.com",
      },
    };
  },
  methods: {
    toggleDetails() {
      this.details_visible = !this.details_visible;
    },
  },
});
app.mount("#app");
