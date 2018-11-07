#include <SFML/Graphics.hpp>
#include <memory>
#include "ShapeAssist.h"
#include "PVector.h"

const int WIDTH = 600;
const int HEIGHT = 600;



int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	std::unique_ptr<ShapeAssist> shape = std::make_unique<ShapeAssist>();



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}

	return 0;
}