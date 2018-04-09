#ifndef FISH_H
#define FISH_H

#include "Object.h"
#include "Coin.h"
#include "Moveable.h"

using namespace std;



class Fish : public Object, Moveable {

	public:
  	
		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
	  	
	  	//ctor
	    Fish(int price, int cvalue);
	    
		/*------------------------------------------------------------
								Getter	Setter
		------------------------------------------------------------*/
		
		int get_id();

		void set_id(int);
		
		int get_price();

		void set_price(int);
		
		int get_coin_value();

		void set_coin_value(int);

		double get_hunger();

		void set_hunger(double);
	
		int get_speed();

		void set_speed(int);

		bool get_hungry();

		void set_hungry(bool);

		const double get_max_hunger();
			
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		//habis makan, hunger full lagi
		void fullHunger();
		
		//decrease hunger 1 per timeframe
		void makeHungry();

		//return true kalau lapar
		bool isHungry();

		//return true if ikan mati
		bool isDead();

  	private:
  		
  		int fish_id;
	  	int fish_price;
	    int coin_value;
	    double hunger;
	    int speed;
	    bool hungry;
	    const double max_hunger = FISH_MAX_HUNGER;

	    static int fish_count; //jumlah ikan

	    
  	
  	
    
};

#endif