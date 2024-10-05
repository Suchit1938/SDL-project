// #define SDL_MAIN_HANDLED
// #include <SDL.h>

// int main(int argc, char *argv[])
// {
//     SDL_Window *window = NULL;
//     SDL_Renderer *renderer = NULL;

//     SDL_Init(SDL_INIT_VIDEO);
//     SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);


//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//     SDL_RenderClear(renderer);

//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

//     for (int i = 50; i < 200; i++)
//     {
//         for (int j = 50; j < 200; j++)
//         {
//             SDL_RenderDrawPoint(renderer, i, j);
//         }
//     }
//     // SDL_Rect r{50,50,250,250};
//     // SDL_RenderFillRect(renderer, &r);
//     SDL_RenderPresent(renderer);
//     SDL_Delay(10000);

//     return 0;
// }

#define SDL_MAIN_HANDLED
#include<iostream>
#include<SDL.h>
using namespace std;

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event e;
    SDL_Init(SDL_INIT_EVERYTHING);
    bool running = true;
    SDL_Rect r{50, 50, 250, 250};

    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    SDL_Delay(1000);
}