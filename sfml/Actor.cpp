#include "Actor.h"


Actor::Actor(PVector location, PVector velocity, PVector acceleration)
	: _topSpeed(0), _mass(0)
{
	local = location;
	velo = velocity;
	accel = acceleration;
}
Actor::~Actor()
{
}
void Actor::SetShapeAssist(ShapeAssist * shape)
{
	if (shape != nullptr && shape->GetClearStatus())
	{
		this->shape = shape;
		std::cout << "Shape set" << std::endl;
		return;
	}
	std::cout << "Cannot set shape" << std::endl;
}
void Actor::SetLocal(PVector vec)
{
	local = vec;
}
void Actor::SetVelo(PVector vec)
{
	velo = vec;
}
void Actor::SetAccel(PVector vec, float topSpeed)
{
	accel = vec;
	this->_topSpeed = topSpeed;
}
void Actor::SetMass(float mass)
{
	_mass = mass;
}
void Actor::SetUsesPhysics(bool phy)
{
	local.mult(0);
	velo.mult(0);
	accel.mult(0);
	_usesPhysics = phy;
}
void Actor::ApplyForce(PVector force)
{
	PVector temp = PVector::div(force, mass);
	accel.add(temp);
}
void Actor::checkEdges(float width, float height)
{
	if (_usesPhysics)
	{
		if (local.x > width - 10) {
			velo.x *= -1;
		}
		else if (local.x < 10) {
			velo.x *= -1;
		}

		if (local.y > height - 10) {
			velo.y *= -1;
		}
		else if (local.y < 10) {
			velo.y *= -1;
		}
	}
	else
	{
		if (local.x > width) {
			local.x = 0;
		}
		else if (local.x < 0) {
			local.x = width;
		}

		if (local.y > height) {
			//local.y = 0;
			velo.y *= -0.8;
		}
		else if (local.y < 0) {
			local.y = height;
		}
	}
}
void Actor::draw()
{
	if (shape == nullptr & shape->GetClearStatus() == false)
	{
		std::cout << "Wot" << std::endl;
		return;
	}
	shape->DrawCircle();

}
void Actor::update()
{
	velo.add(accel);
	local.add(velo);
	shape->SetCircleLocation(local.x, local.y);
	accel.mult(0);
}