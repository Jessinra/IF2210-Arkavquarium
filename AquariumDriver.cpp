#include "Aquarium.h"
#include "Lib/oop.hpp"
#include "Guppy.h"
#include "Piranha.h"
#include "Siput.h"
#include <unistd.h>

#include <math.h>
#include <sstream>
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {

    /************   initialize section *********/

    // initialize window 
    init();

    bool running = true;

    // create aquarium
    Aquarium aquarium;     

    /*******        main loop            *******/
    while (running) {

        handle_input();
        if (quit_pressed()) {
            running = false;
        }
        
        // Command List
        // beli guppy   : G
        // beli makanan : F
        // beli piranha : P
        // beli telor   : E
        // beli siput   : S
        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            if (key == SDLK_b) {
                Coin *c = new Coin(SCREEN_WIDTH/2,SCREEN_TOP,50);
                aquarium.get_list_coin().add(*c);
                aquarium.buy_guppy();
                aquarium.buy_food();
                aquarium.buy_piranha();
                aquarium.buy_egg();
                aquarium.buy_snail();
                
            } else if (key == SDLK_r) {
                int ct = 1;
                aquarium.get_list_coin().remove(aquarium.get_list_coin().get(ct));
                aquarium.get_list_piranha().remove(aquarium.get_list_piranha().get(ct));
                aquarium.get_list_guppy().remove(aquarium.get_list_guppy().get(ct));
                aquarium.get_list_food().remove(aquarium.get_list_food().get(ct));
                aquarium.get_list_siput().remove(aquarium.get_list_siput().get(ct));
                
            } else if (key == SDLK_x) {
                running = false;
                
            }
            
        }

        // on left mouse click
        if (get_mouse_button_down(0)) {
            int val = aquarium.click_coin(get_mouse_pos_x(),get_mouse_pos_y()); // cek coin
            if (val != 0) {
                Aquarium::money += val;
            } else {
                aquarium.buy_food(get_mouse_pos_x());       // beli makan
            }
        }
        
        cout << aquarium.get_list_coin().getNBelmt() << endl;
        cout << aquarium.get_list_piranha().getNBelmt() << endl;
        cout << aquarium.get_list_guppy().getNBelmt() << endl;
        cout << aquarium.get_list_food().getNBelmt() << endl;
        cout << aquarium.get_list_siput().getNBelmt() << endl;

        clear_screen();
        aquarium.draw();
        string egg = to_string(Aquarium::egg);
        string money = to_string(Aquarium::money);
        
        draw_text("Money  " + money, 18, 10, 10, 0, 0, 0);
        draw_text("Egg    " + egg, 18, 10, 30, 0, 0, 0);
        update_screen();
        
    }

    close();
}