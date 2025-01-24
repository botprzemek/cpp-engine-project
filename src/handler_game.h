#ifndef HANDLER_GAME_H
#define HANDLER_GAME_H

#include "handler.h"

class GameHandler : public Handler {
public:
    void handle(Controls::KeyInput key);
    void render();
    void prepare();
};

#endif // HANDLER_GAME_H