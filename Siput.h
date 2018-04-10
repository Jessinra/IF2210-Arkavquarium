#ifndef SIPUT_H
#define SIPUT_H

#include "Pet.h"
#include "Coin.h"
#include "Constant.h"
#include "Moveable.h"
#include "LinkedList.h"


using namespace std;

class Siput : public Pet {
  	public:

   		/*------------------------------------------------------------
			 				Constructor & Destructor
		------------------------------------------------------------*/

    	Siput();

    	/*------------------------------------------------------------
								Getter  Setter
		------------------------------------------------------------*/

		int get_speed();
        void set_speed(int x);


		/*------------------------------------------------------------
									Method
		------------------------------------------------------------*/

        void draw();
        void move(double sec_since_last, LinkedList<Coin>& C);
        double euclidean(Coin C);
        int find_coin(LinkedList<Coin>& C);
        int inRadius(LinkedList<Coin>& C);
        int take_coin(LinkedList<Coin>& C);

		/**** operator overloading ****/
		Siput& operator=(Siput&);
		bool operator==(Siput&);
		bool operator!=(Siput&);

  	private:
	  	double distance_to_coin;
        int speed;
};

#endif
