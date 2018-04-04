

#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <string>
using namespace std;

class moveable {

	public:

		/*------------------------------------------------------------
							 	Getter	Setter
		------------------------------------------------------------*/
		
		int get_x();
		int get_y();
		string get_dir();
		
		void set_x();
		void set_y();
		void set_dir();

		// handle object movement	
		virtual void move() = 0;

	private:

		int position_x;
	  	int position_y;
	  	string direction;


};

#endif