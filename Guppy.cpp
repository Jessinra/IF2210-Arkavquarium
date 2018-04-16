#include "Guppy.h"
#include <iostream>
#include <cmath>

using namespace std;

/*------------------------------------------------------------
                    Constructor & Destructor 	
------------------------------------------------------------*/
Guppy::Guppy() : Fish(GUPPY_PRICE, GUPPY_COIN_VAL_01) {
	
	// value from constant.h
	set_speed(GUPPY_MOVEMENT_SPD);

	set_number_eat(0);
	set_timer(GUPPY_DROP_COIN_TIME);
	set_level(1);
	cout << get_x() << "POSISI X" << get_y() << "POSISI Y" << endl;

}

Guppy& Guppy::operator=(Guppy& g) {
	set_id(g.get_id());
	set_x(g.get_x());
	set_y(g.get_y());
	set_price(g.get_price());
	set_coin_value(g.get_coin_value());
	set_hunger(g.get_hunger());
	set_hungry(g.get_hungry());
	set_dir(g.get_dir());
	set_time_move(g.get_time_move());
	set_speed(g.get_speed());
	set_number_eat(g.get_number_eat());
	set_timer(g.get_timer());
	set_level(g.get_level());
	set_x_move(g.get_x_move());
	set_y_move(g.get_y_move());
	
	return *this;
}

/*------------------------------------------------------------
                        Getter	Setter
------------------------------------------------------------*/		
int Guppy::get_level() {
	return level_grow;
}

void Guppy::set_level(int lv) {
	level_grow = lv;
}

int Guppy::get_number_eat() {
	return number_eat;
}

void Guppy::set_number_eat(int number) {
	number_eat = number;
}

double Guppy::get_timer() {
	return timer;
}

void Guppy::set_timer(double time) {
	timer = time;
}

const int Guppy::get_max_level() {
	return max_level;
}

/*------------------------------------------------------------
                            Method  
------------------------------------------------------------*/ 

bool Guppy::operator==(Guppy& g) {
	return get_id() == g.get_id();
}

bool Guppy::operator!=(Guppy& g) {
	return get_id() != g.get_id();
}

void Guppy::draw() {
	// draw guppy on screen 
	
	if (Fish::isHungry()) {
			if (level_grow == 1) {
				if (Moveable::get_dir() == "Left") {
					draw_image(FILE_guppy_01_left_hungry, get_x(), get_y());
				}
				else {
					draw_image(FILE_guppy_01_right_hungry, get_x(), get_y());	
				}
			}
			else if (level_grow == 2) {
				if (Moveable::get_dir() == "Left") {
					draw_image(FILE_guppy_02_left_hungry, get_x(), get_y());
				}
				else {
					draw_image(FILE_guppy_02_right_hungry, get_x(), get_y());	
				}
			}
			else if (level_grow == 3) {
				if (Moveable::get_dir() == "Left") {
					draw_image(FILE_guppy_03_left_hungry, get_x(), get_y());
				}
				else {
					draw_image(FILE_guppy_03_right_hungry, get_x(), get_y());	
				}
			}
	}
	else {
			
			if (level_grow == 1) {
				if (Moveable::get_dir() == "Left") {
					draw_image(FILE_guppy_01_left, get_x(), get_y());
				}
				else {
					draw_image(FILE_guppy_01_right, get_x(), get_y());	
				}
			}
			else if (level_grow == 2) {
				if (Moveable::get_dir() == "Left") {
					draw_image(FILE_guppy_02_left, get_x(), get_y());
				}
				else {
					draw_image(FILE_guppy_02_right, get_x(), get_y());	
				}
			}
			else if (level_grow == 3) {
				if (Moveable::get_dir() == "Left") {
					draw_image(FILE_guppy_03_left, get_x(), get_y());
				}
				else {
					draw_image(FILE_guppy_03_right, get_x(), get_y());	
				}
			}
	}
}

bool Guppy::produce_coin() {
	// check if guppy able to drop coin
	
	// if yes,
	if(get_timer() <= 0){

		// then set timer to max, and return true
		set_timer(GUPPY_DROP_COIN_TIME);
		return true;
	}

	else{

		// reduce drop coin time 
		set_timer(get_timer()-FISH_TIMER_DEC/5);
		return false;
	}
}   

