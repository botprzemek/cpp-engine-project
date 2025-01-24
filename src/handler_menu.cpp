#include "engine.h"
#include "handler_menu.h"

#include <iostream>

map<MenuHandler::Element, string> MenuHandler::MENU_ELEMENTS;

MenuHandler::MenuHandler(bool isActive)
    : Handler(isActive) {
    MENU_ELEMENTS[START] = "Start";
    MENU_ELEMENTS[OPTIONS] = "Options";
    MENU_ELEMENTS[QUIT] = "Quit";
}

void MenuHandler::handle(Controls::KeyInput key) {
    switch (key) {
        case Controls::UP:
            move(-1);
            break;
        case Controls::DOWN:
            move(1);
            break;
        case Controls::CONFIRM:
            confirm();
            break;
        default:
            break;
    }
}

void MenuHandler::render() {
    cout << string(200, '\n') << endl;

    cout << "MENU (Select one > and confirm twice +)" << endl;

    for (size_t i = 0; i < MENU_ELEMENTS.size(); i++) {
        const Element element = static_cast<Element>(i);

        if (i == selected) {
            cout << " + " << MENU_ELEMENTS.at(element) << endl;
            continue;
        }

        if (i == hovered) {
            cout << " > " << MENU_ELEMENTS.at(element) << endl;
            continue;
        }
        
        cout << "   " << MENU_ELEMENTS.at(element) << endl;
    }
}

void MenuHandler::move(int amount) {
    const int temp = hovered + amount;

    if (temp < 0 || temp >= MENU_ELEMENTS.size()) {
        return;
    }

    hovered = static_cast<Element>(temp % MENU_ELEMENTS.size());
    
    render();
}

void MenuHandler::confirm() {
    if (selected != hovered) {
        selected = hovered;
    
        render();

        return;
    }

    switch(selected) {
        case START:
            Engine::get()->getHandlerManager()->setGame();
            break;
        case OPTIONS:
            break;
        case QUIT:
            abort();
            break;
    }
}