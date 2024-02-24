#pragma once
#include "RenderObj.h"
#include "raylib.h"
#include <string>
#include <iostream>

class Point : public RenderObj
{
public : 

	//-------------- implemented methos -------------//
	Point(Vector2D position, const std::string& uuid) : _uuid(uuid), pos(position) {}//ctor  TO-DO implentiting copy and move constructor

	void setRotation(float rot) { rotation = rot; };
	bool isNode() { return false; }
	void draw() override; // draw method
	inline std::string type() { return _uuid; }
	inline void setPos(Vector2D _pos) { pos = _pos; }
	Vector2D getPos() { return pos; }

	//------------------ virtual method ----------------// 
	virtual void init() {};
	virtual void addChildren(std::vector<RenderObj*> children) {};
	virtual void process(float delta) {};
	virtual void phisics() {};
	virtual void add(RenderObj* child) {};
	virtual RenderObj* getChild(const std::string& child) { return nullptr; };
	virtual void removeChild(const std::string& child) {};
	virtual std::vector<RenderObj*> getChildren(const std::string& child) { return std::vector<RenderObj*>(); };

public :
	float rotation;
	Vector2D pos; // position 2d of point
	std::string _uuid; //uniqe id of object
};

