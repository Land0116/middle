//[Hello SDL분리하기]
#include <SDL.h>

int main(int argc, char* args[]);
bool init(const char* title, int xpos, int ypos, int width, int hegiht, int flags);
void update();
void render();


SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false; //게임 루프를 실행 시킬 수 있게 한다.
int countColor = 1;

int main(int argc, char* args[])
{
 
   if (init("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, SDL_WINDOW_SHOWN))
   {
     g_bRunning = true;

   }
    else {
        return 1;
    }

  while(g_bRunning)
  {
    update();
    if(countColor == 10)
    {
      g_bRunning = false;
    }
    render();
  }
  SDL_Delay(5000);
  SDL_Quit();

    return 0;
}

bool init(const char* title, int xpos, int ypos, int width, int hegiht, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, hegiht, flags);

    if(g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
  }
  else { return false; }

  //SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);

  return true;
}

void update()
{
  if(countColor <= 10)
  {
    SDL_SetRenderDrawColor(g_pRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
    SDL_Delay(1000);
  }
  countColor++;
}

void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}