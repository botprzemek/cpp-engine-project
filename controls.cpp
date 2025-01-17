#include "controls.h"

map<string, Controls::KEY_INPUT> Controls::KEY_MAPPING;

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
}

string Controls::getInput() {
#ifdef _WIN32
    if (_kbhit()) {
        return string(1, _getch());
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

Controls::KEY_INPUT Controls::getKey() {
    const string input = getInput();

    map<string, KEY_INPUT>::iterator mapping = KEY_MAPPING.find(input);

    if (mapping == KEY_MAPPING.end()) {
        return UNKNOWN;
    }

    return mapping->second;
}