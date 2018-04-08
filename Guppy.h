#ifndef GUPPY_H
#define GUPPY_H

#include "Fish.h"
#include "Food.h"
#include "Aquarium.h"
#include "LinkedList.h"
using namespace std;

class Guppy : public Fish {
	
	public:
		
	  	/*------------------------------------------------------------
						Constructor & Destructor 	
		------------------------------------------------------------*/
		
	    Guppy();
	    
		/*------------------------------------------------------------
									Getter  
		------------------------------------------------------------*/
		
		int get_level();
		
		void set_level(int);
		
		int get_number_eat();

		int set_number_eat(int);

		int get_timer();

		void set_timer();

		const int get_max_level();
		/*------------------------------------------------------------
								Method  	
		------------------------------------------------------------*/
		
	    void draw();
	    bool produce_coin();
	    int findFood(LinkedList<Food> F);
	    void move(double sec_since_last,LinkedList<Food> F);
	    double euclidean(Food m);
	    bool inRadius(LinkedList<Food> F);
	    void eat(LinkedList<Food>& F);
	    void grow();
	
	
	private:
		int number_eat;
	    int level_grow;
	    double timer; //guppy mengeluarkan uang setelah bbrp detik
	    const int max_level=3;
};

#endif