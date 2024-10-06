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
                const Uint8 *state = SDL_GetKeyboardState(NULL);
                if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP])
                {
                    r.x += 10;
                    r.y += 10;
                }
                switch (e.key.keysym.sym) // accessing only one key at one time
                {
                case SDLK_RIGHT: // Right key
                    cout << "Right Key is pressed" << endl;
                    r.x += 10; // x direction ke coordinate change ho rahi hh
                    break;

                case SDLK_LEFT:
                    cout << "Left Key  is Pressed" << endl;
                    r.y += 10;
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

                case SDLK_LEFT:
                    cout << "The right key is released" << endl;
                    break;
                }
            }
            else if (e.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&r.x, &r.y);
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // White Color ke liye
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Balck Color ke liye
        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }
}
