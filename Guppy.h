#ifndef GUPPY_H
#define GUPPY_H

#include "Fish.h"
using namespace std;

class Guppy : public Fish {
  public:
    Guppy();
    ~Guppy();
    Guppy(const Guppy &g);
    Guppy& operator=(const Guppy& g);


    void move(); //approach food
    void produce_coin(); ////periodically
    void eat(); //eat food
    void grow();
    bool isFull();

  private:
    int level_grow;
};

#endif
