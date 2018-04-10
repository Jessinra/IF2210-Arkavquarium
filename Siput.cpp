#include "LinkedList.h"
#include "Siput.h"
#include "Lib/oop.hpp"
#include <iostream>
using namespace std;

Siput::Siput() {
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
    cout << "siput move " << Moveable::get_x() << "," << Moveable::get_y() << endl;
    if (inRadius(C) != -999) {
        cout << C.getNBelmt() << endl;
        // get the x value of nearest coin
        if (C.getNBelmt() > 0) {
            int idx = inRadius(C);
            cout << "siput move " << Moveable::get_x() << "," << Moveable::get_y() << endl;
            // set siput x , to
            double a = atan2(C.get(idx).Moveable::get_x() - Moveable::get_x(), C.get(idx).Moveable::get_y() - Moveable::get_y());
            Moveable::set_x(Moveable::get_x() - get_speed() * cos(a) * sec_since_last);
            cout << "siput move " << Moveable::get_x() << "," << Moveable::get_y() << endl;
        }
    }
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
    double radius = 1;
    bool find = false;

    while (!find && idx < C.getNBelmt()) {

        if (radius < euclidean(C.get(idx))) {
            find = true;
        } else {
            idx++;
        }
    }
    if (find) {
        return idx;
    } else {
        return -999;
    }
}

int Siput::find_coin(LinkedList<Coin>& C) {
    int x = Moveable::get_x();
    int y = Moveable::get_y();

    int idx = 1;
    int i = 2;

    while (i < C.getNBelmt()) {
        if (euclidean(C.get(idx)) > euclidean(C.get(i))) {
            idx = i;
        } else {
            i++;
        }
    }
    return idx;
}

int Siput::take_coin(LinkedList<Coin>& C) {
    //find coin in radius
    int idx = inRadius(C);

    if (idx != -999) {
        //remove coin from list
        int value = C.get(idx).get_value();
        C.remove(C.get(idx));
        return value;
    } else {
        return 0;
    }
}

Siput& Siput::operator=(Siput& s) {
    set_speed(SIPUT_MOVEMENT_SPD);
    set_dir(s.get_dir());

    return *this;
}

bool Siput::operator==(Siput& s) {
    return get_id() == s.get_id();
}

bool Siput::operator!=(Siput& s) {
    return get_id() != s.get_id();
}
