#ifndef AQUARIUM_H
#define AQUARIUM_H

#include "wtypes.h" // for GetDesktopResolution()
#include "Object.h"
using namespace std;

class Aquarium : public Object{
	
	public:
		draw()
		
	private:
		int screen_width, screen_height;

		Object ** aquarium;			// pointer ? 
			
		void GetDesktopResolution();
};




#endif
