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
                if ((state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_UP]) || (state[SDL_SCANCODE_RCTRL] && state[SDL_SCANCODE_UP]))
                {
                    cout << "CTRL + UP Key  is Pressed" << endl;
                    r.x -= 50;
                    r.y -= 50;
                    cout << r.x << '\t' << r.y << endl
                         << endl;
                }
                else if ((state[SDL_SCANCODE_LCTRL] && state[SDL_SCANCODE_DOWN]) || (state[SDL_SCANCODE_RCTRL] && state[SDL_SCANCODE_DOWN]))
                {
                    cout << "CTRL + DOWN Key  is Pressed" << endl;
                    r.x += 50;
                    r.y += 50;
                    cout << r.x << '\t' << r.y << endl
                         << endl;
                }
                else
                {
                    switch (e.key.keysym.sym) // accessing only one key at one time
                    {
                    case SDLK_RIGHT: // Right key
                        cout << "Right Key is pressed" << endl;
                        cout << r.x << '\t' << r.y << endl
                             << endl;
                        r.x += 10; // x direction ke coordinate change ho rahi hh
                        break;

                    case SDLK_LEFT:
                        cout << "Left Key  is Pressed" << endl;
                        cout << r.x << '\t' << r.y << endl
                             << endl;
                        r.x -= 10;
                        break;

                    case SDLK_UP:
                        r.y -= 10;
                        cout << "UP Key  is Pressed" << endl;
                        cout << r.x << '\t' << r.y << endl
                             << endl;
                        break;

                    case SDLK_DOWN:
                        r.y += 10;
                        cout << "Down Key  is Pressed" << endl;
                        cout << r.x << '\t' << r.y << endl
                             << endl;
                        break;
                    }
                }
            }
            else if (e.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&r.x, &r.y);
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                r.h -= 10;
                r.w -= 10;
                cout << "The mouse key is preesed " << endl
                     << "height and width are " << endl
                     << r.h << "  " << r.w << endl
                     << endl;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // White Color ke liye
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Balck Color ke liye
        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    return 0;
}