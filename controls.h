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
    enum KEY_INPUT {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        CONFIRM,
        UNKNOWN,
    };

    Controls();

    KEY_INPUT getKey();
private:
    static map<string, KEY_INPUT> KEY_MAPPING;

    string getInput();
};

#endif // CONTROLS_H