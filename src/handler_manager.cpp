#include "handler_manager.h"

#include "handler_menu.h"
#include "handler_game.h"

HandlerManager::HandlerManager()
    : controls(new Controls()),
    game(new GameHandler()),
    menu(new MenuHandler(true)) {
        active = menu;
        game->prepare();
    }

HandlerManager::~HandlerManager() {
    delete controls;
    delete active;
}

void HandlerManager::handle() {
    const Controls::KeyInput key = controls->getKey();

    active->handle(key);
}

void HandlerManager::render() {
    active->render();
}

void HandlerManager::setGame() {
    if (dynamic_cast<GameHandler*>(active)) {
        return;
    }

    active = game;
}

void HandlerManager::setMenu() {
    if (dynamic_cast<MenuHandler*>(active)) {
        return;
    }

    active = menu;
}