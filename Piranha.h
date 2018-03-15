#ifndef PIRANHA_H
#define PIRANHA_H

#include "Fish.h"
using namespace std;

class Piranha : public Fish {
	
	public:
		
	  	/*------------------------------------------------------------
						Constructor & Destructor 	
		------------------------------------------------------------*/	
		
		Piranha();
		~Piranha();
		Piranha(const Piranha& );
		Piranha& operator=(const Piranha& );
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		
		//approach guppy or random move
		void move();
		
		// draw on screen (GUI)
		void draw();
		
		//produce after eat
		void produce_coin(); 
		
		//eat guppy
		void eat(); 
		
		// check hunger condition
		bool isFull();
};

#endif
