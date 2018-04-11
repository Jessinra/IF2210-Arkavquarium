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
#include "Constant.h"


// const int guppy_price = 50;
// const int piranha_price = 250;
// const int food_price = 2;
// const int egg_price = 4000;
// const int siput_price = 1250;

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
		
		/*------------------------------------------------------------
								Class Method	
		------------------------------------------------------------*/
		
		// draw on screen (GUI)
		void draw();	
		
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

		// Method to create new guppy
		// method to run by main
		void buy_guppy();

		// Method to create new piranha
		// method to run by main
		void buy_piranha();

		// Method to add food to tank
		// method to run by main
		void buy_food();
		void buy_food(double x);

		// Method to buy egg
		// method to run by main
		void buy_egg();

		// Method to create siput
		// method to run by main
		void buy_snail();
		
		// method for clicking coin 
		double euclidean(double,double,Coin);
		int inRadius(double,double);
		int click_coin(double,double);

		// save and load
		void save() {
			FILE *file = fopen("savefile", "wb");
			if (file != NULL) {
				fwrite(this, sizeof(Aquarium), 1, file);
				fclose(file);
			}
		}
		void load() {
			FILE *file = fopen("savefile", "rb");
			if (file != NULL) {
				fread(this, sizeof(Aquarium), 1, file);
				fclose(file);
			}
		}

	private:

		// List of objects in aquarium	
		LinkedList<Guppy> list_guppy;
		LinkedList<Piranha> list_piranha;
		LinkedList<Siput> list_siput;
		LinkedList<Food> list_food;
		LinkedList<Coin> list_coin;
			
};


#endif