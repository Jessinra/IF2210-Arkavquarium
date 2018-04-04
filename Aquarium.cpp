
#include "Aquarium.h"

using namespace std;

Aquarium(){

	draw();
	main_loop();

}

~Aquarium();

LinkedList<Fish>& Aquarium::get_list_fish(){

	return list_fish;
}

LinkedList<Pet>& Aquarium::get_list_pet(){

	return list_pet;
}

LinkedList<Food>& Aquarium::get_list_food(){

	return list_food;
}

LinkedList<Coin>& Aquarium::get_list_coin(){

	return list_coin;
}




// draw on screen (GUI)
void Aquarium::draw(){


	LinkedList<Fish> list_fish = get_list_fish();
	for (int i = 1; i <= list_fish.getNBelmt(); i++){

		list_fish[i].draw();
	}

	LinkedList<Pet> list_pet = get_list_pet();
	for (int i = 1; i <= list_pet.getNBelmt(); i++){

		list_pet[i].draw();
	}

	LinkedList<Pet> list_food = get_list_food();
	for (int i = 1; i <= list_food.getNBelmt(); i++){

		list_food[i].draw();
	}

	LinkedList<Pet> list_coin = get_list_coin();
	for (int i = 1; i <= list_coin.getNBelmt(); i++){

		list_coin[i].draw();
	}
	

}

// Method to remove object (calling destructor)
void Aquarium::remove();	
		
	
// Method to add fish to tank 
// called by fish.create() 
void Aquarium::add_fish(Fish& fish){
	// if certain button is clicked ()

	LinkedList<Fish> list = get_list_fish();
	list.add(fish);

}

// Method to remove fish from list of fish 
// called by fish.die() 
void Aquarium::remove_fish(LinkedList<Fish>& list_of_fish, Fish fish){

	LinkedList<Fish> list = get_list_fish();
	list.remove(fish);
}

// Method to add pet to tank
// called by pet.create()
void Aquarium::add_pet(Pet& pet){

	LinkedList<Pet> list = get_list_pet();
	list.add(pet);
}

// Method to remove pet from list of pet
// called by pet.die() // just in case needed it
void Aquarium::remove_pet(LinkedList<Pet>& list_of_pet, Pet pet){

	LinkedList<Pet> list = get_list_pet();
	list.remove(pet);
}

// Method to add food to tank
// called by food.create()
void Aquarium::add_food(Food& food){

	LinkedList<Food> list = get_list_food();
	list.add(food);
}

// Method to remove food from tank
// called by food.consumed(), food.touch_bottom() 
void Aquarium::remove_food(LinkedList<Food>& list_of_food, Food food){

	LinkedList<Food> list = get_list_food();
	list.remove(food);
}

// Method called to add coin to tank 
// called by fish.drop_coin()
void Aquarium::add_coin(Coin& coin){

	LinkedList<Coin> list = get_list_coin();
	list.add(coin);
}

// Method to remove coin from list of coin
// called by pet.collect_coin(), coin.touch_bottom()
void Aquarium::remove_coin(LinkedList<Coin>& list_of_coin, Coin coin){

	LinkedList<Coin> list = get_list_coin();
	list.remove(coin);
}