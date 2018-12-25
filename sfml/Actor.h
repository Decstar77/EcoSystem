#pragma once
#include "PVector.h"
#include "ShapeAssist.h"

class Actor
{
	private:
		ShapeAssist* shape;
		PVector local;
		PVector velo;
		PVector accel;
		
		float _topSpeed;
		float _mass;
		
		bool _usesPhysics;

	public:
		const PVector& const location = local;
		const PVector& const velocity = velo;
		const PVector& const acceleration = accel;

		const float& const topSpeed = _topSpeed;
		const float& const mass = _mass;

		const bool& const usePhysics = _usesPhysics;
	
		Actor(PVector location = PVector(0, 0), PVector velocity = PVector(0,0), PVector acceleration = PVector(0,0));
		~Actor();

		ShapeAssist* GetShape();

		void SetShapeAssist(ShapeAssist* shape);
		void SetLocal(PVector vec);
		void SetLocal(float x, float y);
		void SetVelo(PVector vec);
		void SetVelo(float x, float y);
		void SetAccel(PVector vec, float topSpeed);
		void SetAccel(float x, float y, float topSpeed);
		void SetMass(float mass);
		void SetUsesPhysics(bool phy);
		void ApplyForce(PVector force);

		void checkEdges(float width, float height);
		virtual void draw();
		virtual void update();

};

