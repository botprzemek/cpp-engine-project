#include "handler.h"

#include "engine.h"

#include <iostream>

Handler::Handler() {}

Handler::~Handler() {}

void Handler::handle(Controls::KEY_INPUT key) {}

void MenuHandler::handle(Controls::KEY_INPUT key) {
    switch (key) {
        case Controls::UP:
            printf("MENU:UP\n");
            break;
        case Controls::DOWN:
            printf("MENU:DOWN\n");
            break;
        case Controls::LEFT:
            printf("MENU:LEFT\n");
            break;
        case Controls::RIGHT:
            printf("MENU:RIGHT\n");
            break;
        case Controls::CONFIRM:
            printf("MENU:CONFIRM\n");
            break;
        case Controls::UNKNOWN:
        default:
            break;
    }
}

void GameHandler::handle(Controls::KEY_INPUT key) {
    switch (key) {
        case Controls::UP:
            printf("GAME:UP\n");
            break;
        case Controls::DOWN:
            printf("GAME:DOWN\n");
            break;
        case Controls::LEFT:
            printf("GAME:LEFT\n");
            break;
        case Controls::RIGHT:
            printf("GAME:RIGHT\n");
            break;
        case Controls::CONFIRM:
            printf("GAME:CONFIRM\n");
            break;
        case Controls::UNKNOWN:
        default:
            break;
    }
}

void Handler::render() {}

void MenuHandler::render() {}

void GameHandler::render() {}

HandlerManager::HandlerManager()
    : controls(new Controls()),
    activeHandler(new MenuHandler()) {}

HandlerManager::~HandlerManager() {
    delete controls;
    delete activeHandler;
}

void HandlerManager::handle() {
    const Controls::KEY_INPUT key = controls->getKey();

    activeHandler->handle(key);
}

void HandlerManager::render() {
    activeHandler->render();
}

void HandlerManager::setMenu() {
    if (!dynamic_cast<MenuHandler*>(activeHandler)) {
        return;
    }

    activeHandler = new MenuHandler();
}

void HandlerManager::setGame() {
    if (!dynamic_cast<GameHandler*>(activeHandler)) {
        return;
    }

    activeHandler = new GameHandler();
}