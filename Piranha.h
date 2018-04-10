#ifndef PIRANHA_H
#define PIRANHA_H

#include "Fish.h"
#include "Guppy.h"
#include "LinkedList.h"

#include "Constant.h"

using namespace std;

class Piranha : public Fish {
	
	public:
		
	  	/*------------------------------------------------------------
						Constructor & Destructor 	
		------------------------------------------------------------*/	
		
		Piranha();
	    Piranha& operator=(Piranha&);
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/
		
		bool operator==(Piranha&);
		bool operator!=(Piranha&);
	    void draw();
	    int findGuppy(LinkedList<Guppy> &G);
	    void move(double sec_since_last,LinkedList<Guppy> &G);
	    double euclidean(Guppy &g);
	    bool inRadius(LinkedList<Guppy> &G);
	    int eat(LinkedList<Guppy> &G);
};

#endif