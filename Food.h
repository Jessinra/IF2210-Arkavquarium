#ifndef FOOD_H
#define FOOD_H

#include "Object.h"
#include "Moveable.h"

#include "Constant.h"

using namespace std;

class Food : public Object, public Moveable{

	public:

		/*------------------------------------------------------------
			 				Constructor & Destructor
		------------------------------------------------------------*/

		Food();
		Food(double x);
    	
	    /*------------------------------------------------------------
							 	Getter	Setter
		------------------------------------------------------------*/

		int get_id();
		void set_id(int);

		// int get_type();
		// int get_value();

		// void set_value(int x);

		int get_speed();
		void set_speed(int);

		/*------------------------------------------------------------
									Method
		------------------------------------------------------------*/

	    void draw();
	    void move(double);

		bool operator==(Food&);
		bool operator!=(Food&);		

  	private:

  		int food_id;
    	// int food_type;
    	// int food_value;
  		int food_speed;

    	static int food_count;


};


#endif
