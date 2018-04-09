#ifndef SIPUT_H
#define SIPUT_H

#include "Pet.h"
using namespace std;

class Siput : public Pet {
  	public:

   		/*------------------------------------------------------------
			 				Constructor & Destructor
		------------------------------------------------------------*/

    	Siput();
    	~Siput();

    	/*------------------------------------------------------------
								Getter  Setter
		------------------------------------------------------------*/

		int get_speed();
        void set_speed(int x);


		/*------------------------------------------------------------
									Method
		------------------------------------------------------------*/

        void draw();
        void move(double sec_since_last, LinkedListList<Coin>& C);
        double euclidean(Coin C);
        void find_coin(LinkedList<Coin>& C);
        int inRadius(LinkedList<Coin>& C);
        bool take_coin(LinkedList<Coin>& C);

  	private:
        int speed;
};

#endif
