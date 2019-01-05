#include "pch.h"
#include "BongioviAccount.h"

double Account::Cash_Balance = 10000;
Account::Account()
{

}

Account::Account(double startup)
{
	Cash_Balance = startup;
}

Account::~Account()
{
}
