#include "game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) 
{
  game = new Game();

  game->init("SDL Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_ALLOW_HIGHDPI);

  while(game->running())
  {
    game->handleEvents();
    game->update();
    game->render();
  }

  game->clean();

  return 0;
}