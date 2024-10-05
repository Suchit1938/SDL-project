#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<iostream>
using namespace std;

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event e;
    SDL_Init(SDL_INIT_EVERYTHING);
    bool running = true;
    SDL_Rect r{20, 30, 250, 250};

    SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer);
    
}
