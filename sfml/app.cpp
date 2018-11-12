#include <SFML/Graphics.hpp>
#include <memory>
#include "ShapeAssist.h"
#include "PVector.h"
#include "Human.h"

const int WIDTH = 600;
const int HEIGHT = 600;



int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	window.setFramerateLimit(60);
	std::unique_ptr<ShapeAssist> shape = std::make_unique<ShapeAssist>();
	shape->SetWindow(&window);
	shape->DrawSetColour(sf::Color::White, sf::Color::Green);
	shape->DrawSetThinkness(2);
	shape->SetCircleEquation(300, 300, 5);

	Human man;
	man.SetShapeAssist(shape.get());
	man.SetVelo(PVector(0.1, 0.1));
	man.SetUsesPhysics(true);
	man.SetLocal(PVector(300, 300));
	man.SetMass(10);
	
	PVector grav(0, 2);
	PVector wind(50, 0);
	man.ApplyForce(wind);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		man.checkEdges(WIDTH, HEIGHT);
		man.ApplyForce(grav);
		man.checkEdges(WIDTH, HEIGHT);
		man.update();
		man.checkEdges(WIDTH, HEIGHT);
		window.clear();
		man.draw();
		window.display();
	}

	return 0;
}