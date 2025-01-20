#include "engine.h"

Engine* Engine::instance;
mutex Engine::mtx;

Engine::Engine()
    : stateManager(new StateManager()),
    handlerManager(new HandlerManager()) {}

Engine::~Engine() {
    delete stateManager;
    delete handlerManager;
}

Engine* Engine::get() {
    lock_guard<mutex> lock(mtx);

    if (!instance) {
        instance = new Engine();
    }

    return instance;
}

HandlerManager* Engine::getHandlerManager() {
    return handlerManager;
}

StateManager* Engine::getStateManager() {
    return stateManager;
}

Engine* Engine::start() {
    while (true) {
        handlerManager->handle();
    }

    return instance;
}

void Engine::stop() {
    abort();
}