#ifndef HANDLER_MANAGER_H
#define HANDLER_MANAGER_H

#include "controls.h"
#include "handler.h"
#include "handler_game.h"
#include "handler_menu.h"

class HandlerManager {
public:
    HandlerManager();
    ~HandlerManager();

    void handle();
    void render();
    void setGame();
    void setMenu();
private:
    Controls* controls;

    Handler* active;
    GameHandler* game;
    MenuHandler* menu;
};

#endif // HANDLER_MANAGER_H