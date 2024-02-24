#pragma once
#include "RenderObj.h"
#include <string>
#include <vector>
#include <algorithm>
#include <initializer_list>

class Node : public RenderObj
{

public:
	std::string _uuid;

	Node(const std::string& uuid) : _uuid(uuid) {}; //empty ctor TO-DO implenting copy and move constructor
	Node(std::initializer_list<RenderObj*> children, const std::string& uuid) : _uuid(uuid), _children(children) {}// ctor flutter style

	//--------- implemented method -------//
	bool isNode() { return true; }
	inline std::string type() {	return _uuid;}
	void init() override; // init all children
	
	void process(float delta);

	void add(RenderObj* child) override;// add child in this brach
	inline void addChildren(std::vector<RenderObj*> children) { append<RenderObj*>(_children, children); }
	RenderObj* getChild(const std::string& child) override;//get child of this branch
	void removeChild(const std::string& child);

	std::vector<RenderObj*> getChildren(const std::string& child);
	
	

	//------ virtual method ------//
	virtual void setRotation(float rot) {};
	virtual void phisics(){};
	virtual void draw(){};
	virtual void setPos(Vector2D _pos) {}
	virtual Vector2D getPos() { return Vector2D(10,10); }

private:
	std::vector<RenderObj*> _children; //all children
	std::string uuid;

	//--- function that add children in a vector ---//
	template <typename T>
	void append(std::vector<T>& a, const std::vector<T>& b)
	{
		a.reserve(a.size() + b.size());
		a.insert(a.end(), b.begin(), b.end());
	}




	
};

