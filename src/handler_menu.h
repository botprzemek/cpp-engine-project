#ifndef HANDLER_MENU_H
#define HANDLER_MENU_H

#include "handler.h"

class MenuHandler : public Handler {
public:
    MenuHandler(bool isActive = false);

    enum Element {
        START,
        OPTIONS,
        QUIT,
    };
    
    void handle(Controls::KeyInput key);
    void render();
    void move(int amount);
    void confirm();
private:
    static map<Element, string> MENU_ELEMENTS;
    Element hovered;
    Element selected;
};

#endif // HANDLER_MENU_H