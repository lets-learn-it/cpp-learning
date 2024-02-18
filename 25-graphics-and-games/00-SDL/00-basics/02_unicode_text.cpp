#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>

int main() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    std::cout << "Error SDL2 Initialization: " << SDL_GetError();
    return 1;
  }

  if (TTF_Init() != 0) {
    std::cout << "Error TTF_Init Initialization";
    return 2;
  }

  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  if (SDL_CreateWindowAndRenderer(400, 300, 0, &window, &renderer) != 0) {
    std::cout << "Error SDL_CreateWindowAndRenderer: " << SDL_GetError();
    return 3;
  }

  std::string text = std::string("यदा यदा हि धर्मस्य ग्लानिर्भवति भारत।\nअभ्युत्थानमधर्मस्य तदात्मानं सृजाम्यहम्।।");

  TTF_Font *yatra = TTF_OpenFont("fonts/YatraOne-Regular.ttf", 24);

  SDL_Surface *surface = TTF_RenderUTF8_Blended_Wrapped(yatra, text.c_str(), SDL_Color{255, 255, 255, 255}, 300);
  if (surface == NULL) {
    std::cout << "Error creating surface";
    return 4;
  }

  SDL_Rect rect{50, 100, surface->w, surface->h};

  SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);
  if (tex == NULL) {
    std::cout << "Error creating texture";
    return 5;
  }

  SDL_FreeSurface(surface);

  while (true) {
    SDL_Event e;

    if (SDL_WaitEvent(&e)) {
      if (e.type == SDL_QUIT) {
        break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tex, NULL, &rect);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(yatra);
  TTF_Quit();
  SDL_Quit();

  return 0;
}