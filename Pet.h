#ifndef PET_H
#define PET_H

#include "Object.h"
#include "Moveable.h"
using namespace std;

class Pet : public Object, public Moveable {
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

	private:

		int pet_id;
		static int pet_count;
};

#endif