int Guppy::findFood(LinkedList<Food>& F) {
	//nyari yg terdekat brrti pake iterate dari list Food
	
	int idx = 1;
	int i = 2; //indeks perbandingan mulai dari 2
	
	while (i<=F.getNBelmt()) {
		if (F.get(i).get_x() > SCREEN_TOP && F.get(i).get_x() < SCREEN_BOTTOM && F.get(i).get_x() > SCREEN_LEFT && F.get(i).get_x() < SCREEN_RIGHT && euclidean(F.get(idx)) > euclidean(F.get(i))) {
			idx = i;
		}
		else {
			i++;
		}
	}
	return idx;
}

void Guppy::move(double sec_since_last,LinkedList<Food> &F) {

	double x;
	double y;
	if (Fish::isHungry() && F.getNBelmt() > 0) {
		//mengejar food pakai tips
		int idx = findFood(F);
		if (F.get(idx).get_x() < get_x()) {
			set_dir("Left");
		}
		else {
			set_dir("Right");
		}

		double a = atan2(F.get(idx).get_y()-get_y(), F.get(idx).get_x()-get_x());
		set_x(get_x()+(double)(Fish::get_speed()*cos(a)*sec_since_last*1.5));
		set_y(get_y()+(double)(Fish::get_speed()*sin(a)*sec_since_last*1.5));
	}
	else {
		//random arahnya
		if (Fish::get_time_move() <= 0) {
			Fish::set_time_move(FISH_MAX_TIMER);
			x = rand() % 3;
			y = rand() % 3;
			if (x == 1) {
				x = -1;
				set_dir("Left");
			}
			else if (x == 2) {
				x = 0;
			}
			else {
				x = 1;
				set_dir("Right");
			}
			if (y == 1) {
				y = -1;
			}
			else if (y == 2) {
				y = 0;
			}
			else {
				y = 1;
			}
			Fish::set_x_move(x);
			Fish::set_y_move(y);
		}
		else {
			Fish::set_time_move(Fish::get_time_move()-sec_since_last);
		}

		//kalau sampai ujung
		if (get_x() >= SCREEN_RIGHT || get_x() <= SCREEN_LEFT) {
			Fish::set_x_move(Fish::get_x_move()*(-1));
		}
		if (get_y() <= SCREEN_TOP || get_y() >= SCREEN_BOTTOM) {
			Fish::set_y_move(Fish::get_y_move()*(-1));
		}

		//pindahkan ikan
		set_x(get_x()+Fish::get_speed()*sec_since_last*Fish::get_x_move());
		set_y(get_y()+Fish::get_speed()*sec_since_last*Fish::get_y_move());
	}
}

double Guppy::euclidean(Food &m) {
	// get euclidean distance from guppy to food

	double x_guppy = get_x();
	double y_guppy = get_y();
	double x_food = m.get_x(); 
	double y_food = m.get_y();

	return (sqrt(pow(x_guppy-x_food, 2)) + (pow(y_guppy-y_food, 2)));
}

int Guppy::inRadius(LinkedList<Food>& F) {
	//nyari ikan nya udah diradius itu blm

	int idx = 1;
	double radius = 50;
	bool find = false;
	if (F.getNBelmt() > 0) {
		while (!find && idx<=F.getNBelmt()) {
			if ((radius > abs(get_x()-F.get(idx).get_x())) && (radius > abs(get_y()-F.get(idx).get_y()))) {
				find = true;
			}
			else {
				idx++;
			}
		}
	}
	if (find) {
		return idx;
	}
	else {
		return -999;
	}
}

void Guppy::eat(LinkedList<Food>& F) {
	//eat gak usah pake validasi laper. yg validasi laper itu move.
	//kalau ada ikan diradius itu, eat (itu aja fx nya)

	// search for food 
	int idx = inRadius(F);

	// if found
	if (idx != -999 && Fish::isHungry()) {

		// remove food from list 
		F.remove(F.get(idx));

		// set hunger to max and state ishungry to false
		Fish::fullHunger();
		Fish::set_hungry(false);

		// increase number of food eaten
		set_number_eat(get_number_eat() + 1);
		
		// try to check if fish is able to grow
		grow();
		
	}
}

void Guppy::grow() {
	if (get_number_eat() == GUPPY_REQ_FOOD_COUNT && get_level() != GUPPY_MAX_LV) {
		
		// increase fish lv
		set_level(get_level()+1);
		
		// increase max hunger 
		set_max_hunger(get_max_hunger() + GUPPY_HUNGER_INCREASE_RATE); //tiap naik level tambah bisa nambah laper
		
		// increase the coin value 
		set_coin_value(get_coin_value() + GUPPY_COIN_VAL_INCREASE_RATE); //tiap naik level tambah harga coin nya

		// reset the number of food eaten
		set_number_eat(0);
	}
}    