
#include "SDLManager.h"

#include <cstdio>

SDLManager& SDLManager::GetSDLManager() {
    return s_Instance;
}
SDLManager::SDLManager() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    printf("Everything initialised correctly!\n");
}
SDLManager::~SDLManager() {
    printf("Closing out of SDL.\n");
    SDL_Quit();
}
SDLManager SDLManager::s_Instance;
