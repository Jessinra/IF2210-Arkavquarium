#ifndef SIPUT_H
#define SIPUT_H

#include "Pet.h"
using namespace std;

class Siput : public Pet {
  public:
    Siput();
    ~Siput();

    void take_coin();

  private:
    int distance_to_coin;
};

#endif
