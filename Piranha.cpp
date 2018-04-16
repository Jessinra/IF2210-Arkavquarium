#include "Piranha.h"
#include <cmath>

using namespace std;

/*------------------------------------------------------------
				Constructor & Destructor 	
------------------------------------------------------------*/	
Piranha::Piranha() : Fish(PIRANHA_PRICE, PIRANHA_COIN_VAL) {
	set_speed(PIRANHA_MOVEMENT_SPD);
}

Piranha& Piranha::operator=(Piranha& g) {
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
	set_x_move(g.get_x_move());
	set_y_move(g.get_y_move());

	return *this;
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
		if (G.get(i).get_x() > SCREEN_TOP && G.get(i).get_x() < SCREEN_BOTTOM && G.get(i).get_x() > SCREEN_LEFT && G.get(i).get_x() < SCREEN_RIGHT && euclidean(G.get(idx)) > euclidean(G.get(i))) {
			idx = i;
		}
		else {
			i++;
		}
	}
	return idx;
}

void Piranha::move(double sec_since_last,LinkedList<Guppy>& G) {
	double x;
	double y;
	if (Fish::isHungry() && G.getNBelmt() > 0) {
		//mengejar food pakai tips
		int idx = findGuppy(G);
		if (G.get(idx).get_x() < get_x()) {
			set_dir("Left");
		}
		else {
			set_dir("Right");
		}
		double a = atan2(G.get(idx).get_y()-get_y(), G.get(idx).get_x()-get_x());
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

double Piranha::euclidean(Guppy &g) {

	double x_piranha = get_x();
	double y_piranha = get_y();
	double x_guppy = g.get_x(); 
	double y_guppy = g.get_y();

	return (sqrt(pow(x_piranha-x_guppy, 2)) + (pow(y_piranha-y_guppy, 2)));
}

int Piranha::inRadius(LinkedList<Guppy> &G) {

	int idx = 1;
	double radius = 70;
	bool find = false;
	if (G.getNBelmt() > 0) {
		while (!find && idx<=G.getNBelmt()) {
			if ((radius > abs(get_x()-G.get(idx).get_x())) && (radius > abs(get_y()-G.get(idx).get_y()))) {
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

int Piranha::eat(LinkedList<Guppy> &G) {

	int idx = inRadius(G);

	// found
	if (idx != -999 && Fish::isHungry()) {

		// get eaten guppy lvl
		int guppy_lv = G.get(idx).get_level();

		// remove guppy from list
		G.remove(G.get(idx));

		// set hunger to max and state is hungry to false
		Fish::fullHunger();
		Fish::set_hungry(false);
		
		return guppy_lv;
	}

	// not eating anything
	else {

		return -1;
	}
}

bool Piranha::operator==(Piranha& g) {
	return get_id() == g.get_id();
}

bool Piranha::operator!=(Piranha& g) {
	return get_id() != g.get_id();
}
