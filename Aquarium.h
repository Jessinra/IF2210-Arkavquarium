<<<<<<< HEAD
#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "wtypes.h" // for GetDesktopResolution()

#include "Object.h"
#include "Fish.h"
#include "Pet.h"
#include "Food.h"
#include "Coin.h"
#include "LinkedList.h"

using namespace std;

class Aquarium : public Object{
	
	public:
		
		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
		
		Aquarium();
		~Aquarium();
		
		/*------------------------------------------------------------
									Getter	
		------------------------------------------------------------*/
		
		LinkedList<Fish>& get_list_fish();
		LinkedList<Pet>& get_list_pet();
		LinkedList<Food>& get_list_food();
		LinkedList<Coin>& get_list_coin();
		
		// get reference to object at aquarium matrix
		Object& get_aquarium(int, int);
		
		// set aquarium tile with object
		void set_aquarium(int, int, Object& );
		
		/*------------------------------------------------------------
							Class Method	
		------------------------------------------------------------*/
		
		// draw on screen (GUI)
		void draw();	
		
		// Method to remove object (calling destructor)
	 	void remove();	
		 
		// Method to move object (???)
	 	void move();
	 	
		// Method to add fish to tank 
		// called by fish.create() 
		void add_fish(Fish& fish);
		
		// Method to remove fish from list of fish 
		// called by fish.die() 
		void remove_fish(LinkedList<Fish>& list_of_fish, int fish_id);
		
		// Method to add pet to tank
		// called by pet.create()
		void add_pet(Pet& pet);
		
		// Method to remove pet from list of pet
		// called by pet.die() // just in case needed it
		void remove_pet(LinkedList<Pet>& list_of_pet, int pet_id);
		
		// Method to add food to tank
		// called by food.create()
		void add_food(Food& food);
		
		// Method to remove food from tank
		// called by food.consumed(), food.touch_bottom() 
		void remove_food(LinkedList<Food>& list_of_food, int food_id);
		
		// Method called to add coin to tank 
		// called by fish.drop_coin()
		void add_coin(Coin& coin);
		
		// Method to remove coin from list of coin
		// called by pet.collect_coin(), coin.touch_bottom()
		void remove_coin(LinkedList<Coin>& list_of_coin, int coin_id);
		
		
	private:
		
		int screen_width, screen_height;
		
		// Matrix of water (?)
		Object ** aquarium;	
		
		// List of objects in aquarium	
		LinkedList<Fish> list_fish;
		LinkedList<Pet> list_pet;
		LinkedList<Food> list_food;
		LinkedList<Coin> list_coin;
			
		// Method to get desktop resolution for windows
		void GetDesktopResolution(int& screen_width, int& screen_height);
};


#endif
=======
#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "wtypes.h" // for GetDesktopResolution()

#include "Object.h"
#include "Fish.h"
#include "Pet.h"
#include "Food.h"
#include "Coin.h"
#include "LinkedList.h"

using namespace std;

class Aquarium : public Object{
	
	public:
		
		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
		
		Aquarium();
		~Aquarium();
		
		/*------------------------------------------------------------
									Getter	
		------------------------------------------------------------*/
		
		LinkedList<Fish>& get_list_fish();
		LinkedList<Pet>& get_list_pet();
		LinkedList<Food>& get_list_food();
		LinkedList<Coin>& get_list_coin();
		
		// get reference to object at aquarium matrix
		Object& get_aquarium(int, int);
		
		// set aquarium tile with object
		void set_aquarium(int, int, Object& );
		
		/*------------------------------------------------------------
							Class Method	
		------------------------------------------------------------*/
		
		// draw on screen (GUI)
		void draw();	
		
		// Method to remove object (calling destructor)
	 	void remove();	
		 
		// Method to move object (???)
	 	void move();		
	 	
		// Method to add fish to tank 
		// called by fish.create() 
		void add_fish(Fish& fish);
		
		// Method to remove fish from list of fish 
		// called by fish.die() 
		void remove_fish(LinkedList<Fish>& list_of_fish, int fish_id);
		
		// Method to add pet to tank
		// called by pet.create()
		void add_pet(Pet& pet);
		
		// Method to remove pet from list of pet
		// called by pet.die() // just in case needed it
		void remove_pet(LinkedList<Pet>& list_of_pet, int pet_id);
		
		// Method to add food to tank
		// called by food.create()
		void add_food(Food& food);
		
		// Method to remove food from tank
		// called by food.consumed(), food.touch_bottom() 
		void remove_food(LinkedList<Food>& list_of_food, int food_id);
		
		// Method called to add coin to tank 
		// called by fish.drop_coin()
		void add_coin(Coin& coin);
		
		// Method to remove coin from list of coin
		// called by pet.collect_coin(), coin.touch_bottom()
		void remove_coin(LinkedList<Coin>& list_of_coin, int coin_id);
		
		
	private:
		
		int screen_width, screen_height;
		
		// Matrix of water (?)
		Object ** aquarium;	
		
		// List of objects in aquarium	
		LinkedList<Fish> list_fish;
		LinkedList<Pet> list_pet;
		LinkedList<Food> list_food;
		LinkedList<Coin> list_coin;
			
		// Method to get desktop resolution for windows
		void GetDesktopResolution(int& screen_width, int& screen_height);
};


#endif
>>>>>>> bc511f3b349d24a52025bed2ce0e4a820919245e
