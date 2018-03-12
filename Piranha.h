#ifndef PIRANHA_H
#define PIRANHA_H

#include "Fish.h"
using namespace std;

class Piranha : public Fish {
  public:
    Piranha();
    ~Piranha();
    Piranha(const Piranha &p);
    Piranha& operator=(const Piranha& p);

    void move(); //approach guppy
    void produce_coin(); //produce after eat
    void eat(); //eat guppy
    bool isFull();
};

#endif