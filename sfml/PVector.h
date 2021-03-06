#pragma once
#include <math.h>
#include <iostream>
#include <random>
#include <time.h>
class PVector
{
	private:
		float xSpeed;
		float ySpeed;

	public:
		float x;
		float y;
		PVector(float _x, float _y);
		PVector(float _x, float _y, float _xSpeed, float _ySpeed);
		PVector();
		~PVector();

		
		float mag() const;
		void add(PVector vec);
		void sub(PVector vec);
		void limit(float amt);
		void mult(float n);
		void div(float n);
		void set(float x, float y);
		void normalize();
		void display() const;
		PVector get();
		PVector* getp();

		static PVector sub(PVector vec1, PVector vec2);
		static PVector add(PVector vec1, PVector vec2);
		static PVector mult(PVector vec1, float n);
		static PVector div(PVector vec1, float n);
		static PVector randVec(float xMin, float xMax, float yMin, float yMax);
};
