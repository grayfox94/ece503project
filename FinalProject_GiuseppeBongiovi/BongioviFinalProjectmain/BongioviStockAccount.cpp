#include "pch.h"
#include "BongioviStockAccount.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;


StockAccount::StockAccount()
{
	//build portfolio with AccountInfo.txt upon creation
	//ifstream myfile;
	//myfile.open("AccountInfo.txt");
	//if (myfile.is_open()) {
		//cout << "running account startup" << endl;
		//myfile >> Cash_Balance;
		//Node *n = new Node();
		//string date;
			//while (myfile >> n->itemName >> n->itemNo) {
				//addToStart(n);
				//Node *n = new Node();
			//}
	//}
	//myfile.close();

}

void StockAccount::purchase(string& stock, int share, double* price)
{
	if ((double)share* *price > Cash_Balance) {
		return;
	}
	else {
		Node *n = new Node(stock, share);
		double *p = price;
		n->setprice(p);
		addToStart(n);
		//place sort algo here
		Cash_Balance = Cash_Balance - share * *price;
		StockHistory(0, stock, share, *price);
		//mySize++;
		//update bank and stock transaction sheet here
		//sort();
		

	}
	
	return;
}

void StockAccount::sell(string& stock, int share, double price)
{
	Node *temp = Head;
	//bool match;
	//match = temp->getitemName().compare(stock);
	//cout << match;
	while (temp->getitemName() != stock && temp != NULL) {
		std::cout << temp->getitemName() << std::endl;
		temp = temp->next;
		std::cout << temp->getitemName() << std::endl;
	}
	if (temp == NULL) {
		//going short. probably not allowed.
		std::cout << "Going short is not allowed" << std::endl;
		return;
	}
	else {
		if (share > temp->itemNo) {
			std::cout << "Insufficient shares to sell. Please enter a sufficient amount." << std::endl;
			return;
		}
		if (share == temp->itemNo) {
			//delete node, update cash balance
			Cash_Balance = Cash_Balance + share * price;
			Node *temp2 = temp->prev;
			Node *temp3 = temp->next;
			if (temp2 != NULL) {
				temp2->next = temp3;
			}
			if (temp3 != NULL) {
				temp3->prev = temp2;
			}
			if (temp == Head) {
				Head = Head->next;
			}
			delete temp;
			mySize--;
			//update transaction sheet and account balance sheet

		}
		else {
			//update node with new share total and cash balance
			Cash_Balance = Cash_Balance + share * price;
			temp->itemNo = temp->itemNo - share;
			//update transaction sheet and account balance sheet
		}
		StockHistory(1,stock, share, price);
	}
	return;
}

