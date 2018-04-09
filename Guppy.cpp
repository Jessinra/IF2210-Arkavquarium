#include "Guppy.h"
#include <cmath>

using namespace std;

/*------------------------------------------------------------
                    Constructor & Destructor 	
------------------------------------------------------------*/
Guppy::Guppy() {
	
	// value from constant.h
	Fish::Fish(GUPPY_PRICE, GUPPY_COIN_VAL_01);
	set_speed(GUPPY_MOVEMENT_SPD);

	set_number_eat(0);
	set_timer(GUPPY_DROP_COIN_TIME);
	set_level(1);

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

double Guppy::set_timer(double time) {
	timer = time;
}

const int Guppy::get_max_level() {
	return get_max_level;
}

//implement Moveable
double Guppy::get_x() {
	return Moveable::get_x();
}

double Guppy::get_y() {
	return Moveable::get_y();
}

/*------------------------------------------------------------
                            Method  
------------------------------------------------------------*/ 
void Guppy::draw() {
	// draw guppy on screen 

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

bool Guppy::produce_coin() {
	// check if guppy able to drop coin
	
	// if yes,
	if(get_timer() <= 0){

		// then sex timer to max, and return true
		set_timer(GUPPY_DROP_COIN_TIME);
		return true;
	}

	else{

		// reduce drop coin time 
		set_timer(get_timer()-GUPPY_TIMER_DEC);
		return false;
	}
}   

int Guppy::findFood(LinkedList<Food> F) {
	//nyari yg terdekat brrti pake iterate dari list Food
	
	int idx = 1;
	int i = 2; //indeks perbandingan mulai dari 2
	
	while (i<=F.getNBelmt()) {
		if (euclidean(F.get(idx) > euclidean(F.get(i)))) {
			idx = i;
		}
		else {
			idx++;
		}
	}
	return idx;
}

void Guppy::move(double sec_since_last,LinkedList<Food> F) {

	double x;
	double y;

	if (Fish::isHungry()) {
		//mengejar food pakai tips

		int idx = findFood(F);
		double a = atan2(F.get(idx).get_x()-get_x(), F.get(idx).get_y()-get_y());
		set_x(get_x()+Fish::get_speed()*cos(a)*sec_since_last);
		set_y(get_y()+Fish::get_speed()*sin(a)*sec_since_last);
	}
	else {

		x = rand() % SCREEN_WIDTH;
		y = rand() % SCREEN_HEIGHT;
		if (x >= (SCREEN_WIDTH/2)) {
			x = 1;
		}
		else {
			x = -1;
		}
		if (y >= (SCREEN_HEIGHT/2)) {
			y = 1;
		}
		else {
			y = -1;
		}
		if ((get_x() > 0) && (get_x() < SCREEN_WIDTH) && (get_y() > 0) && (get_y() < SCREEN_HEIGHT)) {
			set_x(get_x()+Fish::get_speed()*sec_since_last*x);
			set_y(get_y()+Fish::get_speed()*sec_since_last*y);
		}
		else {
			if (get_x() == 0) {
				set_x(get_x()+Fish::get_speed()*sec_since_last);	
			}
			else if (get_x() == SCREEN_WIDTH) {
				set_x(get_x()-Fish::get_speed()*sec_since_last);	
			}
			if (get_y() == 0) {
				set_y(get_y()+Fish::get_speed()*sec_since_last);	
			}
			else if (get_y() == SCREEN_HEIGHT) {
				set_y(get_y()-Fish::get_speed()*sec_since_last);	
			}
		}
	}
}

double euclidean(Food &m) {
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
	double radius = 1;
	bool find = false;

	while (!find && i<F.getNBelmt()) {
		if (radius > euclidean(F.get(idx))) {
			find = true;
		}
		else {
			idx++;
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
	int idx = inRadius();

	// if found
	if (idx != -999) {

		// remove food from list 
		F.remove(F.get(idx));

		// set hunger to max and state ishungry to false
		Fish::fullHunger();
		Fish::setHungry(false);

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
		set_maxHunger(get_maxHunger() + GUPPY_HUNGER_INCREASE_RATE); //tiap naik level tambah bisa nambah laper
		
		// increase the coin value 
		set_coin_value(get_coin_value() + GUPPY_COIN_VAL_INCREASE_RATE); //tiap naik level tambah harga coin nya

		// reset the number of food eaten
		set_number_eat(0);
	}
}    