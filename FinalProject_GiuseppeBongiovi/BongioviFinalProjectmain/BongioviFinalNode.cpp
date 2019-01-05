#include "pch.h"
#include "BongioviFinalNode.h"
#include <string>


Node::Node()
{
}
Node::Node(string& name, int no)
	:itemName(name), itemNo(no)
{
	this->next = NULL;
	this->prev = NULL;
}

void Node::setprice(double *p)
{
	price = p;
}

//Node::~Node()
//{
//}

void Node::setnext(Node *s)
{
	this->next = s;
}
void Node::setprev(Node *s) {

}

int Node::getitemNo()
{
	return itemNo;
}

string Node::getitemName()
{
	return itemName;
}

//Node Node::getnext()
//{
	//Node n = *next;
	//return n;
//}
