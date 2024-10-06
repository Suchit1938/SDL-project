#define SDL_MAIN_HANDLED
#include <SDL.h>

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    auto window = SDL_CreateWindow("Texture",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   640, 480, 0);

    auto renderer = SDL_CreateRenderer(window, -1, 0);

    // Create Textures  Texutres is 2 dimension stuctures 
        // red_textures indicates the Colour of the texture 
    auto red_texture = SDL_CreateTexture(                               // TargetAccess is for render target 
        renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,   // PIXELFORMAT is default pixel of the SDL texture 
        1000, 1000);  // Height and Width for the textures are 1000, 1000

    auto blue_texture = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
        1000, 1000);


    // Draw to textures 
    // for red textures
    SDL_SetRenderTarget(renderer, red_texture);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Blue Textures 
    SDL_SetRenderTarget(renderer, blue_texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderTarget(renderer, nullptr); // by passing nullptr as textures means it default back to rendering to window

    // showing Texture

    SDL_RenderCopy(renderer, red_texture, nullptr, nullptr);  // nullptr means srcrect and dstrect
                                                            // first nullptr take the entire texture 
                                                            // Second nullptr means render to the whole thing 
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    SDL_RenderCopy(renderer, blue_texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
}