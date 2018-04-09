#include "Fish.h"
#include <stdlib.h>

#include "Constant.h"

using namespace std;

int Fish::fish_count = 0;
		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
	Fish::Fish(int price, int cvalue) {
		double x = rand() % SCREEN_WIDTH;
		double y = rand() % SCREEN_HEIGHT;
		set_x(x);
		set_y(y);

		Fish::fish_count++;

		fish_id = Fish::fish_count;
		fish_price = price;
		coin_value = cvalue;
		hungry = false;
	}

		/*------------------------------------------------------------
								Getter	Setter
		------------------------------------------------------------*/
	int Fish::get_id() {
		return fish_id;
	}
	
	int Fish::get_price() {
		return fish_price;
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
	
	int Fish::get_speed() {
		return speed;
	}

	bool Fish::get_hungry() {
		return hungry;
	}

	void Fish::set_hungry(bool status) {
		hungry = status;
	}

	const int Fish::get_max_hunger() {
		return max_hunger;
	}

		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
	void Fish::fullHunger() {
		hunger = max_hunger;
	}

	void Fish::makeHungry() {
		hunger = hunger - 0.5;
	}

	void Fish::isHungry() {
		if (get_hunger() < get_max_hunger()) {
			set_hungry(true);
		}
		else {
			set_hungry(false);
		}
	}

	bool Fish::isDead() {
		if (get_hunger() == 0) {
			return true;
		}
		else {
			return false;
		}
	}