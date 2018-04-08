#ifndef FOOD_H
#define FOOD_H

#include "Object.h"
#include "Moveable.h"
using namespace std;

class Food : public Object, Moveable{
	
	public:
	
		/*------------------------------------------------------------
			 				Constructor & Destructor 	
		------------------------------------------------------------*/
	    
		Food();
	    ~Food();
	    
	    /*------------------------------------------------------------
							 	Getter	Setter
		------------------------------------------------------------*/
		
		int get_id();
		int get_value();
		
		void set_value();
		
		/*------------------------------------------------------------
									Method 	
		------------------------------------------------------------*/
		
	    void draw();
	    void remove();
	    void move(double);

  	private:
  		
  		int food_id;
    	int food_type;
    	int food_value;
	
	
};


#endif
