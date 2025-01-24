#ifndef CONTROLS_H
#define CONTROLS_H

#include <map>
#include <string>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

using namespace std;

class Controls {
public:
    Controls();
    ~Controls();

    enum KeyInput {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        CONFIRM,
        UNKNOWN,
    };

    KeyInput getKey();
private:
    static map<string, KeyInput> KEY_MAPPING;

    string getInput();
};

#endif // CONTROLS_H