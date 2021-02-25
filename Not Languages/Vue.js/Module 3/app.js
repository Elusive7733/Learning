function getRandom(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}

const app = Vue.createApp({
  data() {
    return {
      player_health: 100,
      enemy_health: 100,
      round: 0,
      game_end: false,
      win: null,
    };
  },
  computed: {
    enemyBarStyle() {
      if (this.enemy_health < 0) {
        return { width: "0%" };
      }
      return { width: this.enemy_health + "%" };
    },
    playerBarStyle() {
      if (this.player_health < 0) {
        return { width: "0%" };
      }
      return { width: this.player_health + "%" };
    },
    useSpecialAttack() {
      return this.round % 3 !== 0; //this returns true or false
    },
    useHeal() {
      return this.round % 2 !== 0; //this returns true or false
    },
  },
  watch: {
    //instead of making a lot of if statements in every function we can use watchers
    player_health(value) {
      if (value <= 0 && this.enemy_health <= 0) {
        this.win = null;
        this.game_end = true;
      } else if (value <= 0) {
        this.win = false;
        this.game_end = true;
      }
    },
    enemy_health(value) {
      if (value <= 0 && this.player_health <= 0) {
        this.win = null;
        this.game_end = true;
      } else if (value <= 0) {
        this.win = true;
        this.game_end = true;
      }
    },
  },
  methods: {
    attack() {
      this.round++;
      let dmg = getRandom(3, 10);
      this.enemy_health -= dmg;
      this.defend();
    },
    defend() {
      let dmg = getRandom(7, 14);
      this.player_health -= dmg;
    },
    specialAttack() {
      this.round++;
      let dmg = getRandom(19, 19);
      this.enemy_health -= dmg;
      this.defend();
    },
    heal() {
      this.round++;
      let healValue = getRandom(20, 20);
      if (this.player_health + healValue > 100) {
        this.player_health = 100;
      } else {
        this.player_health += healValue;
      }
      this.defend();
    },
    startGame() {
      this.player_health = 100;
      this.enemy_health = 100;
      this.round = 0;
      this.game_end = false;
      this.win = null;
    },
  },
});

app.mount("#game");
