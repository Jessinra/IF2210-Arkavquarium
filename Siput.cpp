#include "LinkedList.h"
#include "Siput.h"
#include "Lib/oop.hpp"
#include <iostream>
using namespace std;

Siput::Siput() {
  distance_to_coin = 0;
}

Siput::~Siput() {}

int Siput::get_distance() {
  return distance_to_coin;
}

void Siput::set_distance(int x) {
  distance_to_coin = x;
}

void Siput::draw() {
  //manggil fitur draw bapaknya
  //pass gambar dan posisi
  int x;
  x = Moveable::get_x();
  int y;
  y = Moveable::get_y();
  draw_image("C:\Users\user\Desktop\ArkavquariumNew",x,y);
}

void Siput::move(LinkedList<Coin> C) {
  int max;
  max = C.get(1);
  for (int i=2; i<=C.getNBelmt(); i++) {
    if (max == C.get(i)) {
      max = C.get(i);
    }
  }
  int x;
  x = max.(Moveable::get_x());
  int y;
  y = max.(Moveable::get_y());
  Moveable::set_x(x+1);
  Moveable::set_y(y+1);
}

int Siput::find_coin() {
  int x;
  x = Moveable::get_x();
  int y;
  y = Moveable::get_y();
  T Coin;
  if ((x+1) and (x-1)) {
    return C.get_id();
  } else {
    return 0;
  }
}

void Siput::take_coin(LinkedList<Coin>& C) {
  if (find_coin!=0) {
    //jalanin take_coin
    add(C.get_value());
    remove();
  } else {
    //jalan ae terus
    Moveable::move();
  }
}
