#pragma once
#include <cmath>
#include "Actor.h"
class Human : public Actor
{
	private: 
		float _life;
		float _carryWeight;


	public:

		const float& life = _life;
		const float& carryWeight = _carryWeight;

		Human(PVector location = PVector(0, 0), PVector velocity = PVector(0, 0), PVector acceleration = PVector(0, 0));
		~Human();

		void update() override;
		void draw() override;

};

