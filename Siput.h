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

    int get_timer();

    void set_timer();

		/*------------------------------------------------------------
									Method
		------------------------------------------------------------*/

    void draw();
    void move(LinkedListList<Coin>& C);
    void find_coin(LinkedList<Coin>& C);
   	void take_coin(LinkedList<Coin>& C);
    double euclidean(Coin C);
    int inRadius(LinkedList<Coin>& C);

  	private:
      double timer;
    	int distance_to_coin;
};

#endif
