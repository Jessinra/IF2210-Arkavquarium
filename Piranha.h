#ifndef PIRANHA_H
#define PIRANHA_H

#include "Fish.h"
#include "Guppy.h"
#include "Aquarium.h"
#include "LinkedList.h"

#include "Constant.h"

using namespace std;

class Piranha : public Fish {
	
	public:
		
	  	/*------------------------------------------------------------
						Constructor & Destructor 	
		------------------------------------------------------------*/	
		
		Piranha();
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		
	    void draw();
	    int findGuppy(LinkedList<Guppy> G);
	    void move(double sec_since_last,LinkedList<Guppy> G);
	    double euclidean(Guppy g);
	    bool inRadius(LinkedList<Guppy> G);
	    bool eat(LinkedList<Guppy>& G);

};

#endif