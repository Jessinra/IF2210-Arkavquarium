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

    // create coin
    Coin *c = new Coin(SCREEN_WIDTH/2,SCREEN_TOP,50);

    /*******        main loop            *******/
    while (running) {

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
        
        c->move(sec_since_last);
        clear_screen();
        c->draw();
        update_screen();
        
    }

    close();
}