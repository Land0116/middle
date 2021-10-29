#ifndef Game_H
#define Game_H

#include <iostream>
#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"

using namespace std;

class Game
{
  public : 
    static Game* Instance()
    {
      if(s_pInstance == 0)
      {
        s_pInstance = new Game();
        return s_pInstance;
      }
      return s_pInstance;
    }

    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

  private :
    Game() {}
    static Game* s_pInstance;

    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;

    int m_currentFrame;

    bool m_bRunning = false;
    
    vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif