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
	
	int get_price();
	
	int get_coin_value();

	void set_coin_value(int cvalue);

	double get_hunger();
	
	int get_speed();

	bool get_hungry();

	void set_hungry(bool status);

	const int get_max_hunger();
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		//habis makan, hunger full lagi
		void fullHunger();
		
		//decrease hunger 1 per timeframe
		void makeHungry();

		//return true kalau lapar
		void isHungry();

		//return true if ikan mati
		bool isDead();

  	private:
  		
  		int fish_id;
	  	int fish_price;
	    int coin_value;
	    double hunger;
	    int speed;
	    bool hungry;

	    static int fish_count; //jumlah ikan

	    const int max_hunger = 20;
  	
  	
    
};

#endif