#pragma once
#include "Point.h"
#include "raylib.h"

static int count = 0;

class Sprite : public Point
{
private:
	Texture2D texture;
	std::string _pathTexture;

public:
	float scale = 1;
	float rotation = 0;

	Sprite(const std::string& pathTexture, const std::string& uuid) 
		: Point(Vector2D(10, count), uuid), _pathTexture(pathTexture) {
		count += 10;
	}

	void setRotation(float rotat) override { rotation = rotat; }
	void draw() override;
	void init() override;
	inline std::string type() override { return _uuid; }

	~Sprite();
};

