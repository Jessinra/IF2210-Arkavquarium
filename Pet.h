#ifndef PET_H
#define PET_H

#include "Object.h"
using namespace std;

class Pet : public Object {
  public:
    Pet();
    ~Pet();

    void draw();
    void remove();
    void move();

    virtual void take_coin() = 0;
};

#endif
