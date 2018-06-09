//
// Created by jerom on 2018-06-08 0008.
//

#ifndef PARTICLE_SCREEN_H
#define PARTICLE_SCREEN_H

#include <SDL2/SDL.h>

class Screen {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Uint32* m_buffer;
public:
    Screen();
    bool init();
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool processEvents();
    void close();
};

#endif //PARTICLE_SCREEN_H
