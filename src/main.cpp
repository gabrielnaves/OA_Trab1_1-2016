#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "gui.h"

int main(int argc, char *argv[]) {
    bool should_quit = false;
    while (!should_quit)
        should_quit = gui::RunMainMenu();
    return 0;
}
