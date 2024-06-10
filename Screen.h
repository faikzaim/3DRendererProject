
#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
typedef struct {
    unsigned char r, g, b;
}Pixel;

class Screen{
private:
    int w;
    int h;
    SDL_Window* window;
    SDL_Surface* surf;

public:
    /*This bool keeps track whether the SDL video subsystem has been initialised already.
     * If it already has been, there is no need to run SDL_Init() again.*/
    static bool isInitialised;
    //Creates a window with the specified dimensions.
    Screen(int width, int height);
    //Destroys the renderer and the window dedicated to the given screen.
    ~Screen();
    //Places the desired pixel at coordinate (x,y).
    void SetPixel(int x, int y, Pixel pixel) const;
    //Retrives the pixel at coordinate(x,y).
    Pixel GetPixel(int x, int y) const;
    /*Renders the frame, any pixels changed before this function is called is written
     * to the buffer and not displayed.*/
    void RenderFrame() const;
    //Clears the frame.
    void ClearFrame() const;
    //this is the SDL_Delay function.
    void static Delay(int ms);
};



#endif //SCREEN_H
