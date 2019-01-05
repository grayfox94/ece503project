#pragma once
class Account
{
public:
	Account(); //will read transaction history to determine Cash_Balance.
	Account(double);
	~Account();
	static double Cash_Balance;
};

