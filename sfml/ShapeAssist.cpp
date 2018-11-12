#include "ShapeAssist.h"



ShapeAssist::ShapeAssist()
	: out_drawColour(sf::Color::White), in_drawColour(sf::Color::Transparent), window(nullptr), thinkness(5)
	, c_x(0), c_y(0), c_raduis(0)
{

}
ShapeAssist::ShapeAssist(sf::RenderWindow *win)
	: out_drawColour(sf::Color::White), window(win), in_drawColour(sf::Color::Transparent), thinkness(5)
	, c_x(0), c_y(0), c_raduis(0)
{
	if (win == nullptr)
	{
		std::cout << "Window is null" << std::endl;
		clear = false;
	}
	if (win->isOpen() == false)
	{
		std::cout << "Window is closed" << std::endl;
		clear = false;
	}
	clear = true;
}
ShapeAssist::~ShapeAssist()
{
}
bool ShapeAssist::GetClearStatus()
{
	return clear;
}
void ShapeAssist::SetWindow(sf::RenderWindow *win)
{
	window = win;
	clear = true;
	if (win == nullptr)
	{
		std::cout << "Window is null" << std::endl;
		clear = false;
	}
	if (win->isOpen() == false)
	{
		std::cout << "Window is closed" << std::endl;
		clear = false;
	}
}

void ShapeAssist::DrawSetThinkness(float thinkness)
{
	this->thinkness = thinkness;
}
void ShapeAssist::DrawSetColour(sf::Color out_colour, sf::Color in_colour)
{
	this->out_drawColour = out_colour;
	this->in_drawColour = in_colour;
}

void ShapeAssist::DrawLine()
{
	if (!clear)
		return;

	window->draw(line, 2, sf::Lines);
}
void ShapeAssist::DrawLine(float x1, float y1, float x2, float y2)
{

}
void ShapeAssist::DrawCircle()
{
	if (!clear)
	{
		std::cout << "Not clear" << std::endl;
		return;
	}
	sf::Vector2f vec(c_x, c_y);
	sf::CircleShape shape(c_raduis - thinkness);
	shape.setPosition(vec);
	shape.setOrigin({ c_raduis, c_raduis });
	shape.setPointCount(c_raduis / 2 + 10);
	shape.setFillColor(in_drawColour);
	shape.setOutlineThickness(thinkness);
	shape.setOutlineColor(out_drawColour);
	window->draw(shape);
}
void ShapeAssist::DrawCircle(float x, float y, float raduis)
{
	if (!clear)
	{
		std::cout << "Not clear" << std::endl;
		return;
	}
	sf::Vector2f vec(x, y);
	sf::CircleShape shape(raduis - thinkness);
	shape.setPosition(vec);
	shape.setOrigin({ raduis, raduis });
	shape.setPointCount(raduis / 2 + 10);
	shape.setFillColor(in_drawColour);
	shape.setOutlineThickness(thinkness);
	shape.setOutlineColor(out_drawColour);
	window->draw(shape);
}

void ShapeAssist::SetLineEquation(float x1, float y1, float x2, float y2)
{
	if (!clear)
		return;

	line[0] = sf::Vertex(sf::Vector2f(x1, y1));
	line[1] = sf::Vertex(sf::Vector2f(x2, y2));
}
void ShapeAssist::SetLineEquation(float m, float c)
{
	std::cout << "SetLineEquation with params 'm' and 'c' has not been completed" << std::endl;
}
void ShapeAssist::SetCircleEquation(float x, float y, float raduis)
{
	c_x = x;
	c_y = y;
	c_raduis = raduis;
}
void ShapeAssist::SetCircleLocation(float x, float y)
{
	c_x = x;
	c_y = y;
}




sf::CircleShape ShapeAssist::GetCircle(float x, float y, float raduis)
{
	if (!clear)
	{
		std::cout << "Not clear" << std::endl;
		return sf::CircleShape();
	}
	sf::Vector2f vec(x, y);
	sf::CircleShape shape(raduis - thinkness);
	shape.setPosition(vec);
	shape.setOrigin({ raduis, raduis });
	shape.setPointCount(raduis / 2 + 10);
	shape.setFillColor(in_drawColour);
	shape.setOutlineThickness(thinkness);
	shape.setOutlineColor(out_drawColour);
	return shape;
}
