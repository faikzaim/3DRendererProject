
#ifndef SDLMANAGER_H
#define SDLMANAGER_H
#include <SDL.h>


class SDLManager {
public:
    SDLManager(const SDLManager&) = delete;

    static SDLManager& GetSDLManager();
private:
    SDLManager();
    ~SDLManager();
    static SDLManager s_Instance;

};



#endif //SDLMANAGER_H
