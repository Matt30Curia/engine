#pragma once
#include <string>
#include <vector>
#include "raylib.h"
#include "Vector2.h"

class RenderObj
{

public:
	virtual void setRotation(float rot) = 0;
	virtual void setPos(Vector2D _pos) = 0;
	virtual Vector2D getPos() = 0;
	virtual std::string type() = 0;
	virtual bool isNode() = 0;
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void process(float delta) = 0;
	virtual void phisics() = 0;
	virtual void add(RenderObj* child) = 0;
	virtual void addChildren(std::vector<RenderObj*> children) = 0;
	virtual RenderObj* getChild(const std::string& child) = 0;
	virtual std::vector<RenderObj*> getChildren(const std::string& child) = 0;
	virtual void removeChild(const std::string& child) = 0;
};

