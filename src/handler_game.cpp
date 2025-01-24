#include "handler_game.h"

// class Player {
// public:
//     Player() {
//         StatisticsBuilder* statisticsBuilder = new StatisticsBuilder();

//         statistics = statisticsBuilder
//             ->defense(2)
//             ->level(1)
//             ->mana(2)
//             ->stamina(2)
//             ->get();
//     }
//     ~Player() {}
// private:
//     Statistics* statistics;
// };

// class Enemy {
// public:
//     Enemy() {}
//     ~Enemy() {}
// private:
//     Statistics* statistics;
// };

// class Statistics {
// public:
//     Statistics() {}
//     ~Statistics() {}

//     int getDefense() {
//         return defense;
//     }
//     int getHealth() {
//         return health;
//     }
//     int getLevel() {
//         return level;
//     }
//     int getMana() {
//         return mana;
//     }
//     int getStamina() {
//         return stamina;
//     }

//     void setDefense(int value) {
//         defense = value;
//     }
//     void setHealth(int value) {
//         health = value;
//     }
//     void setLevel(int value) {
//         level = value;
//     }
//     void setMana(int value) {
//         mana = value;
//     }
//     void setStamina(int value) {
//         stamina = value;
//     }
// private:
//     int defense;
//     int health;
//     int level;
//     int mana;
//     int stamina;
// };

// class StatisticsBuilder {
// public:
//     StatisticsBuilder() {
//         instance = new Statistics();
//     }

//     StatisticsBuilder* defense(int value) {
//         instance->setDefense(value);

//         return this;
//     }
//     StatisticsBuilder* defense(int value) {
//         instance->setDefense(value);

//         return this;
//     }
//     StatisticsBuilder* level(int value) {
//         instance->setDefense(value);

//         return this;
//     }
//     StatisticsBuilder* mana(int value) {
//         instance->setDefense(value);

//         return this;
//     }
//     StatisticsBuilder* stamina(int value) {
//         instance->setDefense(value);

//         return this;
//     }

//     Statistics* get() {
//         return instance;
//     }
// private:
//     Statistics* instance;
// };

// class Level {
// public:
//     Level(const Player* player) {
//         for (int i = 0; i < 3; i++) {
//             enemies.push_back(new Enemy());
//         }
//     }
//     ~Level() {}
// private:
//     vector<Enemy*> enemies;
// };

void GameHandler::prepare() {
    // const Player* player = new Player();

    // const Level* level = new Level(player);
}

void GameHandler::handle(Controls::KeyInput key) {
    switch (key) {
        case Controls::UP:
            break;
        case Controls::DOWN:
            break;
        case Controls::LEFT:
            break;
        case Controls::RIGHT:
            break;
        case Controls::CONFIRM:
            break;
        default:
            break;
    }
}

void GameHandler::render() {}