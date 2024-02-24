#pragma once
#include "Node.h"
class NodeManager
{
private:

	Node* _node;

	NodeManager() {}

	NodeManager(const NodeManager&) = delete;
	void operator=(const NodeManager&) = delete;

public:

	static NodeManager& instance()
	{
		static NodeManager _instance;

		return _instance;
	}

	void setNode(Node& node) { _node = &node; }
	void addChildren(std::vector<RenderObj*> children);
	void addChild(RenderObj* child);
	RenderObj* getChild(const std::string& childId) { return _node->getChild(childId); }
	std::vector<RenderObj*> getChildren(const std::string& child) { return _node->getChildren(child); }
	void removeChild(const std::string& childId) { _node->removeChild(childId); }

};

