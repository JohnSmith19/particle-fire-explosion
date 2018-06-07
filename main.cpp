#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char* argv[]) {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Init failed..." << endl;
        return 1;
    }

    cout << "SDL Init Successed." << endl;

    SDL_Quit();

    return 0;
}