#include "LinkedList.h"
#include "Constant.h"
#include "Coin.h"
#include "Siput.h"
#include "Lib/oop.hpp"
#include <iostream>
using namespace std;

Siput::Siput() {
    distance_to_coin = 0;
    set_speed(SIPUT_MOVEMENT_SPD);
    Moveable::set_dir("Right");
    Moveable::set_x(SCREEN_WIDTH/2);
    Moveable::set_y(SCREEN_BOTTOM);
}

int Siput::get_speed() {
    return speed;
}

void Siput::set_speed(int x) {
    speed = x;
}

void Siput::draw() {

    // draw siput on screen
    if (Moveable::get_dir() == "Left"){
        draw_image(FILE_siput_left, get_x(), get_y());
    } else {
        draw_image(FILE_siput_right, get_x(), get_y());
    }
}

void Siput::move(double sec_since_last, LinkedList<Coin>& C) {

    int x_siput = Moveable::get_x();
    int x_coin;
    int radius = inRadius(C);

    cout << "siput move " << Moveable::get_x() << "," << Moveable::get_y() << endl;
    x_coin = C.get(radius).get_x();
    for (int i=0; i<x_coin; i++) {
	set_x(x_siput*sec_since_last*(i/100));
    }

    /*
    if (inRadius(C) != -999) {
        cout << C.getNBelmt() << endl;
        // get the x value of nearest coin
        if (C.getNBelmt() > 0) {
	    // idx = id coin yg menjadi target
            int idx = inRadius(C);
            cout << "siput move " << Moveable::get_x() << "," << Moveable::get_y() << endl;

	    
            // set siput x , to
            double a = atan2(C.get(idx).Moveable::get_x() - Moveable::get_x(), C.get(idx).Moveable::get_y() - Moveable::get_y());
	    
	    Moveable::set_x(Moveable::get_x() - get_speed() * cos(a) * sec_since_last);			    
            cout << "siput move " << Moveable::get_x() << "," << Moveable::get_y() << endl;
	   
        }
    }
    */
}

double Siput::euclidean(Coin c) {
    // get euclidean distance to coin

    double x_siput = get_x();
    double y_siput = get_y();
    double x_coin = c.get_x();
    double y_coin = c.get_y();

    return (sqrt(pow(x_siput-x_coin, 2)) + (pow(y_siput-y_coin, 2)));
}

int Siput::inRadius(LinkedList<Coin>& C) {
    
    int idx = 1;
    int nearest;
    double radius = 1;
    bool find = false;

    if (find_coin(C) == true) {
	// there's coin on screen_bottom
	nearest = C.get(idx).get_x();
	while (idx+1 < C.getNBelmt()) {
	    if (C.get(idx).get_x() == SCREEN_BOTTOM) {
		// kalo ada beberapa yg di bottom, cari yg terdekat
		if (abs(C.get(idx).get_x() - get_x()) < nearest) {
		    nearest = abs(C.get(idx).get_x() - get_x());
		    radius = idx;
		}
	    } else {
		idx++;
	    }
	}
    } else {
	// no coin on screen_bottom
	nearest = C.get(idx).get_y();
	for (idx=2; idx < C.getNBelmt(); idx++) {
	    // cari coin yg terdekat dengan tanah dg ngukur y
	    if (C.get(idx).get_y() > nearest) {
		radius = idx;
	    }
	}

    }
    // return id coin yg di dalam radius
    return radius; 
   
}

bool Siput::find_coin (LinkedList<Coin>& C) {
    // iterate in list Coin for nearest coin on screen bottom

    bool find = false;
    int i = 1;

    while (i < C.getNBelmt() && !find) {
        if (C.get(i).get_y() == SCREEN_BOTTOM) {
	    find = true;
	} else {
	    i++;        
	}	
    }

    // return x position of coin in radius
    return find;

}

int Siput::take_coin(LinkedList<Coin>& C) {
    //find coin in radius
    int idx = inRadius(C);

    if (idx != -999) {
        //remove coin from list
        C.remove(C.get(idx));
        return C.get(idx).get_value();
    } else {
        return 0;
    }
}

Siput& Siput::operator=(Siput& s) {
    set_speed(SIPUT_MOVEMENT_SPD);
    set_dir(s.get_dir());
    distance_to_coin = s.distance_to_coin;

    return *this;
}

bool Siput::operator==(Siput& s) {
    return get_id() == s.get_id();
}

bool Siput::operator!=(Siput& s) {
    return get_id() != s.get_id();
}
