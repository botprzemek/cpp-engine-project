#ifndef ENGINE_H
#define ENGINE_H

#include "controls.h"
#include "state.h"
#include "handler.h"

#include <map>
#include <mutex>
#include <string>

class Engine {
public:
    static Engine* get();

    StateManager* getStateManager();
    HandlerManager* getHandlerManager();
    
    Engine* start();
    void stop();
private:
    Engine();
    ~Engine();

    static Engine* instance;
    static mutex mtx;

    StateManager* stateManager;
    HandlerManager* handlerManager;
};

#endif // ENGINE_H
