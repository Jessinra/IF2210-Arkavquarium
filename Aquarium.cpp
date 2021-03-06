#include "Aquarium.h"
#include <iostream>

using namespace std;

int Aquarium::egg = 0;
int Aquarium::money = 20000;

Aquarium::Aquarium() {
	Guppy *g = new Guppy();
	Guppy *g1 = new Guppy();
	list_guppy.add(*g);
	list_guppy.add(*g1);
	Siput *s = new Siput();
	list_siput.add(*s);
}

Aquarium::~Aquarium(){

}

LinkedList<Guppy>& Aquarium::get_list_guppy(){
	return list_guppy;
}

LinkedList<Piranha>& Aquarium::get_list_piranha(){
	return list_piranha;
}

LinkedList<Siput>& Aquarium::get_list_siput(){
	return list_siput;
}

LinkedList<Food>& Aquarium::get_list_food(){
	return list_food;
}

LinkedList<Coin>& Aquarium::get_list_coin(){
	return list_coin;
}

// draw on screen (GUI)
void Aquarium::draw(){
	
	draw_image(FILE_aquarium, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	
	for (int i = 1; i <= list_guppy.getNBelmt(); i++){
		list_guppy.get(i).draw();
	}

	for (int i = 1; i <= list_piranha.getNBelmt(); i++){
		list_piranha.get(i).draw();
	}

	cout << "drawsiput" << endl;
	for (int i = 1; i <= list_siput.getNBelmt(); i++){
		list_siput.get(i).draw();
	}

	for (int i = 1; i <= list_food.getNBelmt(); i++){
		list_food.get(i).draw();
	}

	for (int i = 1; i <= list_coin.getNBelmt(); i++){
		list_coin.get(i).draw();
	}

	cout << "draw" << endl;

	// draw aquarium
	

	// tampilin uang
	// tampilin telur
	// tampilin button yang dapat digunakan
}


// Method to add guppy to tank 
// called by guppy.create() 
void Aquarium::add_guppy(Guppy& guppy) {
	list_guppy.add(guppy);
}

// Method to remove guppy from list of piranha
// called by guppy.die() 
void Aquarium::remove_guppy(Guppy& guppy) {
	list_guppy.remove(guppy);
}

// Method to add piranha to tank 
// called by piranha.create() 
void Aquarium::add_piranha(Piranha& piranha) {
	list_piranha.add(piranha);
}

// Method to remove piranha from list of piranha
// called by piranha.die() 
void Aquarium::remove_piranha(Piranha& piranha) {
	list_piranha.remove(piranha);
}


// Method to add Siput to tank
// called by Siput.create()
void Aquarium::add_siput(Siput& siput){
	list_siput.add(siput);
}

// Method to remove Siput from list of Siput
// called by Siput.die() // just in case needed it
void Aquarium::remove_siput(Siput& siput){
	list_siput.remove(siput);
}

// Method to add food to tank
// called by food.create()
void Aquarium::add_food(Food& food){
	list_food.add(food);
}

// Method to remove food from tank
// called by food.consumed(), food.touch_bottom() 
void Aquarium::remove_food(Food& food){
	list_food.remove(food);
}

// Method called to add coin to tank 
// called by fish.drop_coin()
void Aquarium::add_coin(Coin& coin){
	list_coin.add(coin);
}

// Method to remove coin from list of coin
// called by Siput.collect_coin(), coin.touch_bottom()
void Aquarium::remove_coin(Coin& coin){
	list_coin.remove(coin);
}

void Aquarium::buy_guppy(){

	// Money sufficient 
	if (Aquarium::money >= GUPPY_PRICE){

		Guppy *g = new Guppy();
		cout << g -> get_x() << " " << g -> get_y() << "******** posisi GUPPY" << endl;
		add_guppy(*g);

		Aquarium::money -= GUPPY_PRICE;

	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}
}


void Aquarium::buy_piranha(){

	// Money sufficient 
	if (Aquarium::money >= PIRANHA_PRICE){

		Piranha *p = new Piranha();
		cout << p -> get_x() << " " << p -> get_y() << "******** posisi PIRANHA" << endl;
		add_piranha(*p);

		Aquarium::money -= PIRANHA_PRICE;

	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}
}


void Aquarium::buy_food(){

	// Money sufficient 
	if (Aquarium::money >= FOOD_PRICE){
		
		Food *f = new Food();
	    add_food(*f);

	    Aquarium::money -= FOOD_PRICE;
	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}
}

void Aquarium::buy_food(double x) {
	// Money sufficient 
	if (Aquarium::money >= FOOD_PRICE){
		
		Food *f = new Food(x);
	    add_food(*f);

	    Aquarium::money -= FOOD_PRICE;
	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}
}


void Aquarium::buy_egg(){

	// Money sufficient 
	if (Aquarium::money >= EGG_PRICE){
		
		Aquarium::egg++;
		Aquarium::money -= EGG_PRICE;
	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}


}


void Aquarium::buy_snail(){

	// Money sufficient 
	if (Aquarium::money >= SIPUT_PRICE){

		Siput *s = new Siput();
        add_siput(*s);

	    Aquarium::money -= SIPUT_PRICE;
	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}

}


double Aquarium::euclidean(double x, double y, Coin c) {
    // get euclidean distance to coin

    double x_coin = c.get_x();
    double y_coin = c.get_y();

    return (sqrt(pow(x-x_coin, 2)) + (pow(y-y_coin, 2)));
}


int Aquarium::inRadius(double x, double y) {
    
    int idx = 1;
    int nearest;
    double radius = 1;

	nearest = get_list_coin().get(idx).get_x();
	while (idx+1 < get_list_coin().getNBelmt()) {
	    if (euclidean(x,y,get_list_coin().get(idx)) < nearest) {
		    nearest = euclidean(x,y,get_list_coin().get(idx));
		    radius = idx;
		}
	    else {
			idx++;
	    }
	}
    
    // return id coin yg di dalam radius
    return radius;
}


int Aquarium::click_coin(double x, double y) {
    //find coin in radius
    if (get_list_coin().getNBelmt() > 0) {
        int idx = inRadius(x,y);
        if (get_list_coin().get(idx).get_x() >= x - 30 && get_list_coin().get(idx).get_x() <= x + 30 && get_list_coin().get(idx).get_y() >= y-30 && get_list_coin().get(idx).get_y() <= y+30) {
            int value = get_list_coin().get(idx).get_value();
            get_list_coin().remove(get_list_coin().get(idx));
            return value;
        } else {
			return 0;
		}
    } else {
		return 0;
	}
}