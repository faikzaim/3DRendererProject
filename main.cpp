
#include "Screen.h"
#include "SDLManager.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Screen screen = Screen(800, 800);
    Screen screen2 = Screen(400,400);
    screen.SetPixel(400, 400, {0,255, 0});
    screen.SetPixel(401, 400, {0,255,0});
    screen.SetPixel(400, 401, {0,255,0});
    screen.SetPixel(401, 401, {0,255,0});
    screen.RenderFrame();
    Screen::Delay(2000);
    screen.ClearFrame();
    screen.SetPixel(400, 400, {255,0,0});
    screen.SetPixel(401, 400, {255,0,0});
    screen.SetPixel(400, 401, {255,0,0});
    screen.SetPixel(401, 401, {255,0,0});
    screen.RenderFrame();
    Pixel pixel = screen.GetPixel(400,401);
    printf("red:%d, green:%d, blue:%d\n", pixel.r, pixel.g, pixel.b);
    Screen::Delay(2000);
    return 0;
}
