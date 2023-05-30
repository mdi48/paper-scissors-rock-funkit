#include "game.h"

void compare (void) {
    if (myChoice == theirChoice) {
        result = 'T';
    } else if (myChoice == 'P') {
        if (theirChoice == 'S') {
            result = 'L';
        }
        result = 'W';
    } else if (myChoice == 'S') {
        if (theirChoice == 'R') {
            result = 'L';
        }
        result = 'W';
    } else if (myChoice == 'R') {
        if (theirChoice == 'P') {
            result = 'L';
        }
        result = 'W';
    }
    display_character (result);
}