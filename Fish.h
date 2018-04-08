#ifndef FISH_H
#define FISH_H

#include "Object.h"
#include "Food.h"
#include "Coin.h"
#include "Moveable.h"

using namespace std;

const double hunger_decrease_const = 0.005;

class Fish : public Object, Moveable {

	public:
  	
		/*------------------------------------------------------------
							Constructor & Destructor 	
		------------------------------------------------------------*/
	  	
	  	//ctor
	    Fish();
	    
		//dtor
	    ~Fish();
	    
		//cctor
	    Fish(const Fish&);
	    
		//operator assignment 
	    Fish& operator=(const Fish& );
	    
		/*------------------------------------------------------------
								Getter	Setter
		------------------------------------------------------------*/
		
		int get_id();
		int get_price();
		int get_coin_value();
		double get_hunger();
		int get_speed();
		
		void set_price(int);
		void set_coin_value(int);
		void set_hunger(double);
		void set_speed(int);
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		
		// draw on screen (GUI)
	    virtual void draw();
	    
	    void remove();
	    
	    // merubah posisi x y ikan, mendekati makanan / bergerak bebas
	    virtual void move() = 0;
	    
	    // membuat object coin dan memanggil aquarium.add_coin(coin&)
	    virtual void produce_coin() = 0;
	    
	    // menambah hunger dan memanggil aquarium.remove_food(food&)
	    virtual void eat() = 0;
	    
	    // mengecek apakah hunger = max hunger
	    virtual bool isFull() = 0;

  	protected:
  		
	  	int fish_id;
	  	int fish_price;
	    int coin_value;
	    double hunger;
	    int max_hunger;
	    int speed;
	    
	    static int fish_count; // jumlah ikan (mungkin perlu)
    
  	
  	
    
};

#endif
