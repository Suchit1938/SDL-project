#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <cmath>
#define PI 3.14

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = SDL_CreateWindow("Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
                      640, 480);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderDrawLine(renderer, 0, 240, 640, 240);
    SDL_RenderDrawLine(renderer, 320, 0, 320, 480);

    for (float i = 0; i < 340; i = i + 0.1)
    {
        int num = pow(i, 2);
        float y = pow((1 - num), 0.5);
        SDL_RenderDrawPoint(renderer, (i + 320) * 100, (y + 240) * 100);
    }
    // for (float angle = 0; angle < 2 * PI; angle += 0.01)
    // {
    //     float x = 100 * cos(angle); // Scaling factor
    //     float y = 100 * sin(angle);
    //     SDL_RenderDrawPoint(renderer, 320 + x, 240 + y); // Centering the circle at (320, 240)
    // }

    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}