// asbtract class Object.h

#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
	virtual void create() = 0;		// create object
	virtual void draw() = 0;		// draw on screen
	virtual void remove() = 0;		// remove object (calling destructor)
	virtual void move() = 0;		// movement
};

#endif // !OBJECT_H
