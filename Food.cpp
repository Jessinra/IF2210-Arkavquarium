#include "Food.h"
#include "Lib/oop.hpp"
#include <iostream>
#include <random>
using namespace std;

int Food::food_count = 0;

Food::Food() {
    set_y(SCREEN_TOP);
    int a = rand() % SCREEN_WIDTH + 1;
    set_x((double) a);
    Food::food_count++;
    set_id(Food::food_count);
    set_speed(FOOD_MOVEMENT_SPD);
}

Food::Food(double x) {
    set_y(SCREEN_TOP);
    set_x(x);
    Food::food_count++;
    set_id(Food::food_count);
    set_speed(FOOD_MOVEMENT_SPD);
}


int Food::get_id() {
    return food_id;
}

void Food::set_id(int id){
    food_id = id;
}

// int Food::get_type(){

//     return food_type;
// }

// int Food::get_value() {
    
//     return food_value;
// }

// void Food::set_value(int x) {
//     food_value = x;
// }

int Food::get_speed(){

    return food_speed;
}

void Food::set_speed(int spd){

    food_speed = spd;
}

void Food::draw() {
    // draw food on screen

    draw_image(FILE_food,get_x(),get_y());
}

void Food::move(double sec_since_last) {
    
    // if food is not on bottom yet, 
    if (get_y() <= SCREEN_BOTTOM) {
        cout << "Food move" << get_x() << "," << get_y() << endl;
        // move coin towards bottom of the tank
        set_y(get_y() + (get_speed() * sec_since_last));
        cout << "Food move" << get_x() << "," << get_y() << endl;
    }
}


bool Food::operator==(Food& s) {
    return get_id() == s.get_id();
}

bool Food::operator!=(Food& s) {
    return get_id() != s.get_id();
}