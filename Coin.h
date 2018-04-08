#ifndef COIN_H
#define COIN_H

#include "Object.h"
#include "Moveable.h"

using namespace std;

class Coin : public Object, Moveable {
	
	public:

		static int coin_amount;
		/*------------------------------------------------------------
			 				Constructor & Destructor 	
		------------------------------------------------------------*/
		Coin();

		Coin(int x, int y, int value);
		
		/*------------------------------------------------------------
							 	Getter	Setter
		------------------------------------------------------------*/
		
		int get_id();
		int get_value();
		
		/*------------------------------------------------------------
									Method  
		------------------------------------------------------------*/
		
		void draw();
		void remove();
		void move(double);
	
	private:
		int coin_id;
		int coin_value;

};

#endif
