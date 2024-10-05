#include<stdio.h>
#include <inc/SDL.h>

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* render = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640*4, 480*4, 0, &window, &render);
    SDL_RenderSetScale(render, 4, 4);

    SDL_SetRenderDrawColo(render, 0, 0, 0, 255);
    SDL_RenderClear(render);

    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderDrawPoint(render, 640/2, 480/2);

    SDL_RenderPresent(render);
    SDL_Delay(1000);

    return 0;
}