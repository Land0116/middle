#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{ 
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

        m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
        m_textureManager.load("Assets/BackGround.png", "BackGround", m_pRenderer);

      }
      else { return false; }
    }
    else { return false; }
  }
  else { return false; }

  m_bRunning = true;
  return true;
}

void Game::update()
{
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  m_textureManager.draw("BackGround", 0, 0, 640, 480, m_pRenderer);
  m_textureManager.drawFrame("animate", 0, 0, 128, 82, 0, m_currentFrame, m_pRenderer);
  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch (event.type) 
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}