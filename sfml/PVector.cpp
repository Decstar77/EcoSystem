#include "PVector.h"





PVector::PVector()
	: x(0), y(0), xSpeed(0), ySpeed(0)
{
}
PVector::PVector(float _x, float _y)
	: x(_x), y(_y), xSpeed(0), ySpeed(0)
{
}
PVector::PVector(float _x, float _y, float _xSpeed, float _ySpeed)
	: x(_x), y(_y), xSpeed(_xSpeed), ySpeed(_ySpeed)
{

}
PVector::~PVector()
{
}

float PVector::mag() const 
{
	return (sqrt(x*x + y * y));
}
void PVector::add(PVector vec)
{
	x += vec.x;
	y += vec.y;
}
void PVector::sub(PVector vec)
{
	x -= vec.x;
	y -= vec.y;
}
void PVector::set(float _x, float _y)
{
	x = _x;
	y = _y;
}
void PVector::mult(float n)
{
	x *= n;
	y *= n;
}
void PVector::div(float n)
{
	x /= n;
	y /= n;
}
void PVector::normalize()
{
	float m = mag();
	if (m != 0)
		div(m);
}
void PVector::limit(float amt)
{
	if (amt < mag())
	{
		normalize();
		mult(amt);
	}
}
void PVector::display() const
{
	std::cout << "x: " << x << " y: " << y << std::endl;
}
PVector PVector::get()
{
	return *this;
}
PVector* PVector::getp()
{
	return this;
}

//Static Function
PVector PVector::add(PVector vec1, PVector vec2)
{
	return PVector(vec1.x + vec2.x, vec1.y + vec2.y);
}
PVector PVector::sub(PVector vec1, PVector vec2)
{
	return PVector(vec1.x - vec2.x, vec1.y - vec2.y);
}
PVector PVector::mult(PVector vec1, float n)
{
	vec1.x *= n;
	vec1.y *= n;
	return vec1;
}
PVector PVector::div(PVector vec1, float n)
{
	vec1.x /= n;
	vec1.y /= n;
	return vec1;
}
PVector PVector::randVec(float xMin, float xMax, float yMin, float yMax)
{
	
	float x = ((float(rand()) / float(RAND_MAX)) * (xMax - xMin)) + xMin;
	float y = ((float(rand()) / float(RAND_MAX)) * (yMax - yMin)) + yMin;
	return PVector();
}
