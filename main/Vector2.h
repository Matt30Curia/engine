#pragma once

#include <cmath>
#include "raylib.h"


#define RAD 0.01745329251994329576922222222222f

class Vector2D
{
public:
	float x, y;
	float rotation;
	Vector2D(float _x, float _y) : x{ _x }, y{ _y } {}
	Vector2D(){}

	bool operator== (Vector2D point);

	Vector2D operator*=(float n);
	Vector2D operator*=(Vector2D point);
	Vector2D operator+=(float n);
	void operator+=(Vector2D point);
	Vector2D operator-=(float n);
	Vector2D operator-=(Vector2D point);
	Vector2D operator/=(float n);
	Vector2D operator/=(Vector2D point);

	bool operator <(Vector2D point) { return x < point.x && y < point.y; }
	bool operator >(Vector2D point) { return x > point.x && y > point.y; }

	Vector2D operator*(float n);
	Vector2D operator*(Vector2D point);
	Vector2D operator+(float n);
	Vector2D operator+(Vector2D point);
	Vector2D operator-(float n);
	Vector2D operator-(Vector2D point);
	Vector2D operator/(float n);
	Vector2D operator/(Vector2D point);
	Vector2D rotate(float angle);
	

	Vector2D toVector2D(Vector2 point) { return Vector2D{ point.x, point.y }; }
	Vector2 toVector2();
};

