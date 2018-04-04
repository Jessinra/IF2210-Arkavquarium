#ifndef COIN_H
#define COIN_H

#include "Object.h"
#include "Moveable.h"
using namespace std;

class Coin : public Object, Moveable {
	
	public:
		
		/*------------------------------------------------------------
			 				Constructor & Destructor 	
		------------------------------------------------------------*/
		
		Coin();
		~Coin();
		
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
		void move();
	
	private:
		
		int coin_id;
		int coin_value;
};

#endif
