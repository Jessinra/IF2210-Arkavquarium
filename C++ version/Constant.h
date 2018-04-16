#ifndef CONSTANT_H
#define CONSTANT_H

#include "Lib/oop.hpp"
using namespace std;

const int GUPPY_PRICE = 50;
const int PIRANHA_PRICE = 250;
const int FOOD_PRICE = 2;
const int EGG_PRICE = 4000;
const int SIPUT_PRICE = 1250;

const int GUPPY_COIN_VAL_01 = 5;
const int GUPPY_COIN_VAL_02 = 15; 
const int GUPPY_COIN_VAL_03 = 25;
const int GUPPY_COIN_VAL_INCREASE_RATE = 10;

const int PIRANHA_COIN_VAL = GUPPY_PRICE;	 //harga ikan 

const double GUPPY_DROP_COIN_TIME = 10;

const double FISH_TIMER_DEC = 0.1;
const double FISH_MAX_HUNGER = 20;
const double FISH_HUNGRY_BORDERLINE = 10; // Fish getting hungry below this point
const double FISH_HUNGER_DECREASE_RATE = 0.01;
const double FISH_MAX_TIMER = 1;

const int GUPPY_MAX_LV = 3;
const int GUPPY_REQ_FOOD_COUNT = 5;		// how many food needed to lvl up
const int GUPPY_HUNGER_INCREASE_RATE = 10;

const int GUPPY_MOVEMENT_SPD = 100;
const int PIRANHA_MOVEMENT_SPD = 150;
const int COIN_MOVEMENT_SPD = 50;
const int SIPUT_MOVEMENT_SPD = 100;
const int FOOD_MOVEMENT_SPD = 50;

const int SCREEN_TOP = 80;
const int SCREEN_BOTTOM = SCREEN_HEIGHT - 80;
const int SCREEN_LEFT = 80;
const int SCREEN_RIGHT = SCREEN_WIDTH - 80;

/**** IMAGE ****/

const string FILE_guppy_01_left = "img/guppy_01.png";
const string FILE_guppy_02_left = "img/guppy_02.png";
const string FILE_guppy_03_left = "img/guppy_03.png";

const string FILE_guppy_01_right = "img/guppy_01_r.png";
const string FILE_guppy_02_right = "img/guppy_02_r.png";
const string FILE_guppy_03_right = "img/guppy_03_r.png";

const string FILE_guppy_01_left_hungry = "img/guppy_01_h.png";
const string FILE_guppy_02_left_hungry = "img/guppy_02_h.png";
const string FILE_guppy_03_left_hungry = "img/guppy_03_h.png";

const string FILE_guppy_01_right_hungry = "img/guppy_01_r_h.png";
const string FILE_guppy_02_right_hungry = "img/guppy_02_r_h.png";
const string FILE_guppy_03_right_hungry = "img/guppy_03_r_h.png";

const string FILE_piranha_left = "img/piranha.png";
const string FILE_piranha_right = "img/piranha_r.png";

const string FILE_piranha_left_hungry = "img/piranha_h.png";
const string FILE_piranha_right_hungry = "img/piranha_r_h.png";

const string FILE_siput_left = "img/snail.png";
const string FILE_siput_right = "img/snail_r.png";

const string FILE_coin = "img/coin.png";

const string FILE_food = "img/food.png";

const string FILE_aquarium = "img/Aquarium2.jpg";

const string FILE_main_menu = "img/main.jpg";

const string FILE_win = "img/youwin.png";

const string FILE_lose = "img/gameover.png";

const string FILE_credit = "img/credit.jpeg";

#endif