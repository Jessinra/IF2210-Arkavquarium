#ifndef GUPPY_H
#define GUPPY_H

#include "Fish.h"
using namespace std;

class Guppy : public Fish {
	
	public:
		
	  	/*------------------------------------------------------------
						Constructor & Destructor 	
		------------------------------------------------------------*/
		
	    Guppy();
	    ~Guppy();
	    Guppy(const Guppy& );
	    Guppy& operator=(const Guppy& );
	    
		/*------------------------------------------------------------
									Getter  
		------------------------------------------------------------*/
		
		int get_level();
		
		void set_level(int);
		
		/*------------------------------------------------------------
								Method  	
		------------------------------------------------------------*/
		
		//approach food
	    void move();
	    
	    // draw on screen (GUI)
	    void draw();
	    
	    //periodically drop coin
	    void produce_coin(); 
	    
	    //eat food
		void eat(); 
		
		// grow to another lv
	    void grow();
	    
	    // check kondisi hunger
	    bool isFull();
	
	
	private:
		
	    int level_grow;
	    int max_level;
};

#endif
