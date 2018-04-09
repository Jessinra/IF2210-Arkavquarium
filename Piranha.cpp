#include "Piranha.h"
#include <cmath>

using namespace std;

/*------------------------------------------------------------
				Constructor & Destructor 	
------------------------------------------------------------*/	
Piranha::Piranha() {

	Fish::Fish(PIRANHA_PRICE, PIRANHA_COIN_VAL);
	set_speed(PIRANHA_MOVEMENT_SPD);
}


/*------------------------------------------------------------
                        Getter	Setter
------------------------------------------------------------*/	

//implement Moveable
double Piranha::get_x() {
	return Moveable::get_x();
}

double Piranha::get_y() {
	return Moveable::get_y();
}


/*------------------------------------------------------------
							Method 
------------------------------------------------------------*/	

void Piranha::draw() {
	// draw piranha on screen 

	if (Fish::isHungry()) {
		if (Moveable::get_dir() == "Left") {
			draw_image(FILE_piranha_left_hungry, Moveable::get_x(), Moveable::get_y()); 
		}
		else {
			draw_image(FILE_piranha_right_hungry, Moveable::get_x(), Moveable::get_y());	
		}
	}
	else {
		if (Moveable::get_dir() == "Left") {
			draw_image(FILE_piranha_left, Moveable::get_x(), Moveable::get_y()); 
		}
		else {
			draw_image(FILE_piranha_right, Moveable::get_x(), Moveable::get_y());	
		}
	}
}

int Piranha::findGuppy(LinkedList<Guppy>& G) {

	int idx = 1;
	int i = 2; //indeks perbandingan mulai dari 2

	while (i<=G.getNBelmt()) {
		if (euclidean(G.get(idx) > euclidean(G.get(i)))) {
			idx = i;
		}
		else {
			idx++;
		}
	}
	return idx;
}

void Piranha::move(double sec_since_last,LinkedList<Guppy>& G) {

	double x;
	double y;

	if (Fish::isHungry()) {
		//mengejar food pakai tips
		int idx = findGuppy(G);
		double a = atan2(G.get(idx).get_x()-get_x(), G.get(idx).get_y()-get_y());
		set_x(get_x()+Fish::get_speed()*cos(a)*sec_since_last);
		set_y(get_y()+Fish::get_speed()*sin(a)*sec_since_last);
	}

	else {
		if (Fish::get_time_move() == 0 || get_x() == SCREEN_LEFT || get_y() == SCREEN_TOP || get_x() == SCREEN_RIGHT || get_y() == SCREEN_BOTTOM) {
			Fish::set_time_move(FISH_MAX_TIMER);
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
		}
		else {
			Fish::set_time_move(Fish::get_time_move()-FISH_TIMER_DEC);
		}
		if ((get_x() > SCREEN_LEFT) && (get_x() < SCREEN_RIGHT) && (get_y() > SCREEN_TOP) && (get_y() < SCREEN_BOTTOM)) {
			set_x(get_x()+Fish::get_speed()*sec_since_last*x);
			set_y(get_y()+Fish::get_speed()*sec_since_last*y);
		}
		else {
			if (get_x() == SCREEN_LEFT) {
				set_x(get_x()+Fish::get_speed()*sec_since_last);	
			}
			else if (get_x() == SCREEN_RIGHT) {
				set_x(get_x()-Fish::get_speed()*sec_since_last);	
			}
			if (get_y() == SCREEN_TOP) {
				set_y(get_y()+Fish::get_speed()*sec_since_last);	
			}
			else if (get_y() == SCREEN_BOTTOM) {
				set_y(get_y()-Fish::get_speed()*sec_since_last);	
			}
		}
	}
}

double Piranha::euclidean(Guppy &g) {

	double x_piranha = get_x();
	double y_piranha = get_y();
	double x_guppy = g.get_x(); 
	double y_guppy = g.get_y();

	return (sqrt(pow(x_piranha-x_guppy, 2)) + (pow(y_piranha-y_guppy, 2)));
}

bool Piranha::inRadius(LinkedList<Guppy> &G) {

	int idx = 1;
	double radius = 1;
	bool find = false;
	
	while (!find && i<G.getNBelmt()) {
		if (radius > euclidean(G.get(idx))) {
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

int eat(LinkedList<Guppy> &G) {

	int idx = inRadius();

	// found
	if (idx != -999) {

		// get eaten guppy lvl
		int guppy_lv = G.get(idx).get_level();

		// remove guppy from list
		G.remove(G.get(idx));

		// set hunger to max and state is hungry to false
		Fish::fullHunger();
		Fish::setHungry(false);
		
		return guppy_lv;
	}

	// not eating anything
	else {

		return -1;
	}
}


























//approach guppy or random move
void Piranha::move() {

}
		
// draw on screen (GUI)
void Piranha::draw() {
	if (Moveable::get_dir() == "Left") {
		draw_image("piranhaLeft.png", Movable::get_x(), Movable::get_y());
	}
	else {
		draw_image("piranhaRight.png", Movable::get_x(), Movable::get_y());
	}
}
		
//produce after eat
bool Piranha::produce_coin() {
	status = false;
	if (Fish::get_hungry() == false) { //if kenyang then produce coin
		return true;
	}
	else {
		return false;
	}
} 
		
//eat guppy
void Piranha::eat() {
	if (Fish::getHungry()) {
		bool find = false;
		//find guppy
		if (find) {
			Fish::fullHunger();
			Fish::setHungry(false);
		}
		else {

		}
	}
} 

bool Piranha::findGuppy(LinkedList<Guppy> G) {
	//nyari dalam radius brp
	
}

/*		
// check hunger condition
bool Piranha::isFull() {
	if (get_hunger() == get_maxHunger()) {
		return true;
	}
	else {
		return false;
	}
}
*/