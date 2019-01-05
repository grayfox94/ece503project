#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "BongioviAccount.h"
class BankAccount :
	public Account
{
public:
	BankAccount();
	void ViewAccountBalance(); //print out cash balance.
	void Deposit(double);	//basic deposit into cash balance. Update Bank_Transaction_History.txt
	void Withdraw(double); //basic withdraw from cash balance. Update Bank_Transaction_History.txt
	void printHistory(); //print out transaction history. must read it from: Bank_Transaction_History.txt
	void writeHistory(int, double);
	~BankAccount();
};

