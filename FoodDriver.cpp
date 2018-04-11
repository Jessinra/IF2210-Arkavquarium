#include "Aquarium.h"
#include "Lib/oop.hpp"
#include <unistd.h>

#include <iostream>
using namespace std;

int main(int argc, char* args[]) {

    /************ initialize section *********/

    // initialize window 
    init();

    bool running = true;

    // starting time 
    double prevtime = time_since_start();

    LinkedList<Food> list_food;

    // create coin
    for (int i = 0; i < SCREEN_WIDTH/50; i++){
        Food *f = new Food(i * 50);
        list_food.add(*f);
    }

    while(running){

        handle_input();
        if (quit_pressed()) {
            running = false;
        }
        for (auto key : get_tapped_keys()) {
            if (key == SDLK_x) {

                running = false;
                break;
            }
        }

        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;
        
        clear_screen();

        for (int i = 1; i <= list_food.getNBelmt(); i++){

            Food &current_food = list_food.get(i);

            // remove food that touch the bottom
            if (current_food.get_y() >= SCREEN_BOTTOM){
                list_food.remove(current_food);
                i--;
            }  

            // move food
            current_food.move(sec_since_last);

            // draw

            current_food.draw();

        }

        
        update_screen();
    }
    close();
}