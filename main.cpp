
#include "Screen.h"
#include "Vector3.h"
#include "Matrix.h"
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
    auto mat1 = Matrix(3,3);
    auto mat2 = Matrix(3,3);
    mat1(0,0) = 1, mat1(0,1) = 2, mat1(0,2) = 3,
    mat1(1,0) = 4; mat1(1,1) = 5, mat1(1,2) = 6,
    mat1(2,0) = 7; mat1(2,1) = 8, mat1(2,2) = 9;

    mat2(0,0) = 5, mat2(0,1) = 3, mat2(0,1) = 7,
    mat2(1,0) = 9; mat2(1,1) = 1, mat2(1,2) = 2,
    mat2(2,0) = 7; mat2(2,1) = 1, mat2(2,2) = 1;

    Matrix matres = mat1 * mat2;

    printf("[%f %f %f \n %f %f %f \n %f %f %f]\n",
        matres(0,0), matres(0,1), matres(0,2),
        matres(1,0), matres(1,1), matres(1,2),
        matres(2,0), matres(2,1), matres(2,2));

    auto screen = Screen(500, 500);
    DrawLine({300,5}, {120,350},{255,0,0}, &screen);
    DrawLine({20,55}, {120,350},{255,0,0}, &screen);
    DrawLine({20,55}, {300,5},{255,0,0}, &screen);
    screen.SetPixel(300, 5, {0,255,0});
    screen.SetPixel(20, 55, {0,255,0});
    screen.SetPixel(120, 350, {0,255,0});
    screen.RenderFrame();
    Screen::Delay(2000);
    return 0;
}
