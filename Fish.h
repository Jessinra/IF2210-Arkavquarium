#ifndef FISH_H
#define FISH_H

#include "Object.h"
#include "Food.h"
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
		
	int Fish::get_id();
	
	int Fish::get_price();
	
	int Fish::get_coin_value();

	void set_coin_value(int cvalue);

	double Fish::get_hunger();
	
	int Fish::get_speed();

	bool Fish::get_hungry();

	void Fish::set_hungry(bool status);

	const int get_max_hunger();
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		//habis makan, hunger full lagi
		void Fish::fullHunger();
		
		//decrease hunger 1 per timeframe
		void Fish::makeHungry();

		//return true kalau lapar
		void Fish::isHungry();

		//return true if ikan mati
		bool Fish::isDie();

		// draw on screen (GUI)
	    virtual void draw();
	    
	    // merubah posisi x y ikan, mendekati makanan / bergerak bebas
	    virtual void move() = 0;
	    
	    // membuat object coin dan memanggil aquarium.add_coin(coin&)
	    virtual void produce_coin() = 0;
	    
	    // menambah hunger dan memanggil aquarium.remove_food(food&)
	    virtual void eat() = 0;

  	protected:
  		
  		int fish_id;
	  	int fish_price;
	    int coin_value;
	    double hunger;
	    int speed;
	    bool hungry;

	    static int fish_count; // jumlah ikan

	    const int max_hunger = 20;
  	
  	
    
};

#endif