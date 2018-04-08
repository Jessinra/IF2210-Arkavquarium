#include "Pet.h"
#include "Lib/oop.hpp"
#include <iostream>
using namespace std;

Pet::Pet() {
  pet_id = 0;
  pet_count = 0;
}

Pet::~Pet() {}

int Pet::get_id() {
  return pet_id;
}

void Pet::draw() {}

void Pet::move() {}
