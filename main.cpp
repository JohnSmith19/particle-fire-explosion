#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.h"

using namespace std;

int main(int argc, char* argv[]) {
    Screen screen;

    if(screen.init() == false) {
        cout << "Error initialising SDL." << endl;
    }

    while(true) {
        // Update particles
        // Draw particles
        int elapsed = SDL_GetTicks();
        unsigned char green = (unsigned  char)((1 + sin(elapsed * 0.001)) * 128);
        unsigned char red = (unsigned  char)((1 + sin(elapsed * 0.002)) * 128);
        unsigned char blue = (unsigned  char)((1 + sin(elapsed * 0.003)) * 128);

        for(int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }

        // Draw the screen
        screen.update();

        // Check for messages/events
        if(screen.processEvents() == false) {
            break;
        }
    }

    screen.close();
    return 0;
}