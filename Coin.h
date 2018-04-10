#ifndef COIN_H
#define COIN_H

#include "Object.h"
#include "Moveable.h"
#include "Constant.h"

using namespace std;

class Coin : public Object, public Moveable {
	
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

		void set_id(int);

		int get_value();

		void set_value(int);

		int get_speed();
		
		void set_speed(int);

		/*------------------------------------------------------------
									Method  
		------------------------------------------------------------*/
		
		void draw();
		void remove();
		void move(double);

		/**** operator overloading ****/
		Coin& operator=(Coin&);
		bool operator==(Coin&);
		bool operator!=(Coin&);
	
	private:
		int coin_id;
		int coin_value;
		int coin_speed;

};

#endif
