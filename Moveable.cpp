#include "Moveable.h"
using namespace std;
/*------------------------------------------------------------
                        Getter	Setter
------------------------------------------------------------*/

int Moveable::get_x() {
    return position_x;
}
int Moveable::get_y() {
    return position_y;
}
string Moveable::get_dir() {
    return direction;
}

void Moveable::set_x(int x) {
    position_x = x;
}
void Moveable::set_y(int y) {
    position_y = y;
}
void Moveable::set_dir(string dir) {
    direction = dir;
}