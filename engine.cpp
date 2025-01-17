#include "engine.h"

Engine* Engine::instance;
mutex Engine::mtx;

Engine::Engine() {
    controls = new Controls();
};

Engine* Engine::get() {
    if (instance) {
        return instance;
    }

    lock_guard<mutex> lock(mtx);
    
    if (!instance) {
        instance = new Engine();
    }
    
    return instance;
}

Engine* Engine::start() {
    while(isRunning) {
        const Controls::KEY_INPUT key = controls->getKey();

        switch(key) {
            case Controls::UP:
                cout << "Move Up" << endl;
                break;
            case Controls::DOWN:
                cout << "Move Down" << endl;
                break;
            case Controls::LEFT:
                cout << "Move Left" << endl;
                break;
            case Controls::RIGHT:
                cout << "Move Right" << endl;
                break;
            case Controls::CONFIRM:
                cout << "Confirmed" << endl;
                break;
            case Controls::UNKNOWN:
            default:
                cout << "Unknown Key Pressed" << endl;
                break;
        }
    }

    return get();
}

Controls* Engine::getControls() {
    if (!controls) {
        controls = new Controls();
    }

    return controls;
}