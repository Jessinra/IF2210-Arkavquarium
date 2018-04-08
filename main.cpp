#include "Aquarium.h"
#include "Lib/oop.hpp"
#include "Guppy.h"
#include "Piranha.h"
#include "Siput.h"

#include <math.h>
#include <sstream>
using namespace std;

// pixels per second
const double speed = 150; 

int main(int argc, char* args[]) {

    /************   initialize section *********/

    // initialize window 
    init();

    bool running = true;
    bool win = false;

    // starting time 
    double prevtime = time_since_start();

    // create aquarium
    Aquarium aquarium;     

    // create cursor
    double cx = SCREEN_WIDTH/2;
    double cy = 20;

    /*******        main loop            *******/
    while (running) {

        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        /********* cek input keyboard *********/

        // jangan lupa validasi uang & kurangin uang
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
            switch (key) {

                // buy guppy
                case SDLK_g:
                    aquarium.buy_guppy();
                    break;

                // buy food
                case SDLK_f:
                    
                    aquarium.buy_food();
                    break;

                // buy piranha
                case SDLK_p:
                    
                    aquarium.buy_piranha();
                    break;

                // buy egg
                case SDLK_e:
                    
                    aquarium.buy_egg();
                    break;

                // buy snail
                case SDLK_s:
                    
                    aquarium.buy_snail();
                    break;

                // x untuk keluar
                case SDLK_x:

                    running = false;
                    break;
            }
        }

        // cursor dan gerakan cursor
        for (auto key : get_pressed_keys()) {

            switch (key) {

                // move up
                case SDLK_UP:
                    cy -= speed * sec_since_last;
                    break;

                // move down
                case SDLK_DOWN:
                    cy += speed * sec_since_last;
                    break;

                // move left
                case SDLK_LEFT:
                    cx -= speed * sec_since_last;
                    break;

                // move right
                case SDLK_RIGHT:
                    cx += speed * sec_since_last;
                    break;
            }
        }

        /******* pengecekan *******/

        // cek jumlah ikan u/ menang/kalah
        if ((aquarium.get_list_guppy().getNBelmt() == 0) && (aquarium.get_list_piranha().getNBelmt() == 0 ) && (aquarium::money < guppy_price)) {
            running = false;
        } 

        // cek telur untuk menang/kalah
        else if (Aquarium::egg == 3) {
            win = true;
            running = false;
        }

        // game still continue
        else {

            // iterasi list guppy
            for (int i = 1; i <= aquarium.get_list_guppy().getNBelmt(); i++) {

                Guppy current_guppy = aquarium.get_list_guppy().get(i);

                // cek mati 
                if (current_guppy.get_hunger() < 0) {

                    aquarium.remove_guppy(current_guppy);
                    i--;

                } else {

                    // move fish
                    current_guppy.move(sec_since_last);
                
                    // cek untuk drop coin
                    if(current_guppy.produce_coin()){

                        Coin *c = new Coin();
                        aquarium.add_coin(*c);

                    }

                    // cek untuk makan
                    

                    // ngurangin c


                    // ngurangin hunger
                    current_guppy.set_hunger(current_guppy.get_hunger() - hunger_decrease_const)
                    
                }
            }

            // iterasi list piranha
            for (int i = 1; i <= aquarium.get_list_piranha().getNBelmt(); i++) {
                
                Piranha current_piranha = aquarium.get_list_piranha().get(i);

                // cek mati
                if (current_piranha.get_hunger() < 0) {
                    
                    aquarium.remove_piranha(current_piranha);
                    i--;

                } else {

                    // move fish
                    current_piranha.move(sec_since_last);
                    


                    // cek untuk makan & drop coin



                    // ngurangin hunger
                    current_piranha.set_hunger(current_piranha.get_hunger() - hunger_decrease_const)

                }
            }

            // iterasi list coin
            for (int i = 1; i <= aquarium.get_list_coin().getNBelmt(); i++) {

                Coin current_coin = aquarium.get_list_coin().get(i);

                // move coin
                current_coin.move(sec_since_last);

            }
                
            // iterasi list makanan
            for (int i = 1; i <= aquarium.get_list_food().getNBelmt(); i++) {

                Food current_food = aquarium.get_list_food().get(i);

                // move food
                current_food.move(sec_since_last);

            }

            // iterasi list siput
            for (int i = 1; i <= aquarium.get_list_siput().getNBelmt(); i++) {

                Siput current_siput = aquarium.get_list_siput().get(i);

                // move siput
                current_siput.move(sec_since_last);

                // get coin
                // current_siput.take_coin();

            }

            // draw every faking thing (fish, coin, food, piranha, siput, money, egg count ,command ) 
            aquarium.draw()  
        }
    }
}