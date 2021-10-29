#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{ 
  SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  SDL_Surface* pTempSurface_Back = IMG_Load("Assets/BackGround.png");
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);

        if(pTempSurface != 0)
        {
          m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
          SDL_FreeSurface(pTempSurface);

          SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

          m_destinationRectangle.w = m_sourceRectangle.w;
          m_destinationRectangle.h = m_sourceRectangle.h;

          m_destinationRectangle.x = m_sourceRectangle.x = 0;
          m_destinationRectangle.y = m_sourceRectangle.y = 0;

          cout << "W : " << m_sourceRectangle.w  << " H : " << m_sourceRectangle.h << endl;
          if(pTempSurface_Back != 0)
          {
            m_pTexture_Back = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface_Back);
            SDL_FreeSurface(pTempSurface_Back);

            SDL_QueryTexture(m_pTexture_Back, NULL, NULL, &m_sourceRectangle_Back.w, &m_sourceRectangle_Back.h);

            m_destinationRectangle_Back.w = m_sourceRectangle_Back.w;
            m_destinationRectangle_Back.h = m_sourceRectangle_Back.h;

            m_destinationRectangle_Back.x = m_sourceRectangle_Back.y = 0;
            m_destinationRectangle_Back.y = m_sourceRectangle_Back.y = 0;
          }
          else { return false; }
        }
        else { return false; }
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
  if(dirt == 1)
  {
    if(m_destinationRectangle.x >= 520)
    {
      dirt = -1;
    }
    m_destinationRectangle.x++;
  }
  else if(dirt == -1)
  {
    if(m_destinationRectangle.x == 0)
    {
      dirt = 1;
    }
    m_destinationRectangle.x--;
  }
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture_Back, &m_sourceRectangle_Back, &m_destinationRectangle_Back);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
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