#include "Food.h"
#include "Lib/oop.hpp"
#include <iostream>
using namespace std;

Food::Food() {
  food_id = 0;
  food_type = 0;
  food_value = 0;
}

Food::~Food() {}

int Food::get_id() {
  return food_id;
}

int Food::get_value() {
  return food_value;
}

int Food::get_type() {
  return food_type;
}

int Food::get_value() {
  return food_value;
}

void Food::set_value(int x) {
  food_value = x;
}

void Food::draw() {
  x = Moveable::get_x();
  y = Moveable::get_y();
  draw_image("C:\Users\user\Desktop\ArkavquariumNew",x,y);
}

void Food::remove() {
  
}

void Food::move() {
  int x;
  x = Moveable::get_x();
  Moveable::set_x(x-1);
}
