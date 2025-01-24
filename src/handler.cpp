#include "handler.h"

Handler::Handler(bool isActive) {
    active = isActive;
}

Handler::~Handler() {}

void Handler::handle(Controls::KeyInput key) {}

bool Handler::isActive() {
    return active;
}

void Handler::render() {}