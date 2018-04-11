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
    cout << "id " << c->get_id() << endl;
    cout << "val " << c->get_value() << endl;
    cout << "speed " << c->get_speed() << endl;

    Coin a = *c;
    cout << "id " << a.get_id() << endl;
    cout << "val " << a.get_value() << endl;
    cout << "speed " << a.get_speed() << endl;
    a.set_id(10);
    a.set_value(90);
    a.set_speed(200);
    a.set_x(100);
    a.set_y(50);
    cout << "id " << a.get_id() << endl;
    cout << "val " << a.get_value() << endl;
    cout << "speed " << a.get_speed() << endl;
    
    if (c == c) {
        cout << "true" << endl;
    }

    if (c != c) {
        cout << "blabla" << endl;
    }

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
        a.move(sec_since_last);
        clear_screen();
        a.draw();
        c->draw();
        update_screen();
        
    }

    close();
}