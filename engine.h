#ifndef ENGINE_H
#define ENGINE_H

#include "controls.h"

#include <map>
#include <mutex>
#include <string>

#include <iostream>

using namespace std;

class Engine {
public:
    static Engine* get();

    Engine* start();
    Controls* getControls();
private:
    static Engine* instance;
    static mutex mtx;
    Controls* controls;

    Engine();
};

#endif // ENGINE_H
