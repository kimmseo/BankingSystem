/*
File name: NormalAccount.h
Author: Kim Minseo
Last edited: 08/06/2023
Version 0.7
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

// Normal Account
class NormalAccount : public Account
{
private:
  int interestRate;

public:
  NormalAccount(int ID, double money, std::string name, int rate)
      : Account(ID, money, name), interestRate(rate)
  {
  }
  virtual void Deposit(double money) override;
};

// Override Deposit function
void NormalAccount::Deposit(double money)
{
  Account::Deposit(money);                          // Deposit initial amount
  Account::Deposit(money * (interestRate / 100.0)); // Deposit interest
}

#endif