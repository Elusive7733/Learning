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
      log_messages: [],
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
      this.updateLog("Player", "Attacks", "Monster", dmg);
      this.defend();
    },
    defend() {
      let dmg = getRandom(7, 14);
      this.player_health -= dmg;
      this.updateLog("Monster", "Attacks", "Player", dmg);
    },
    specialAttack() {
      this.round++;
      let dmg = getRandom(19, 19);
      this.enemy_health -= dmg;
      this.updateLog("Player", "Ultimates", "Monster", dmg);
      this.defend();
    },
    heal() {
      this.round++;
      let heal_value = getRandom(11, 17);
      if (this.player_health + heal_value > 100) {
        heal_value = 100 - player_health;
        this.player_health = 100;
        this.updateLog("Player", "Heals", "Player", heal_value);
      } else {
        this.player_health += heal_value;
        this.updateLog("Player", "Heals", "Player", heal_value);
      }
      this.defend();
    },
    startGame() {
      this.player_health = 100;
      this.enemy_health = 100;
      this.round = 0;
      this.game_end = false;
      this.win = null;
      this.log_messages = [];
    },
    surrender() {
      this.game_end = true;
      this.win = false;
    },
    updateLog(who, what, whom, value) {
      // we dont take whom because only 2 characters here
      this.log_messages.unshift({
        action_by: who,
        action_type: what,
        action_to: whom,
        action_value: value,
      });
    },
  },
});

app.mount("#game");
