#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <string>
using namespace std;

class Moveable {

	public:

		/*------------------------------------------------------------
							 	Getter	Setter
		------------------------------------------------------------*/
		
		double get_x();
		double get_y();
		string get_dir();
		
		void set_x(double x);
		void set_y(double y);
		void set_dir(string dir);

		// handle object movement	
		virtual void move() = 0;

	private:

		double position_x;
	  	double position_y;
	  	string direction;


};

#endif