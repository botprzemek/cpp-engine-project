// #include "state_manager.h"

// StateManager::StateManager() {}

// StateManager::~StateManager() {}

// class StateManager {
// public:
//     StateManager() {
//         state = IDLE;
//     }
//     ~StateManager() {}

//     enum Type {
//         IDLE,
//         RUNNING,
//         ACTIVE,
//         STOPPED,
//     };

//     void run() {
//         state = RUNNING;
//     }
//     void activate() {
//         state = ACTIVE;
//     }
//     void stop() {
//         state = STOPPED;
//     }

//     bool isIdling() {
//         return state == IDLE;
//     }
//     bool isRunning() {
//         return state == RUNNING;
//     }
//     bool isActive() {
//         return state == ACTIVE;
//     }
//     bool isStopped() {
//         return state == STOPPED;
//     }
// private:
//     Type state;
// };