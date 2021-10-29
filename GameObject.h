#ifndef GameObject_H
#define GameObject_H

#include "LoaderParams.h"

using namespace std;

class GameObject
{
  public :
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() {}
    virtual ~GameObject() {}

  protected:
    GameObject(const LoaderParams* pParams) {}
};

#endif