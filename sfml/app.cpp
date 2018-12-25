#include <SFML/Graphics.hpp>
#include <memory>
#include "ShapeAssist.h"
#include "PVector.h"
#include "Human.h"
#include <cmath>
#define PI 3.14159265
const int WIDTH = 600;
const int HEIGHT = 600;



int main()
{
	srand(static_cast<unsigned>(time(0)));
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	window.setFramerateLimit(60);
	std::unique_ptr<ShapeAssist> shape = std::make_unique<ShapeAssist>();
	shape->SetWindow(&window);
	shape->DrawSetColour(sf::Color::White, sf::Color::Green);
	shape->DrawSetThinkness(2);
	shape->SetCircleEquation(300, 300, 5);
	shape->SetLineEquation(0, 300, 600, 300);

	float mew = 0.1;
	float normal = 1;
	float fricMag = mew * normal;
	float speed = 0;
	float dragMag = 0;

	PVector grav(0, 3);
	PVector wind(10, 0);
	PVector fric;
	PVector drag;

	Human man;
	man.SetShapeAssist(shape.get());
	man.SetVelo(PVector(0.1, 0.1));
	man.SetUsesPhysics(true);
	man.SetLocal(PVector(300, 50));
	man.SetMass(10);
	man.ApplyForce(wind);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		fric = man.velocity;
		fric.normalize();
		fric.mult(-1 * fricMag);
		
		speed = man.velocity.mag();
		dragMag = speed * speed * mew;
		drag = man.velocity;
		drag.normalize();
		drag.mult(-1 * dragMag);

		//man.ApplyForce(fric);
		if (man.location.y > 300)
			man.ApplyForce(drag);
		man.ApplyForce(grav);	

		man.update();
		man.checkEdges(WIDTH, HEIGHT);

		window.clear();
		man.draw();
		shape->DrawLine();
		window.display();
	}

	return 0;
}