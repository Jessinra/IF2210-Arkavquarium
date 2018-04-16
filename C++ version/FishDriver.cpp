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

    LinkedList<Piranha> list_piranha;
    LinkedList<Guppy> list_guppy;
    LinkedList<Food> list_food;

    // create coin
    for (int i = 0; i < 20; i++){
        Piranha *f = new Piranha();
        list_piranha.add(*f);

        Guppy *g = new Guppy();
        list_guppy.add(*g);
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
        
        for (int i = 1; i <= list_piranha.getNBelmt(); i++){

            Piranha &current_piranha = list_piranha.get(i);

            if (current_piranha.get_hunger() < 0) {
                    
                list_piranha.remove(current_piranha);
                i--;
            }
            else{
                // move piranha
                current_piranha.move(sec_since_last, list_guppy);

                // ngurangin hunger
                current_piranha.makeHungry();

                // draw
                current_piranha.draw();
            }

        }

        for (int i = 1; i <= list_guppy.getNBelmt(); i++) {

            Guppy &current_guppy = list_guppy.get(i);

            // cek mati 
            if (current_guppy.get_hunger() < 0) {

                list_guppy.remove(current_guppy);
                i--;

            } else {
                
                current_guppy.move(sec_since_last, list_food);
                
                current_guppy.makeHungry();

                current_guppy.draw();
                
            }
        }


        update_screen();
    }
    close();
}