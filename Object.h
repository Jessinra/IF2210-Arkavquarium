// asbtract class Object.h

#ifndef OBJECT_H
#define OBJECT_H

#include "Lib/oop.hpp"

using namespace std;

class Object {
	
	public:	
				
		/*------------------------------------------------------------
									Method  
		------------------------------------------------------------*/
		
		// draw on screen
		virtual void draw() = 0;		
		
		// remove object (calling destructor)
		virtual void remove() = 0;	
	
};

#endif // !OBJECT_H
