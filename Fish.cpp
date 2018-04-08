#include "Fish.h"
#include <stdlib.h>

using namespace std;

		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
	Fish::Fish(int price, int cvalue) {
		double x = rand() % 640;
		double y = rand() % 480;
		set_x(x);
		set_y(y);
		fish_count++;
		fish_id = fish_count;
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

	void set_coin_value(int cvalue) {
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

	const int get_max_hunger() {
		return get_max_hunger;
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

	bool Fish::isDie() {
		if (get_hunger() == 0) {
			return true;
		}
		else {
			return false;
		}
	}