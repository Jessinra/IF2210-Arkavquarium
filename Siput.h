#ifndef SIPUT_H
#define SIPUT_H

#include "Pet.h"
using namespace std;

class Siput : public Pet {
  	public:
  		
   		/*------------------------------------------------------------
			 				Constructor & Destructor 	
		------------------------------------------------------------*/ 		
		
    	Siput();
    	~Siput();
    	
    	/*------------------------------------------------------------
								Getter  Setter
		------------------------------------------------------------*/
		
		int get_distance();
		
		void set_distance();
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/	
	
		void move();
   		void take_coin();

  	private:
  		
    	int distance_to_coin;
};

#endif
