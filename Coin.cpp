#include "Coin.h"

using namespace std;

int Coin::coin_amount = 0;
/*------------------------------------------------------------
                    Constructor & Destructor 	
------------------------------------------------------------*/

Coin::Coin(int x, int y, int value) {
    set_x(x);
    set_y(y);
    coin_amount++;
    coin_id = coin_amount;
    coin_value = value;
}

/*------------------------------------------------------------
                        Getter	Setter
------------------------------------------------------------*/

int Coin::get_id() {
    return coin_id;
}
int Coin::get_value() {
    return coin_value;
}

/*------------------------------------------------------------
                            Method  
------------------------------------------------------------*/

void Coin::draw() {
    draw_image("coin.png", get_x(), get_y());
}

void Coin::move() {
    set_y(get_y()-1);
}