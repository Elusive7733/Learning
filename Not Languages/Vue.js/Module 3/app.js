function getRandom(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}

const app = Vue.createApp({
  data() {
    return {
      player_health: 100,
      enemy_health: 100,
      round: 0,
    };
  },
  computed: {
    enemyBarStyle() {
      return { width: this.enemy_health + "%" };
    },
    playerBarStyle() {
      return { width: this.player_health + "%" };
    },
    useSpecialAttack() {
      return this.round % 3 !== 0;
    },
  },
  methods: {
    attack() {
      this.round++;
      let dmg = getRandom(3, 20);
      this.enemy_health -= dmg;
      this.defend();
    },
    defend() {
      let dmg = getRandom(8, 25);
      this.player_health -= dmg;
    },
    specialAttack() {
      this.round++;
      let dmg = getRandom(10, 30);
      this.enemy_health -= dmg;
      this.defend();
    },
  },
});

app.mount("#game");