void StockAccount::sort()
{ //using insertion sort for this algorithm
	if (Head == NULL || Head->next == NULL) {
		return;
	}
	Node *temp1 = Head;
	Node *temp2 = Head->next;
	for (int i = 0; i < mySize; i++) {
		//printList();
		//cout << temp1->getitemName() << endl;
		//cout << "iter :" << i << endl;
		//if (temp1->next == NULL) {
			//cout << "next item is NULL" << endl;
		//}
		temp2 = temp1->next;
		//if (temp2 == NULL) {
			//break;
		//}
		while(temp2 != NULL) {
			//cout << "temp2 is:	" << temp2->getitemName() << endl;
			//cout << "temp1 is:	" << temp1->getitemName() << endl;
			//printList();
			//if (Head == temp1) {
				//cout << "Head is equal to temp 1" << endl;
			//}
			//else {
				//cout << "Head is:	" << Head->getitemName() << endl;
			//}
			//if (temp2->next == NULL) {
				//std::cout << "it will crash here because next is null" << endl;
			//}
			if ((*temp2->price)*(temp2->getitemNo()) > (*temp1->price)*(temp1->getitemNo())) {
				//swap
				//cout << "Running swap" << endl;
				//if (temp2->next == NULL) {
					//cout << "Temp2 next is NULL" << endl;
				//}
				if (temp1->next == temp2) {
					//cout << "Runnin Head Swap" << endl;
					if (temp1 == Head) {
						Head = temp2;
						Node *temp3 = temp2->next;
						//Node *temp4 = temp2->prev;
						temp2->prev = temp1->prev;
						temp2->next = temp1;
						temp1->next = temp3;
						temp1->prev = temp2;
						if (temp3 != NULL) {
							temp3->prev = temp1;
						}
						temp3 = temp1;
						temp1 = temp2;
						temp2 = temp3;
					}
					else {
						Node *temp3 = temp2->next;
						Node *temp4 = temp1->prev;
						temp2->prev = temp1->prev;
						temp2->next = temp1;
						temp1->next = temp3;
						temp1->prev = temp2;
						temp4->next = temp2;
						if (temp3 != NULL) {
							temp3->prev = temp1;
						}
						temp3 = temp1;
						temp1 = temp2;
						temp2 = temp3;
					}
					//Head->next = temp2->next;
					
				}
				else{
					//cout << "Running reg swap" << endl;
					if (Head == temp1) {
						Head = temp2;
					}
					Node *temp3 = temp2->next;
					Node *temp4 = temp2->prev;
					Node *temp5 = temp1->prev;
					Node *temp6 = temp1->next;
					temp2->prev = temp1->prev;
					temp2->next = temp1->next;
					temp1->next = temp3;
					temp1->prev = temp4;
					temp4->next = temp1;
					temp6->prev = temp2;
					if (temp5 != NULL) {
						temp5->next = temp2;
					}
					if (temp3 != NULL) {
						temp3->prev = temp1;
					}
					temp3 = temp1;
					temp1 = temp2;
					temp2 = temp3;
					//cout << "reg swap complete" << endl;

				}
				//delete temp4;
			}

			temp2 = temp2->next;
			

		}
		temp1 = temp1->next;
	}

}

void StockAccount::addToStart(Node *n)
{
	//std::cout << "myHead is orginally : " << myHead->getitemNo() << "	" << myHead->getitemName() << std::endl;

	if (Head == NULL) {
		//std::cout << "if statement in add to start firing" << std::endl;
		Head = n;
		//myTail = n;
		n->setnext(NULL);
		mySize++;
		//std::cout << "myHead is now : " << myHead->getitemNo() << "	" << myHead->getitemName() << std::endl;
		//std::cout << "myHead next is now: " << myHead->next->getitemNo() << "	" << myHead->next->getitemName() << std::endl;
	}
	else {
		//std::cout << "myHead is orginally : " << myHead->getitemNo() << "	" << myHead->getitemName() << std::endl;
		n->next = Head;
		Head = n;
		//std::cout << "myHead is now : " << myHead->getitemNo() << "	" << myHead->getitemName() << std::endl;
		//std::cout << "myHead next is now: " << myHead->next->getitemNo() << "	" << myHead->next->getitemName() << std::endl;

		mySize++;
	}
}

void StockAccount::printList()
{
	//std::cout << "printing out list" << std::endl;
	Node *temp = Head;
	if (temp == NULL) {
		std::cout << "printing list is list is empty" << std::endl;
		return;
	}
	std::cout << "Cash Balance:	" << Cash_Balance << std::endl;
	std::cout << "Ticker"<<"	"<<"Shares"<<"	"<<"PricePerShare"<<"	"<<	"TotalValue" << std::endl;
	double TotalValue = 0;
	while (temp != NULL) {
		std::cout << temp->getitemName() <<"	" << temp->getitemNo() <<"	" <<*temp->price<<"		"<<*temp->price*temp->getitemNo()<< std::endl;
		TotalValue = TotalValue + *temp->price*temp->getitemNo();
		temp = temp->next;
	}
	std::cout << "Total Value :	" << TotalValue << std::endl;
}

bool StockAccount::removeFromStart()
{
		if (Head == NULL) {
			std::cout << "list is empty" << std::endl;
			return false;
		}
		else {
			Node *temp = Head;
			Head = Head->next;
			delete temp;
			mySize--;
			return true;
		}
}



