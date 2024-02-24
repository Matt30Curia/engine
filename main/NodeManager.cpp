#include "NodeManager.h"

void NodeManager::addChildren(std::vector<RenderObj*> children)
{
	for (auto child : children)
	{
		child->init();
	}
	_node->addChildren(children);
	
}

void NodeManager::addChild(RenderObj* child)
{
	child->init(); _node->add(child);
}
	

