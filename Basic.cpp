
#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
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

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = false;
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    cout << "Right Key is pressed" << endl;
                    r.x += 10;
                    break;
                }
            }
            else if (e.type == SDL_KEYUP)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    cout << "The key is released" << endl;
                    break;
                }
            }
            else if(e.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&r.x, &r.y);
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }
}