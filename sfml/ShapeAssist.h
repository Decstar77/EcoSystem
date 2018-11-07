#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

enum ShapeAssistShape
{
	square = 0,
	cicle = 1,
};

class ShapeAssist
{
	private:
		sf::RenderWindow *window;
		sf::Color out_drawColour;
		sf::Color in_drawColour;
		sf::Vertex line[2];
		float thinkness;
		float c_x, c_y, c_raduis;
		bool clear = false;

	public:
		ShapeAssist();
		ShapeAssist(sf::RenderWindow *win);
		~ShapeAssist();
		bool GetClearStatus();
		void SetWindow(sf::RenderWindow *win);

		void DrawSetDefualt(ShapeAssistShape shape);
		void DrawSetThinkness(float think);
		void DrawSetColour(sf::Color out_colour, sf::Color in_colour = sf::Color::Transparent);

		void DrawLine();
		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawCircle();
		void DrawCircle(float x, float y, float raduis);
		void DrawDefualt();

		void SetLineEquation(float m, float c);
		void SetLineEquation(float x1, float y1, float x2, float y2);
		void SetCircleEquation(float x, float y, float raduis);



		sf::CircleShape GetCircle(float x, float y, float raduis);

};
