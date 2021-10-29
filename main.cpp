//[추상 Class]
#include "Game.h"

int main(int argc, char* args[])
{
  if(TheGame::Instance()->init("Game Class", 100, 100, 640, 480, 0))
  {
    while(TheGame::Instance()->running())
    {
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      SDL_Delay(10);
    }
  }
  else
  {
    cout << "game init failure" << SDL_GetError() << endl;
    return -1;
  }
  
  TheGame::Instance()->clean();
  return 0;
}