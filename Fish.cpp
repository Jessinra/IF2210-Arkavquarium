#include "Fish.h"
#include <stdlib.h>

#include "Constant.h"

using namespace std;

int Fish::fish_count = 0;

		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
	Fish::Fish(int price, int cvalue) {

		// set position
		set_x(SCREEN_RIGHT/2);
		set_y(SCREEN_BOTTOM/2);

		Fish::fish_count++;

		set_id(Fish::fish_count);
		set_price(price);
		set_coin_value(cvalue);
		fullHunger();	//set hunger to max value
		set_hungry(false);
		Moveable::set_dir("Right");
		time_move = FISH_MAX_TIMER;
		x_move = 1;
		y_move = 1;
	}

		/*------------------------------------------------------------
								Getter	Setter
		------------------------------------------------------------*/
	int Fish::get_id() {
		return fish_id;
	}
	
	void Fish::set_id(int id){
		fish_id = id;
	}

	int Fish::get_price() {
		return fish_price;
	}
	
	void Fish::set_price(int price){
		fish_price = price;
	}

	int Fish::get_coin_value() {
		return coin_value;
	}

	void Fish::set_coin_value(int cvalue) {
		coin_value = cvalue;
	}

	double Fish::get_hunger() {
		return hunger;
	}
	
	void Fish::set_hunger(double hunger){
		this->hunger = hunger;
	}

	int Fish::get_speed() {
		return speed;
	}

	void Fish::set_speed(int spd){
		speed = spd;
	}

	bool Fish::get_hungry() {
		return hungry;
	}

	void Fish::set_hungry(bool status) {
		hungry = status;
	}

	double Fish::get_time_move() {
		return time_move;
	}

	void Fish::set_time_move(double t) {
		time_move = t;
	}

	int Fish::get_x_move() {
		return x_move;
	}

	void Fish::set_x_move(int x) {
		x_move = x;
	}

	int Fish::get_y_move() {
		return y_move;
	}

	void Fish::set_y_move(int y) {
		y_move = y;
	}

	const double Fish::get_max_hunger() {
		return max_hunger;
	}

	void Fish::set_max_hunger(double h) {
		max_hunger = h;
	}

		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
	void Fish::fullHunger() {
		// set hunger to max value 

		set_hunger(get_max_hunger());
	}

	void Fish::makeHungry() {
		// Periodicly make fish hungry 

		set_hunger(get_hunger() - FISH_HUNGER_DECREASE_RATE);
	}

	bool Fish::isHungry() {
		// check if fish hunger is below certain point

		if (get_hunger() <=  FISH_HUNGRY_BORDERLINE) {
			set_hungry(true);
			return true;
		}
		else {
			return false;
		}
	}

	bool Fish::isDead() {
		// check if fish hunger is below or equal zero
		
		if (get_hunger() <= 0) {
			return true;
		}
		else {
			return false;
		}
	}