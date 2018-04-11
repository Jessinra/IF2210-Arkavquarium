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

// pixels per second
const double speed = 150; 

int main(int argc, char* args[]) {

    /************   initialize section *********/

    // initialize window 
    init();

    bool running = true;

    // starting time 
    double prevtime = time_since_start();

    bool status_main = true;
    bool status_credit = false;
    while (status_main) {
        handle_input();
        if (quit_pressed()) {
            running = false;
        }
        clear_screen();
        draw_image(FILE_main_menu, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        if (get_mouse_button_down(0) && (get_mouse_pos_x() >= (SCREEN_WIDTH/2)-110 && get_mouse_pos_x() <= (SCREEN_WIDTH/2)+110 && get_mouse_pos_y() <= (SCREEN_HEIGHT/2)+245 && get_mouse_pos_y() >= (SCREEN_HEIGHT/2)+170)) {
            status_credit = true;
            status_main = false;
        }
        else if (get_mouse_button_down(0) && (get_mouse_pos_x() >= (SCREEN_WIDTH/2)-110 && get_mouse_pos_x() <= (SCREEN_WIDTH/2)+110 && get_mouse_pos_y() <= (SCREEN_HEIGHT/2)+10 && get_mouse_pos_y() >= (SCREEN_HEIGHT/2)-65)) {
            status_main = false;
        }
        update_screen();
    }
    while (status_credit) {
        handle_input();
        if (quit_pressed()) {
            running = false;
        }
        clear_screen();
        draw_image(FILE_credit, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        if (get_mouse_button_down(0)) {
            status_credit = false;
            status_main = true;
        }
        update_screen();
    }

    // create aquarium
    Aquarium aquarium;     
    
    // create cursor
    double cx = SCREEN_WIDTH/2;
    double cy = 20;

    int ct = 1;
    cout << ct++ << endl;

    /*******        main loop            *******/
    while (running) {

        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        cout << ct++ << "Money: "<< Aquarium::money << endl;
        /********* cek input keyboard *********/

        // jangan lupa validasi uang & kurangin uang
        handle_input();
        if (quit_pressed()) {
            running = false;
        }
        
        cout << "Money: " << Aquarium::money << endl;

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
                // save
                case SDLK_q:

                    aquarium.save();
                    break;
                // load
                case SDLK_l:

                    aquarium.load();
                    break;
                
            }
        }

        cout << ct++<< "Money: "<< Aquarium::money << endl; //3

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

        // on left mouse click
        if (get_mouse_button_down(0)) {
            int val = aquarium.click_coin(get_mouse_pos_x(),get_mouse_pos_y()); // cek coin
            if (val != 0) {
                Aquarium::money += val;
            } else {
                aquarium.buy_food(get_mouse_pos_x());       // beli makan
            }
        }


        cout << ct++<< "Money: "<< Aquarium::money << endl; //4
        /******* pengecekan *******/

        // cek jumlah ikan u/ menang/kalah
        if ((aquarium.get_list_guppy().getNBelmt() == 0) && (aquarium.get_list_piranha().getNBelmt() == 0 ) && (Aquarium::money < GUPPY_PRICE)) {
            draw_image(FILE_lose, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            update_screen();
        } 

        // cek telur untuk menang/kalah
        else if (Aquarium::egg == 3) {
            draw_image(FILE_win, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            update_screen();
        }

        // game still continue
        else {
            cout << ct++ << "Money: "<< Aquarium::money<< endl; //5
            // iterasi list guppy
            for (int i = 1; i <= aquarium.get_list_guppy().getNBelmt(); i++) {
                cout << ct++ << endl; //6
                Guppy &current_guppy = aquarium.get_list_guppy().get(i);

                // cek mati 
                if (current_guppy.get_hunger() < 0) {

                    aquarium.remove_guppy(current_guppy);
                    i--;

                } else {
                    cout << "?" << "Money: "<< Aquarium::money<< endl;
                    // move fish
                    current_guppy.move(sec_since_last, aquarium.get_list_food());
                    cout << "a" << "Money: "<< Aquarium::money<< endl;
                    // check to drop coin & reduce timer
                    if(current_guppy.produce_coin()){

                        Coin *c = new Coin(current_guppy.get_x(), current_guppy.get_y(), current_guppy.get_coin_value());
                        aquarium.add_coin(*c);

                    }
                    cout << "makan" << "Money: "<< Aquarium::money<< endl;
                    // cek untuk makan
                    current_guppy.eat(aquarium.get_list_food());
                    cout << "hunger"<< "Money: "<< Aquarium::money << endl;
                    // ngurangin hunger
                    current_guppy.makeHungry();
                    
                }
            }
            cout << ct++ << endl; //7
            // iterasi list piranha
            for (int i = 1; i <= aquarium.get_list_piranha().getNBelmt(); i++) {
                
                Piranha &current_piranha = aquarium.get_list_piranha().get(i);

                // cek mati
                if (current_piranha.get_hunger() < 0) {
                    
                    aquarium.remove_piranha(current_piranha);
                    i--;

                } else {

                    // move fish
                    current_piranha.move(sec_since_last, aquarium.get_list_guppy());
                
                    // cek untuk makan
                    int eaten_lv = current_piranha.eat(aquarium.get_list_guppy());

                    // check drop coin
                    if (eaten_lv > 0){

                        int coin_val = current_piranha.get_coin_value() * (eaten_lv+1); // piranha coin value = guppy price 
                        Coin *c = new Coin(current_piranha.get_x(), current_piranha.get_y(), coin_val);
                        aquarium.add_coin(*c);
                    }

                    // ngurangin hunger
                    current_piranha.makeHungry();

                }
            }
            cout << ct++<< "Money: "<< Aquarium::money<< endl; //8
            // iterasi list coin
            for (int i = 1; i <= aquarium.get_list_coin().getNBelmt(); i++) {

                Coin &current_coin = aquarium.get_list_coin().get(i);

                // move coin
                current_coin.move(sec_since_last);

            }
            cout << ct++<< "Money: "<< Aquarium::money << endl; //9
            // iterasi list makanan
            for (int i = 1; i <= aquarium.get_list_food().getNBelmt(); i++) {

                Food &current_food = aquarium.get_list_food().get(i);

                // remove food that touch the bottom
                if (current_food.get_y() >= SCREEN_BOTTOM){
                    aquarium.remove_food(current_food);
                    i--;
                }
                
                // move food
                current_food.move(sec_since_last);
            }

            cout << ct++ << "Money: "<< Aquarium::money<< endl; //10

            // iterasi list siput
            for (int i = 1; i <= aquarium.get_list_siput().getNBelmt(); i++) {

                Siput &current_siput = aquarium.get_list_siput().get(i);
                cout << "siput gerak" << endl;
                // move siput
                current_siput.move(sec_since_last,aquarium.get_list_coin());
                // get coin
                cout << "Money: "<< Aquarium::money << endl;
                Aquarium::money += current_siput.take_coin(aquarium.get_list_coin());
                // current_siput.take_coin();

            }

            cout << ct++ << "Money: "<< Aquarium::money<< endl;//11
            // draw every faking thing (fish, coin, food, piranha, siput, money, egg count ,command ) 
            clear_screen();
            aquarium.draw();
            string egg = to_string(Aquarium::egg);
            string money = to_string(Aquarium::money);
            
            draw_text("Money  " + money, 18, 10, 10, 0, 0, 0);
            draw_text("Egg    " + egg, 18, 10, 30, 0, 0, 0);
            update_screen();
            
            //usleep(100000);
        }
    }

    close();
}