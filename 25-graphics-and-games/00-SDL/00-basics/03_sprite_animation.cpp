#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum class Direction { LEFT, RIGHT, STOP };
enum class JumpDirection { NONE, UP, DOWN };

SDL_Texture* CreateTexture(SDL_Renderer* renderer, std::string path) {
  SDL_Surface* sur = IMG_Load(path.c_str());
  if (sur == NULL) {
    std::cout << "Error loading image: " << IMG_GetError();
    exit(5);
  }

  // What is SDL_Texture?
  // Array of pixel stored in VRAM encoded in a driver specific format.
  SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, sur);
  if (tex == NULL) {
    std::cout << "Error creating texture";
    exit(6);
  }
  SDL_FreeSurface(sur);

  return tex;
}

int main() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    std::cout << "Error SDL2 Initialization: " << SDL_GetError();
    return 1;
  }

  if (IMG_Init(IMG_INIT_PNG) == 0) {
    std::cout << "Error SDL2_image Initialization";
    return 2;
  }

  SDL_Window* window = SDL_CreateWindow("First Program", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_OPENGL);
  if (window == NULL) {
    std::cout << "Error window creation";
    return 3;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    std::cout << "Error renderer creation";
    return 4;
  }

  SDL_Texture* left_0 = CreateTexture(renderer, "sprite/left-0.png");
  SDL_Texture* left_1 = CreateTexture(renderer, "sprite/left-1.png");
  SDL_Texture* left_2 = CreateTexture(renderer, "sprite/left-2.png");
  SDL_Texture* left_3 = CreateTexture(renderer, "sprite/left-3.png");

  SDL_Texture* left_moves[] = {left_0, left_1, left_2, left_3};

  SDL_Texture* right_0 = CreateTexture(renderer, "sprite/right-0.png");
  SDL_Texture* right_1 = CreateTexture(renderer, "sprite/right-1.png");
  SDL_Texture* right_2 = CreateTexture(renderer, "sprite/right-2.png");
  SDL_Texture* right_3 = CreateTexture(renderer, "sprite/right-3.png");

  SDL_Texture* right_moves[] = {right_0, right_1, right_2, right_3};

  Direction direction = Direction::STOP;
  JumpDirection jumpDirection = JumpDirection::NONE;
  int jump = 0, ground = 300;
  SDL_Rect rect{300, 300, 95, 200};
  int left = 0, right = 0;
  SDL_Event e;

  while(true) {
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        break;
      }

      if (e.type = SDL_KEYDOWN) {
        switch (e.key.keysym.sym)
        {
        case SDLK_RIGHT:
          direction = Direction::RIGHT;
          break;

        case SDLK_LEFT:
          direction = Direction::LEFT;
          break;

        case SDLK_SPACE:
          direction = Direction::STOP;
          break;

        case SDLK_UP:
          if (jumpDirection == JumpDirection::NONE) jumpDirection = JumpDirection::UP;
          break;

        default:
          break;
        }
      }
    }

    SDL_RenderClear(renderer);
    if (jumpDirection != JumpDirection::NONE) {
      if (jumpDirection == JumpDirection::UP) jump += 1;
      if (jumpDirection == JumpDirection::DOWN) jump -= 1;
      if (jump == 100) jumpDirection = JumpDirection::DOWN;
      if (jump == 0) jumpDirection = JumpDirection::NONE;
    }
    if (direction == Direction::LEFT) {
      SDL_RenderCopy(renderer, left_moves[left], NULL, &rect);
      left = (left + 1) % 4;
      right = 0;
      rect.x -= 1;
    } else if (direction == Direction::RIGHT) {
      SDL_RenderCopy(renderer, right_moves[right], NULL, &rect);
      right = (right + 1) % 4;
      left = 0;
      rect.x += 1;
    } else {
      SDL_RenderCopy(renderer, right_0, NULL, &rect);
      right = left = 0;
    }
    rect.y = - jump + ground;
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(left_0);
  SDL_DestroyTexture(left_1);
  SDL_DestroyTexture(left_2);
  SDL_DestroyTexture(left_3);
  SDL_DestroyTexture(right_0);
  SDL_DestroyTexture(right_1);
  SDL_DestroyTexture(right_2);
  SDL_DestroyTexture(right_3);

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  IMG_Quit();
  SDL_Quit();

  return 0;
}