#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "Object.h"
#include "Guppy.h"
#include "Piranha.h"
#include "Pet.h"
#include "Siput.h"
#include "Food.h"
#include "Coin.h"
#include "LinkedList.h"

#include "Lib/oop.hpp"

using namespace std;

class Aquarium : public Object{
	
	public:
		
		static int money;
		static int egg;
		
		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
		
		Aquarium();
		~Aquarium();
		
		/*------------------------------------------------------------
									Getter	
		------------------------------------------------------------*/
		
		LinkedList<Guppy>& get_list_guppy();
		LinkedList<Piranha>& get_list_piranha();
		LinkedList<Siput>& get_list_siput();
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
	 	
		// Method to add guppy to tank 
		// called by guppy.create() 
		void add_guppy(Guppy& guppy);
		
		// Method to remove guppy from list of piranha
		// called by guppy.die() 
		void remove_guppy(Guppy& guppy);
		
		// Method to add piranha to tank 
		// called by piranha.create() 
		void add_piranha(Piranha& piranha);
		
		// Method to remove piranha from list of piranha
		// called by piranha.die() 
		void remove_piranha(Piranha& piranha);
		
		// Method to add pet to tank
		// called by pet.create()
		void add_siput(Siput& siput);
		
		// Method to remove pet from list of pet
		// called by pet.die() // just in case needed it
		void remove_siput(Siput& siput);
		
		// Method to add food to tank
		// called by food.create()
		void add_food(Food& food);
		
		// Method to remove food from tank
		// called by food.consumed(), food.touch_bottom() 
		void remove_food(Food& food);
		
		// Method called to add coin to tank 
		// called by guppy.drop_coin()
		void add_coin(Coin& coin);
		
		// Method to remove coin from list of coin
		// called by pet.collect_coin(), coin.touch_bottom()
		void remove_coin(Coin& coin);


		void main_loop();

		void generate_coins();
		
		
	private:

		// List of objects in aquarium	
		LinkedList<Guppy> list_guppy;
		LinkedList<Piranha> list_piranha;
		LinkedList<Siput> list_siput;
		LinkedList<Food> list_food;
		LinkedList<Coin> list_coin;
			
};


#endif