#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "BongioviAccount.h"
#include <string>
#include "BongioviFinalNode.h"

using namespace std;

class StockAccount :
	public Account
{
public:
	StockAccount(); //must have constructor that will read transaction history or current positions and rebuild

	//any transactions must update Bank_Transaction_History.txt and Stock_Transaction_History.txt

	void purchase(string&, int,double*); //purchse shares at price, reject otherwise.

	void sell(string&, int,double); //sell shares at price and credit cash balance
	void sort();
	//int size() const;
	void addToStart(Node *);
	//void addToEnd(Node *);
	void printList();
	bool removeFromStart();
	//bool removeFromEnd();
	//void removeNodeFromList(int);
	void removeNodeFromList(string);
	void StockHistory(int, string, int, double);
	void Accountinfo();
	void setprices(string&, double *);
	void startupbuy(string&, int,double*);
	~StockAccount();
	//Node gethead();
private:
	Node *Head;
	int mySize = 0; //do i need this?

};

