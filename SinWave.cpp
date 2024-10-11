#define SDL_MAIN_HANDLED
#include <iostream>
#include <math.h>
#include <SDL.h>
#define PI 3.14
using namespace std;

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = SDL_CreateWindow("Sin", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
                      640, 480);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    int n = 0;
    while (n < 9)
    {
        SDL_SetRenderDrawColor(renderer, 100, 150, 175, 255);
        SDL_RenderDrawLine(renderer, (n * PI * 20), 0, (n * PI * 20), 480);
        n++;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < 640; i++)
    {
        SDL_RenderDrawPoint(renderer, i, 240);
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    for (float i = 0; i < 8 * PI; i = i + 0.001)
    {
        SDL_RenderDrawPoint(renderer, i * 20, (sin(i) * 20) + 240);
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (float i = 0; i < 8 * PI; i += 0.001)
    {
        SDL_RenderDrawPoint(renderer, i * 20, (tan(i) * 20) + 240);
    }

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
    SDL_RenderDrawLine(renderer, 0, 240 - 20, 640, 220);
    SDL_RenderDrawLine(renderer, 0, 240 + 20, 640, 260);

    SDL_RenderPresent(renderer);

    SDL_Delay(10000);
}