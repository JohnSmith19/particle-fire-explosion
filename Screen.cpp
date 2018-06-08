//
// Created by jerom on 2018-06-08 0008.
//

#include <cstdio>
#include "Screen.h"

Screen::Screen() :
        m_window(NULL),
        m_renderer(NULL),
        m_texture(NULL),
        m_buffer(NULL) {
}

bool Screen::init() {

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL Init failed...");
        return false;
    }

    // https://wiki.libsdl.org/SDL_CreateWindow
    m_window = SDL_CreateWindow("Particle Fire Explosion",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(m_window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    // https://wiki.libsdl.org/SDL_CreateRenderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(m_renderer == NULL) {
        printf("Could not create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    // https://wiki.libsdl.org/SDL_CreateTexture
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                                             SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if(m_texture == NULL) {
        printf("Could not create texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    // screen buffer
    Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        buffer[i] = 0x00FFFFFF;
    }

    SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

    return true;
}

bool Screen::processEvents() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Screen::close() {
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}