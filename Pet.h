#ifndef PET_H
#define PET_H

#include "Object.h"
#include "Moveable.h"
using namespace std;

class Pet : public Object, Moveable {
  	public:
  		
  		/*------------------------------------------------------------
			 				Constructor & Destructor 	
		------------------------------------------------------------*/
		
	    Pet();
	    ~Pet();
	    
	    /*------------------------------------------------------------
									Getter  
		------------------------------------------------------------*/
		
		int get_id();
		
		/*------------------------------------------------------------
									Method 
		------------------------------------------------------------*/	
		
	    void draw();
	    void remove();
	    virtual void move();
		
	
	    
	private:
		
		int pet_id;
		static int pet_count;
};

#endif
