#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "wtypes.h" // for GetDesktopResolution()
#include "Object.h"
using namespace std;

class Aquarium : public Object{
	
	public:
		
		// Constructor & Destructor aquarium
		Aquarium();
		~Aquarium();
		
		/*------------------------------------------------------------
							Method from abstract class	
		------------------------------------------------------------*/
		// draw on screen (GUI)
		void draw();	
		
		// Method to remove object (calling destructor)
	 	void remove();	
		 
		// Method to move object 
	 	void move();		
		
		/*------------------------------------------------------------
							Class Method	
		------------------------------------------------------------*/
		
		// Method to add fish to tank 
		// called by fish.create() 
		void add_fish(Fish& fish);
		
		// Method to remove fish from list of fish 
		// called by fish.die() 
		void remove_fish(List<Fish>& list_of_fish, int fish_id);
		
		// Method to add pet to tank
		// called by pet.create()
		void add_pet(Pet& pet);
		
		// Method to remove pet from list of pet
		// called by pet.die() // just in case needed it
		void remove_pet(List<Pet>& list_of_pet, int pet_id);
		
		// Method to add food to tank
		// called by food.create()
		void add_food(Food& food);
		
		// Method to remove food from tank
		// called by food.consumed(), food.touch_bottom() 
		void remove_food(List<Food>& list_of_food, int food_id);
		
		// Method called to add coin to tank 
		// called by fish.drop_coin()
		void add_coin(Coin& coin);
		
		// Method to remove coin from list of coin
		// called by pet.collect_coin(), coin.touch_bottom()
		void remove_coin(List<Coin>& list_of_coin, int coin_id);
		
		
		
		
		
		
	private:
		int screen_width, screen_height;
		
		// Matrix of water (?)
		Object ** aquarium;	
		
		// List of objects in aquarium	
		List<Fish> list_fish;
		List<Pet> list_pet;
		List<Food> list_food;
		List<Coin> List_coin;
			
		// Method to get desktop resolution for windows
		void GetDesktopResolution(int& screen_width, int& screen_height);
};


#endif
