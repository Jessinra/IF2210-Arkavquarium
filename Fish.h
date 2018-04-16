#ifndef FISH_H
#define FISH_H

#include "Constant.h"
#include "Object.h"
#include "Coin.h"
#include "Moveable.h"

using namespace std;



class Fish : public Object, public Moveable {

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

		double get_time_move();

		void set_time_move(double);

		int get_x_move();

		void set_x_move(int);

		int get_y_move();

		void set_y_move(int);

		const double get_max_hunger();
		
		void set_max_hunger(double);
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		//habis makan, hunger full lagi
		void fullHunger();
		
		//decrease hunger periodically
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
	    double time_move;
	    int x_move;
	    int y_move;
	    double max_hunger = FISH_MAX_HUNGER;

	    static int fish_count; //jumlah ikan

	    
  	
  	
    
};

#endif
