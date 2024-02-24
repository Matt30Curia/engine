#include "Node.h"
#include <iostream>


void Node::init()
{
	for (auto child : _children)
	{
		child->init();
	}
}

void Node::process(float delta)  {
	for (int i = 0; i < _children.size() ; i++ ) 
	{
		_children[i]->phisics();
		_children[i]->process(delta);
		_children[i]->draw();
	
	}

}

void Node::add(RenderObj* child) 
{
	_children.push_back(child);
}

RenderObj* Node::getChild(const std::string& child)//funziona
{

	for (auto elem : _children)
	{

		if (elem->isNode())
		{
			std::cout << "nodo";
			return elem->getChild(child);
		}

		if (child == elem->type())
		{
			std::cout << "trovato";
			return elem;
			
		}

		
	}
	return nullptr;
}

void Node::removeChild(const std::string& child)
{

	for (int i = 0; i < _children.size(); i++)
	{

		if (_children[i]->isNode())
		{
			return _children[i]->removeChild(child);
		}

		if (child == _children[i]->type())
		{
				_children.erase(_children.begin() + i);
				break;
		}
	}

}

std::vector<RenderObj*> Node::getChildren(const std::string& child)
{
	std::vector<RenderObj*> buffer;

	for (auto elem : _children)
	{

		if (elem->isNode())
		{
			buffer = elem->getChildren(child);
		}

		if (child == elem->type())
		{
			buffer.push_back(elem);
		}


	}
	return buffer;
}
