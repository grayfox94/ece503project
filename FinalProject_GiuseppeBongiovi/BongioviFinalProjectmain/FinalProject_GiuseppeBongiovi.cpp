// BongioviFinalProjectmain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "BongioviAccount.h"
#include "BongioviBankAccount.h"
#include "BongioviFinalNode.h"
#include "BongioviStockAccount.h"
#include "BongioviStockData.h"
#include <vector>
#include <locale>
#include <stdlib.h>
using namespace std;

int main()
{
   //main function will run portfolio

	vector<StockData> b; //run extraction of results.txt data

	//run extraction of previous data for cash_balance and stock portfolio
	cout << "running extraction" << endl;
	Account A;
	BankAccount B;
	StockAccount C;
	StockData a;

	cout << "setting price pointers" << endl;
	ifstream myfile;
	myfile.open("Result_1.txt");
	while (myfile >> a.name >> a.price >> a.date) {

		//cout << a.name << "	" << a.price << "	" << a.date << endl;
		b.push_back(a);
	}
	myfile.close();
	//startup buy. used to match stock price pointers
	ifstream startupfile;
	startupfile.open("AccountInfo.txt");
	if (startupfile.is_open()) {
		string st;
		int pr;
		startupfile >> A.Cash_Balance;
		while (startupfile >> st >> pr) {
			int i;
			for (i = 0; i < b.size(); i++) {
				if (st.compare(b[i].name) == 0) {
					//std::cout << b[i].name << ":	" << b[i].price << std::endl;
					//found = true;
					break;
				}
			}
			C.startupbuy(st, pr, &b[i].price);
		}
	}
	startupfile.close();
	C.sort();

	int input = 9; //used 9 as a placeholder
	while (input != 0) {
		
		std::cout << std::endl;
		std::cout << "Please Select an Option:" << std::endl;
		std::cout << "1. Stock Portfolio Account" << std::endl;
		std::cout << "2. Bank Account" << std::endl;
		std::cout << "0. Exit Program" << std::endl;
		std::cin >> input;
		if (input == 1) {
			//srand(time(NULL));
			int r = rand() % 2 + 1;
			string str;
			if (r == 1) {
				str = "Result_1.txt";
			}
			else if (r == 2) {
				str = "Result_2.txt";
			}
			ifstream myfile;
			myfile.open(str);
			int count = 0;
			while (myfile >> a.name >> a.price >> a.date) {

				cout << a.name << "	" << a.price << "	" << a.date << endl;
				b[count].price = a.price;
				//C.setprices(a.name, &a.price);
				count++;
			}
			myfile.close();
			int input2 = 9; //used 9 as a placeholder
			while (input2 != 0) {
				C.Accountinfo();
				std::cout << std::endl;
				std::cout << "Please Select an Option for Stock Portfolio Account:" << std::endl;
				std::cout << "1. Display the price for a stock symbol" << std::endl;
				std::cout << "2. Display the current portfolio" << std::endl;
				std::cout << "3. Buy Shares" << std::endl;
				std::cout << "4. Sell Shares" << std::endl;
				std::cout << "5. View a graph for the portfolio value" << std::endl;
				std::cout << "6. View Transaction History" << std::endl;
				std::cout << "0. Return to previous Menu" << std::endl;
				std::cin >> input2;
				if (input2 == 1) {
					//price for stock
					string s;
					bool found = false;
					std::cout << "input ticker symbol" << std::endl;
					std::cin >> s;
					int i;
					for (i = 0; i < b.size(); i++) {
						if (s.compare(b[i].name) == 0) {
							std::cout << b[i].name << ":	"<<b[i].price<<std::endl;
							found = true;
							break;
						}
					}
					if (found == false) {
						std::cout << "Ticker symbol not found" << std::endl;
					}
				}
				else if (input2 == 2) {
					//display portfolio
					C.sort();
					C.printList();
				}
				else if (input2 == 3) {
					//buy shares
					string s;
					bool found = false;
					std::cout << "input ticker symbol" << std::endl;
					std::cin >> s;
					int i;
					for (i = 0; i < b.size(); i++) {
						if (s.compare(b[i].name) == 0) {
							std::cout << b[i].name << ":	" << b[i].price << std::endl;
							found = true;
							break;
						}
					}
					if (found == false) {
						std::cout << "Ticker symbol not found" << std::endl;
					}
					else {
						std::cout << "input how many shares you wish to purchase" << std::endl;
						int sh;
						std::cin >> sh;
						if (sh*b[i].price > A.Cash_Balance) {
							std::cout << "insufficient funds" << std::endl;
							break;
						}
						else {
							C.purchase(b[i].name, sh, &b[i].price);
							//double *p = &b[i].price;
						}

					}
					//C.sort();
					
				}
				else if (input2 == 4) {
					//sell shares
					string s;
					bool found = false;
					std::cout << "input ticker symbol" << std::endl;
					std::cin >> s;
					int i;
					for (i = 0; i < b.size(); i++) {
						if (s.compare(b[i].name) == 0) {
							std::cout << b[i].name << ":	" << b[i].price << std::endl;
							found = true;
							break;
						}
					}
					if (found == false) {
						std::cout << "Ticker symbol not found" << std::endl;
					}
					else {
						std::cout << "input how many shares you wish to sell" << std::endl;
						int sh;
						std::cin >> sh;
						C.sell(b[i].name, sh, b[i].price);

					}
					//C.sort();

				}
				else if (input2 == 5) {
					//view graph of portfolio value
				}
				else if (input2 == 6) {
					//view transaction history
					std::cout << "Event	" << "Ticker	"<<"Shares	"<<"Price	" << "Total	" << "Date\n";
					ifstream myfile;
					myfile.open("Stock_Transaction_History.txt");
					if (myfile.is_open()) {
						string line;
						while (getline(myfile, line)) {
							cout << line << endl;
						}
					}
					else {
						cout << "No Transacion History" << endl;
					}
					
				}
			}
		}
		else if (input == 2) {
			int input2 = 9; //just used 9 as a placeholder
			while (input2 != 0) {
				C.Accountinfo();
				std::cout << std::endl;
				std::cout << "BANK ACCOUNT" << std::endl;
				std::cout << "Please Select an Option:" << std::endl;
				std::cout << "1. View Account Balance" << std::endl;
				std::cout << "2. Deposit Money" << std::endl;
				std::cout << "3. Withdraw Money" << std::endl;
				std::cout << "4. Print Out History" << std::endl;
				std::cout << "0. Return to Previous Menu" << std::endl;
				std::cin >> input2;
				if (input2 == 1) {
					//view account balance
					B.ViewAccountBalance();
				}
				else if (input2 == 2) {
				//deposit money
					std::cout << "Enter How Much to Deposit:" << std::endl;
					double deposit;
					std::cin >> deposit;
					B.Deposit(deposit);

				}
				else if (input2 == 3) {
					//withdraw money
					std::cout << "Enter How Much to Withdraw:" << std::endl;
					double withdraw;
					std::cin >> withdraw;
					B.Withdraw(withdraw);
				}
				else if (input2 == 4) {
					//print out transaction history
					std::cout << "Event	" << "Amount	" << "Cash_Balance	" << "Date\n";
					ifstream myfile;
					myfile.open("Bank_Transaction_History.txt");
					if (myfile.is_open()) {
						string line;
						while (getline(myfile, line)) {
							cout << line << endl;
						}
					}
					else {
						cout << "No Transacion History" << endl;
					}
					//myfile>>cout
				}
				C.Accountinfo();

		
			}
		}
	}
	
}

