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
      return this.round % 3 !== 0; //this returns true or false
    },
  },
  watch: {
    //instead of making a lot of if statements in every function we can use watchers
    player_health(value) {
      if (value <= 0 && this.enemy_health <= 0) {
        //a draw
      } else if (value <= 0) {
        //player lost
      }
    },
    enemy_health(value) {
      if (value <= 0 && this.player_health <= 0) {
        //a draw
      } else if (value <= 0) {
        //player lost
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
      let dmg = getRandom(9, 16);
      this.enemy_health -= dmg;
      this.defend();
    },
    heal() {
      this.round++;
      let healValue = getRandom(10, 20);
      if (this.player_health + healValue > 100) {
        this.player_health = 100;
      } else {
        this.player_health += healValue;
      }
      this.defend();
    },
  },
});

app.mount("#game");
