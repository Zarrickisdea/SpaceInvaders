#pragma once

#include <SDL2/SDL.h>
#include <iostream>

class Game
{
  public:
    Game();
    ~Game();

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return isRunning; }

  private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool isRunning;
};