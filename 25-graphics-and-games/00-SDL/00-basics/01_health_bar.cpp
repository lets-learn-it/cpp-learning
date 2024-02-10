#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

/*
 * Example taken from https://glusoft.com/sdl2-tutorials/make-health-bar-sdl/
 */

int main() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    std::cout << "Error SDL2 Initialization: " << SDL_GetError();
    return 1;
  }

  if (IMG_Init(IMG_INIT_PNG) == 0) {
    std::cout << "Error SDL2_image Initialization";
    return 2;
  }

  SDL_Window* window = SDL_CreateWindow("Health Bar", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    std::cout << "Error window creation";
    return 3;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    std::cout << "Error renderer creation";
    return 4;
  }

  SDL_Surface* healthbar_sur = IMG_Load("img/healthbar.png");
  if (healthbar_sur == NULL) {
    std::cout << "Error loading image: " << IMG_GetError();
    return 5;
  }

  SDL_Texture* healthbar_tex = SDL_CreateTextureFromSurface(renderer, healthbar_sur);
  if (healthbar_tex == NULL) {
    std::cout << "Error creating texture";
    return 6;
  }

  SDL_Rect rect{100, 100, 200, 22};

  int x = 0;  // x position of mouse

  while (true) {
    SDL_Event e;

    if (SDL_WaitEvent(&e)) {
      if (e.type == SDL_QUIT) {
        break;
      }

      if (e.type == SDL_MOUSEMOTION) {
        x = e.motion.x;
        if (x < 196) x = 196;
        if (x > 392) x = 392;
      }
    }

    SDL_Rect rect2{102, 102, (x-192), 18};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, healthbar_tex, NULL, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect2);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(healthbar_tex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();

  return 0;
}