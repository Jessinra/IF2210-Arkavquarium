// main
#include "Aquarium.h"
#include "Lib/oop.hpp"
#include "Guppy.h"
#include "Piranha.h"
#include "Siput.h"

#include <math.h>
#include <sstream>
using namespace std;

const double speed = 150; // pixels per second

int main(int argc, char* args[]) {
    init();

    Aquarium aquarium;      // create aquarium

    bool running = true;
    bool win = false;

    double prevtime = time_since_start();

    // create cursor
    double cx = SCREEN_WIDTH/2;
    double cy = 20;

    /******* main loop *******/
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
                Guppy *g = new Guppy();
                aquarium.add_guppy(*g);
                break;
            // buy food
            case SDLK_f:
                Food *f = new Food();
                aquarium.add_food(*f);
                break;
            // buy piranha
            case SDLK_p:
                Piranha *p = new Piranha();
                aquarium.add_piranha(*p);
                break;
            // buy egg
            case SDLK_e:
                Aquarium::egg++;
                break;
            // buy snail
            case SDLK_s:
                Siput *s = new Siput();
                aquarium.add_siput(*s);
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
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
            }
        }

        /******* pengecekan *******/
        // cek jumlah ikan u/ menang/kalah
        if (aquarium.get_list_guppy().getNBelmt() == 0 && aquarium.get_list_piranha().getNBelmt()) {
            running = false;
        } 
        // cek telur untuk menang/kalah
        else if (Aquarium::egg == 3) {
            win = true;
            running = false;
        }
        else {
        // iterasi list guppy
            for (int i = 1; i <= aquarium.get_list_guppy().getNBelmt(); i++) {
                // cek mati
                if (aquarium.get_list_guppy().get(i).get_hunger() == 0) {
                    Guppy guppy_rem = aquarium.get_list_guppy().get(i);
                    aquarium.remove_guppy(guppy_rem);
                    i--;
                } else {
                // move fish
                
                // cek untuk drop coin
                
                // ngurangin c

                // ngurangin hunger
                
                // tampilin di layar
                }
            }
        // iterasi list piranha
            for (int i = 1; i <= aquarium.get_list_piranha().getNBelmt(); i++) {
                // cek mati
                if (aquarium.get_list_piranha().get(i).get_hunger() == 0) {
                    Piranha piranha_rem = aquarium.get_list_piranha().get(i);
                    aquarium.remove_piranha(piranha_rem);
                    i--;
                } else {
                // move fish
                
                // ngurangin hunger
                
                // tampilin di layar
                }
            }
        // iterasi list coin
            for (int i = 1; i <= aquarium.get_list_coin().getNBelmt(); i++) {
                // move coin
                aquarium.get_list_coin().get(i).move(sec_since_last);

                // tampilin di layar
            }
                
        // iterasi list makanan
            for (int i = 1; i <= aquarium.get_list_food().getNBelmt(); i++) {
                // move food
                // aquarium.get_list_food().get(i).move((int)sec_since_last);

                // tampilin di layar
            }
        // iterasi list siput
            for (int i = 1; i <= aquarium.get_list_siput().getNBelmt(); i++) {
                // move siput

                // tampilin di layar
            }
        // tampilin uang
        // tampilin telur
        // tampilin button yang dapat digunakan
        }
    }
}