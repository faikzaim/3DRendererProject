
#include "Screen.h"

Screen::Screen(int width, int height) {
    this->w = width;
    this->h = height;

    window = nullptr;

    // Initialising a display
    window = SDL_CreateWindow("Window",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if(!window) {
        printf("The window could not be created: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    //Getting the surface of the window which holds all the raw pixel data.
    surf = SDL_GetWindowSurface(window);
    if(!surf) {
        printf("The surface could not be created: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
    //This clears the whole window, giving us a blank surface.
    SDL_FillRect(surf, nullptr, 0xFFFFFF);
    SDL_UpdateWindowSurface(window);
}
Screen::~Screen() {
    //Frees all the memory allocated for the window and the surface
    SDL_DestroyWindow(window);
    printf("Freed the memory.\n");
}
void Screen::SetPixel(unsigned int x, unsigned int y, Pixel pixel) const {
    uint32_t *pixels = (uint32_t*)surf->pixels;
    //Accessing the correct memory location for the pixel we want to manipulate.
    pixels[x + (y * w)] = (pixel.r<<16)|(pixel.g<<8)|(pixel.b);
}
Pixel Screen::GetPixel(unsigned int x, unsigned int y) const {
    Pixel pixelResult;
    uint32_t *pixels = (uint32_t*) surf->pixels;
    //Getting the pixel data for the desired (x,y) coordinate
    uint32_t result = pixels[x + (y * surf->w)];
    pixelResult.r = result>>16;
    pixelResult.g = (result>>8)&0xFF;
    pixelResult.b = result&0xFF;
    return pixelResult;
}
void Screen::RenderFrame() const {
    SDL_UpdateWindowSurface(window);
}

void Screen::ClearFrame() const {
    SDL_FillRect(surf, nullptr, 4294967295);
    SDL_UpdateWindowSurface(window);
}
void Screen::Delay(int ms) {
    SDL_Delay(ms);
}





