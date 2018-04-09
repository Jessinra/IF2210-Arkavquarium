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

		int get_distance();

		void set_distance(int x);

		/*------------------------------------------------------------
									Method
		------------------------------------------------------------*/

        void draw();
        void move();
        void find_coin();
       	void take_coin(LinkedList<Coin>& C);

  	private:

    	int distance_to_coin;
};

#endif
