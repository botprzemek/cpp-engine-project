#ifndef HANDLER_H
#define HANDLER_H

#include "controls.h"

class Handler {
public:
    Handler(bool isActive = false);
    ~Handler();

    virtual void handle(Controls::KeyInput key);
    virtual void render();

    bool isActive();
private:
    bool active;
};

#endif // HANDLER_H
