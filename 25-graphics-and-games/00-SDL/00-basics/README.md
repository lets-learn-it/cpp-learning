# SDL2 Basics

## Building

```sh
g++ 00_disply_image.cpp -lSDL2 -lSDL2_image
```

## SDL modules

While initializing SDL, you can specify different modules using below flags.

- `SDL_INIT_TIMER`: Timer subsystem
- `SDL_INIT_AUDIO`: audio subsystem
- `SDL_INIT_VIDEO`: video subsystem, automatically initializes the events subsystem
- `SDL_INIT_JOYSTICK`: joystick subsystem, automatically initializes the events subsystem
- `SDL_INIT_HAPTIC`: haptic (force feedback) subsystem
- `SDL_INIT_GAMECONTROLLER`: controller subsystem, automatically initializes the joystick subsystem
- `SDL_INIT_EVENTS`: events subsystem
- `SDK_INIT_EVERYTHING`: all of the above subsystems
- `SDK_INIT_NOPARACHUTE`: compatibility, this flag is ignored.

```cpp
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
  std::cout << "Error SDL2 Initialization: " << SDL_GetError();
  return 1;
}
```



## References

[SDL2 Tutorials - glusoft.com](https://glusoft.com/sdl2-tutorials/)
