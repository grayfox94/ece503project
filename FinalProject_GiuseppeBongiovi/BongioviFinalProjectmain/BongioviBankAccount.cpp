
#include "pch.h"
#include "BongioviBankAccount.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h> //needed for transaction history
using namespace std;


BankAccount::BankAccount()
{
}

void BankAccount::ViewAccountBalance()
{
	std::cout << "Account Balance: $" << Cash_Balance << std::endl;
}

void BankAccount::Deposit(double cash)
{
	Cash_Balance = Cash_Balance + cash;
	writeHistory(1, cash);
	return;

}

void BankAccount::Withdraw(double cash)
{
	if (cash > Cash_Balance) {
		std::cout << "Withdrawal limit is : $" << Cash_Balance << std::endl;
	}
	else {
		Cash_Balance = Cash_Balance - cash;
		writeHistory(0, cash);
		
		return;
	}
}

void BankAccount::printHistory()
{

}
void BankAccount::writeHistory(int a,double cash) {
	time_t seconds;
	seconds = time(NULL);
	tm *timeinfo;
	timeinfo = localtime(&seconds);
	
	if (a == 1) {
		//deposit
		ofstream myfile;
		myfile.open("Bank_Transaction_History.txt", std::ios::app);
		myfile << "Deposit		" << cash << "	" << Cash_Balance << "	" << asctime(timeinfo) << "\n";
		myfile.close();
	}
	if (a == 0) {
		//withdraw
		ofstream myfile;
		myfile.open("Bank_Transaction_History.txt", std::ios::app);
		myfile << "Withdrawal	" << cash << "	" << Cash_Balance << "	" << asctime(timeinfo) << "\n";
		myfile.close();
	}
}


BankAccount::~BankAccount()
{
}
