#ifndef FISH_H
#define FISH_H

#include "Object.h"
#include "Food.h"
#include "Coin.h"
using namespace std;

class Fish : public Object {
  public:
  	//ctor
    Fish();
    //dtor
    ~Fish();
    //cctor
    Fish(const Fish &ikan);
    //operator assignment
    Fish& operator=(const Fish& ikan);

    void draw();
    void remove();

    virtual void move() = 0;
    virtual void produce_coin() = 0;
    virtual void eat() = 0;
    virtual bool isFull() = 0;

  protected:
    long price;
    long coin_produced;
    int hunger;
    int speed;
};

#endif
