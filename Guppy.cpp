#include "Guppy.h"
#include <cmath>

using namespace std;

/*------------------------------------------------------------
                    Constructor & Destructor 	
------------------------------------------------------------*/
Guppy::Guppy() {
	int price = 10;
	int cvalue = 2;
	Fish::Fish(price, cvalue);
	level_grow = 1;
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

double Guppy::set_timer() {
	timer = 10;
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
	if (level_grow == 1) {
		if (Moveable::get_dir() == "Left") {
			draw_image("guppy_01.png", Moveable::get_x(), Moveable::get_y());
		}
		else {
			draw_image("guppy_01_r.png", Moveable::get_x(), Moveable::get_y());	
		}
	}
	else if (level_grow == 2) {
		if (Moveable::get_dir() == "Left") {
			draw_image("guppy_02.png", Moveable::get_x(), Moveable::get_y());
		}
		else {
			draw_image("guppy_02_r.png", Moveable::get_x(), Moveable::get_y());	
		}
	}
	else if (level_grow == 3) {
		if (Moveable::get_dir() == "Left") {
			draw_image("guppy_03.png", Moveable::get_x(), Moveable::get_y());
		}
		else {
			draw_image("guppy_03_r.png", Moveable::get_x(), Moveable::get_y());	
		}
	}
}

bool Guppy::produce_coin() {
	status = false;
	if (get_timer() == 0) { //if setelah 10s then produce coin
		return true;
	}
	else {
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
	set_timer(get_timer()-0.5);
	if (Fish::isHungry()) {
		//mengejar food pakai tips
		int idx = findFood(F);
		double a = atan2(F.get(idx).get_x()-get_x(), F.get(idx).get_y()-get_y());
		set_x(get_x()+Fish::get_speed()*cos(a)*sec_since_last);
		set_y(get_y()+Fish::get_speed()*sin(a)*sec_since_last);
	}
	else {
		x = rand() % 640;
		y = rand() % 480;
		if (x>=320) {
			x = 1;
		}
		else {
			x = -1;
		}
		if (y>=240) {
			y = 1;
		}
		else {
			y = -1;
		}
		if ((get_x() > 0) && (get_x() < 640) && (get_y() > 0) && (get_y() < 480)) {
			set_x(get_x()+Fish::get_speed()*sec_since_last*x);
			set_y(get_y()+Fish::get_speed()*sec_since_last*y);
		}
		else {
			if (get_x() == 0) {
				set_x(get_x()+Fish::get_speed()*sec_since_last);	
			}
			else if (get_x() == 640) {
				set_x(get_x()-Fish::get_speed()*sec_since_last);	
			}
			if (get_y() == 0) {
				set_y(get_y()+Fish::get_speed()*sec_since_last);	
			}
			else if (get_y() == 480) {
				set_y(get_y()-Fish::get_speed()*sec_since_last);	
			}
		}
	}
	eat();
}

double euclidean(Food m) {
	double x_guppy = get_x();
	double y_guppy = get_y();
	double x_food = m.get_x(); 
	double y_food = m.get_y();
	return (sqrt(pow(x_guppy-x_food, 2)) + (pow(y_guppy-y_food, 2)));
}

int Guppy::inRadius(LinkedList<Food> F) {
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
	int idx = inRadius();
	if (idx != -999) {
		Fish::fullHunger();
		Fish::setHungry(false);
		set_number_eat(get_number_eat() + 1);
		grow();
		remove(F.get(idx));
	}
	else {

	}
}

void Guppy::grow() {
	if (get_number_eat() == 5 && get_level() != 3) {
		set_level(level_grow+1);
		set_maxHunger(get_maxHunger + 10); //tiap naik level tambah bisa nambah laper
		Fish::set_coin_value(get_coin_value()+2); //tiap naik level tambah harga coin nya
	}
}    