void StockAccount::removeNodeFromList(string a)
{
	Node *n = Head;
	if (Head->itemName == a) {
		Head = Head->next;
		mySize--;
		return;
	}
	while (!n->next->itemName.compare(a) && n != NULL) {
		n = n->next;
	}
	if (n == NULL) {
		std::cout << "Item number not found." << std::endl;
		return;
	}
	//if (n->next == myTail) {
		//removeFromEnd();
		//return;
	//}
	n->setnext(n->next->next);
	n = n->next;
	delete n;
	mySize--;
}

void StockAccount::StockHistory(int a, string stock, int share, double price)
{
	time_t seconds;
	seconds = time(NULL);
	tm *timeinfo;
	timeinfo = localtime(&seconds);

	if (a == 1) {
		//sell
		ofstream infile;
		infile.open("Stock_Transaction_History.txt", std::ios::app);
		infile << "Sell	" << stock << "	" << share << "	" << price << "	" << share * price <<"	"<< asctime(timeinfo)<<"\n";
		infile.close();
		ofstream myfile;
		myfile.open("Bank_Transaction_History.txt", std::ios::app);
		myfile << "SELL		" << share*price << "	" << Cash_Balance << "	" << asctime(timeinfo) << "\n";
		myfile.close();
	}
	if (a == 0) {
		//buy
		ofstream infile;
		infile.open("Stock_Transaction_History.txt", std::ios::app);
		infile << "Buy	" << stock << "	" << share << "	" << price << "	" << share * price <<"	"<< asctime(timeinfo) << "\n";
		infile.close();
		ofstream myfile;
		myfile.open("Bank_Transaction_History.txt", std::ios::app);
		myfile << "BUY		" << share*price << "	" << Cash_Balance << "	" << asctime(timeinfo) << "\n";
		myfile.close();
	}

}

void StockAccount::Accountinfo()
{
	ofstream myfile;
	myfile.open("AccountInfo.txt");
	//myfile << Cash_Balance << endl;
	
	std::cout << "printing out list" << std::endl;
	Node *temp = Head;
	if (temp == NULL) {
		std::cout << "printing list is list is empty" << std::endl;
		return;
	}
	myfile << Cash_Balance << std::endl;
	//myfile << "Ticker" << "	" << "Shares" << "	" << "PricePerShare" << "	" << "TotalValue" << std::endl;
	double TotalValue = 0;
	while (temp != NULL) {
		myfile << temp->getitemName() << "	" << temp->getitemNo() /*<< *temp->price << "		" /*<< *temp->price*temp->getitemNo()*/ << std::endl;
		TotalValue = TotalValue + *temp->price*temp->getitemNo();
		temp = temp->next;
	}
	//myfile<< "Total Value :	" << TotalValue << std::endl;
	myfile.close();

	time_t seconds;
	seconds = time(NULL);
	tm *timeinfo;
	timeinfo = localtime(&seconds);

	ofstream mfile;
	mfile.open("ValueHistory.txt", std::ios::app);
	mfile << TotalValue + Cash_Balance << "	" << asctime(timeinfo) << endl;
}

void StockAccount::setprices(string& name, double *p)
{
	cout << "Trying to set price" << endl;
	Node *temp = Head;
	while (temp != NULL && temp->itemName != name) {
		cout << temp->itemName;
		//cout << "Searching" << endl;
		temp = temp->next;
	}
	if (temp != NULL) {
		temp->price = p;
	}
	else {
		return;
	}
}

void StockAccount::startupbuy(string &stock, int share,double*price)
{
	Node *n = new Node(stock, share);
	double *p = price;
	n->setprice(p);
	addToStart(n);
	//place sort algo here
	//Cash_Balance = Cash_Balance - share * *price;
	//StockHistory(0, stock, share, *price);
	//mySize++;
	//update bank and stock transaction sheet here
	//sort();
}

StockAccount::~StockAccount()
{
}
