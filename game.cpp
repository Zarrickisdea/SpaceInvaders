#include "game.h"

Game::Game()
{
  isRunning = false;
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "SDL init success\n";
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window != 0)
    {
      std::cout << "window creation success\n";
      renderer = SDL_CreateRenderer(window, -1, 0);
      if(renderer != 0)
      {
        std::cout << "renderer creation success\n";
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      }
      else
      {
        std::cout << "renderer init fail\n";
        return false;
      }
    }
    else
    {
      std::cout << "window init fail\n";
      return false;
    }
  }
  else
  {
    std::cout << "SDL init fail\n";
    return false;
  }
  std::cout << "init success\n";
  isRunning = true;
  return true;
}

void Game::render()
{
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}

void Game::clean()
{
  std::cout << "cleaning game\n";
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_QUIT:
        isRunning = false;
        break;
        
      default:
        break;
    }
  }
}

void Game::update()
{

}