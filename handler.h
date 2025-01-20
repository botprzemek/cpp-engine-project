#ifndef HANDLER_H
#define HANDLER_H

#include "controls.h"

class Handler {
public:
    Handler();
    ~Handler();

    virtual void handle(Controls::KEY_INPUT key);
    virtual void render();
private:
    bool isActive;
};

class MenuHandler : public Handler {
public:
    void handle(Controls::KEY_INPUT key) override;
    void render() override;
};

class GameHandler : public Handler {
public:
    void handle(Controls::KEY_INPUT key) override;
    void render() override;
};

class HandlerManager {
public:
    HandlerManager();
    ~HandlerManager();

    void handle();
    void render();
    void setMenu();
    void setGame();
private:
    Handler* activeHandler;
    Controls* controls;
};

#endif // HANDLER_H
