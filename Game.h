#ifndef Game_H
#define Game_H

#include <iostream>
#include <SDL.h>
#include "TextureManager.h"

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

    int m_currentFrame;

    bool m_bRunning = false;
};

#endif