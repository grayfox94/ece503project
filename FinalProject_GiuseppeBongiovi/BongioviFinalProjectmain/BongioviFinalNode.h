#pragma once
//#include "BongioviLinkedList.h"
#include <string>
using namespace std;
class Node {
	friend class StockAccount;
public:
	Node();
	Node(string&, int);
	void setprice(double*);
	void setprev(Node *);
	void setnext(Node *);
	int getitemNo();
	string getitemName();
	//Node getnext();


private:
	string itemName;
	int itemNo;
	double *price;
	//double value = itemNo * (*price);
	Node *next;
	Node *prev;


};

