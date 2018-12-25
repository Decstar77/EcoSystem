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
	ShapeAssist* shape = Actor::GetShape();
	if (shape == nullptr & shape->GetClearStatus() == false)
	{
		std::cout << "Please set shade assist" << std::endl;
		return;
	}
	shape->DrawCircle(location.x, location.y, (1.2)*mass);
}
