#include "Coin.h"

using namespace std;

int Coin::coin_amount = 0;
/*------------------------------------------------------------
                    Constructor & Destructor 	
------------------------------------------------------------*/

Coin::Coin() {
    
    set_x(0);
    set_y(0);
    set_id(0);
    set_value(0);
    set_speed(COIN_MOVEMENT_SPD);

}

Coin::Coin(int x, int y, int value) {

    set_x(x);
    set_y(y);

    Coin::coin_amount++;

    set_id(Coin::coin_amount);
    set_value(value);
    set_speed(COIN_MOVEMENT_SPD);

}

/*------------------------------------------------------------
                        Getter	Setter
------------------------------------------------------------*/

int Coin::get_id() {
    return coin_id;
}

void Coin::set_id(int id){
    coin_id = id;
}

int Coin::get_value() {
    return coin_value;
}

void Coin::set_value(int value){
    coin_value = value;
}

int Coin::get_speed(){
    return coin_speed;
}

void Coin::set_speed(int spd){
    coin_speed = spd;
}

/*------------------------------------------------------------
                            Method  
------------------------------------------------------------*/

void Coin::draw() {
    draw_image(FILE_coin, get_x(), get_y());
}

void Coin::move(double sec_since_last) {

    // if coin is not on bottom yet, 
    if (get_y() <= SCREEN_BOTTOM) {

        // move coin towards bottom of the tank
        set_y(get_y()+(get_speed() * sec_since_last));
    } else {
        set_y(SCREEN_BOTTOM);
    }
}


Coin& Coin::operator=(Coin& s) {
    set_x(s.get_x());
    set_y(s.get_y());

    set_id(s.get_id());
    set_value(s.get_value());
    set_speed(COIN_MOVEMENT_SPD);

    return *this;
}   

bool Coin::operator==(Coin& s) {
    return get_id() == s.get_id();
}

bool Coin::operator!=(Coin& s) {
    return get_id() != s.get_id();
}