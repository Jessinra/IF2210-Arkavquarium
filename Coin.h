#ifndef COIN_H
#define COIN_H

#include "Object.h"
using namespace std;

class Coin : public Object {
  public:
    Coin();
    ~Coin();

    void draw();
    void remove();
    void move();

  private:
    int coin_value;
};

#endif
