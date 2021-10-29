#ifndef Game_H
#define Game_H

#include <iostream>
#include <SDL.h>
#include "SDL_image.h"

using namespace std;

class Game
{
  public : 
    Game() {}
    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

  private :
    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;

    SDL_Texture* m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;

    SDL_Texture* m_pTexture_Back;
    SDL_Rect m_sourceRectangle_Back;
    SDL_Rect m_destinationRectangle_Back;

    bool m_bRunning = false;
};

#endif