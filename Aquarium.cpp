#include "Aquarium.h"

using namespace std;

Aquarium::egg = 0;
Aquarium::money = 200;

Aquarium::Aquarium() {
	Guppy *g = new Guppy();
	list_guppy.add(*g);
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
	for (int i = 1; i <= list_guppy.getNBelmt(); i++){
		list_guppy.get(i).draw();
	}

	for (int i = 1; i <= list_piranha.getNBelmt(); i++){
		list_piranha.get(i).draw();
	}

	LinkedList<Siput> list_siput = get_list_siput();
	for (int i = 1; i <= list_siput.getNBelmt(); i++){
		list_siput.get(i).draw();
	}

	LinkedList<Food> list_food = get_list_food();
	for (int i = 1; i <= list_food.getNBelmt(); i++){
		list_food.get(i).draw();
	}

	LinkedList<Coin> list_coin = get_list_coin();
	for (int i = 1; i <= list_coin.getNBelmt(); i++){
		list_coin.get(i).draw();
	}

	// draw aquarium also
	// tampilin uang
	// tampilin telur
	// tampilin button yang dapat digunakan
}

// Method to remove object (calling destructor)
void Aquarium::remove() {

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

	int guppy_price = 50;

	// Money sufficient 
	if (Aquarium::money >= guppy_price){

		Guppy *g = new Guppy();
		add_guppy(*g);

		Aquarium::money -= guppy_price;

	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}
}


void Aquarium::buy_piranha(){

	// Money sufficient 
	if (Aquarium::money >= piranha_price){

		Piranha *p = new Piranha();
		add_piranha(*p);

		Aquarium::money -= piranha_price;

	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}
}


void Aquarium::buy_food(){

	// Money sufficient 
	if (Aquarium::money >= food_price){
		
		Food *f = new Food();
	    add_food(*f);

	    Aquarium::money -= food_price;
	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}
}


void Aquarium::buy_egg(){

	// Money sufficient 
	if (Aquarium::money >= egg_price){
		
		Aquarium::egg++;
		Aquarium::money -= egg_price;
	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}


}


void Aquarium::buy_snail(){

	// Money sufficient 
	if (Aquarium::money >= siput_price){

		Siput *s = new Siput();
        add_siput(*s);

	    Aquarium::money -= siput_price;
	}

	// unsufficient money
	else{
		cout << "money not enough" << endl;
	}

}