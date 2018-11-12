#include "Human.h"



Human::Human(PVector location, PVector velocity, PVector acceleration)
{
	SetLocal(location);
	SetVelo(velocity);
	SetAccel(acceleration, 1);
	
}


Human::~Human()
{
}

void Human::update()
{
	Actor::update();	
}
void Human::draw()
{
	Actor::draw();
}
