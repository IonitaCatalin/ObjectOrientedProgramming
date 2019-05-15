#pragma once
#include "Node.h"
#include "Container.h"
class LinkedList :public Container
{
private:
	Node*ListHead;
public:
	LinkedList();
	~LinkedList();
};

