
#include "Screen.h"
#include "SDLManager.h"
#include <cmath>
#include <iostream>
typedef struct {
    unsigned int x, y;
}Point;

template<typename T>
void SwitchVar(T* a, T* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void DrawLine(Point p1, Point p2, Pixel colour, Screen* screen) {
    int yi = 1;
    int xi = 1;

    int dx = static_cast<int>(p2.x) - static_cast<int>(p1.x);
    int dy = static_cast<int>(p2.y) - static_cast<int>(p1.y);
    //If x is increasing at a faster rate at y:
    if(abs(dx) > abs(dy)) {
        //For the function to work properly, we need to make sure p1.x is smaller than p2.x
        if(p2.x < p1.x) {
            SwitchVar(&p1.x, &p2.x);
            SwitchVar(&p1.y, &p2.y);
        }
        //If y is decreasing instead of increasing, go one pixel below instead of above
        if(dy < 0) {
            dy *= -1;
            yi = -1;
        }
        int d = 2*dy - dx;

        for(int i = 0; i < dx; i++) {
            screen->SetPixel(p1.x + i, p1.y, colour);
            if(d > 0) {
                p1.y += yi;
                d -= 2*dx;
            }
            d += 2*dy;
        }
    }
    //In this case switch x with y
    else {
        if(p2.y < p1.y) {
            SwitchVar(&p1.x, &p2.x);
            SwitchVar(&p1.y, &p2.y);
        }
        if(dx < 0) {
            dx *= -1;
            xi = -1;
        }
        int d = 2*dx - dy;

        for(int i = 0; i < dy; i++) {
            screen->SetPixel(p1.x, p1.y + i, colour);
            if(d > 0) {
                p1.x += xi;
                d -= 2*dy;
            }
            d += 2*dx;
        }
    }
}

int main(int argc, char* argv[]) {
    auto screen = Screen(1000, 1000);
    DrawLine({300,5}, {120,350},{255,0,0}, &screen);
    DrawLine({20,55}, {120,350},{255,0,0}, &screen);
    DrawLine({20,55}, {300,5},{255,0,0}, &screen);
    screen.SetPixel(300, 5, {0,255,0});
    screen.SetPixel(20, 55, {0,255,0});
    screen.SetPixel(120, 350, {0,255,0});
    screen.RenderFrame();
    Screen::Delay(20000);
    return 0;
}
