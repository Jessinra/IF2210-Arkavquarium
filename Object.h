// asbtract class Object.h

#ifndef OBJECT_H
#define OBJECT_H

class Object {
	
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
		
		/*------------------------------------------------------------
									Method  
		------------------------------------------------------------*/
		
		// draw on screen
		virtual void draw() = 0;		
		
		// remove object (calling destructor)
		virtual void remove() = 0;	
		
		// handle object movement	
		virtual void move() = 0;	
		
	private:
		
		int position_x;
	  	int position_y;
	  	string direction;
};

#endif // !OBJECT_H
