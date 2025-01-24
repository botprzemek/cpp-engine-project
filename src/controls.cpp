#include "controls.h"

map<string, Controls::KeyInput> Controls::KEY_MAPPING;

Controls::Controls() {
    KEY_MAPPING["w"] = UP;
    KEY_MAPPING["W"] = UP;
    KEY_MAPPING["\033[A"] = UP;
    KEY_MAPPING["s"] = DOWN;
    KEY_MAPPING["S"] = DOWN;
    KEY_MAPPING["\033[B"] = DOWN;
    KEY_MAPPING["a"] = LEFT;
    KEY_MAPPING["A"] = LEFT;
    KEY_MAPPING["\033[D"] = LEFT;
    KEY_MAPPING["d"] = RIGHT;
    KEY_MAPPING["D"] = RIGHT;
    KEY_MAPPING["\033[C"] = RIGHT;
    KEY_MAPPING[" "] = CONFIRM;
    KEY_MAPPING["\n"] = CONFIRM;
    KEY_MAPPING["\r"] = CONFIRM;
}

Controls::~Controls() {}

string Controls::getInput() {
#ifdef _WIN32
    if (!_kbhit()) {
        return "";
    }

    const int input = _getch();

    if (input != 224) {
        return string(1, input);
    }

    const int extra = _getch();

    switch(extra) {
        case 72:
            return "W";
        case 80:
            return "S";
        case 75:
            return "A";
        case 77:
            return "D";
        default:
            return "";
    }

#else
    struct termios _terminal;
    struct termios terminal;

    tcgetattr(STDIN_FILENO, &_terminal);

    terminal = _terminal;
    terminal.c_lflag &= ~ICANON;
    terminal.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);

    string input;
    input += getchar();

    if (input[0] == '\033') {
        input += getchar();
        input += getchar();
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &_terminal);
    return input;
#endif
    return "";
}

Controls::KeyInput Controls::getKey() {
    const string input = getInput();

    if (input == "") {
        return UNKNOWN;
    }

    map<string, KeyInput>::iterator mapping = KEY_MAPPING.find(input);

    if (mapping == KEY_MAPPING.end()) {
        return UNKNOWN;
    }

    return mapping->second;
}