#ifndef Game_H
#define Game_H

#include <iostream>
#include <SDL.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

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

    GameObject m_go;
    Player m_player;
};

#endif