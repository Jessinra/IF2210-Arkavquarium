#include "Pet.h"
#include "Lib/oop.hpp"
#include <iostream>

#include "Constant.h"

using namespace std;

Pet::pet_count = 0;

Pet::Pet() {

	Pet::pet_count++;
  	pet_id = Pet::pet_count;

}

Pet::~Pet() {}

int Pet::get_id() {
  return pet_id;
}

void Pet::draw() {}

void Pet::move() {}
