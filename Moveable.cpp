#include "Moveable.h"
using namespace std;
/*------------------------------------------------------------
                        Getter	Setter
------------------------------------------------------------*/

double Moveable::get_x() {
    return position_x;
}
double Moveable::get_y() {
    return position_y;
}
string Moveable::get_dir() {
    return direction;
}

void Moveable::set_x(double x) {
    position_x = x;
}
void Moveable::set_y(double y) {
    position_y = y;
}
void Moveable::set_dir(string dir) {
    direction = dir;
}