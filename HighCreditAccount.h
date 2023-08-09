/*
File name: HighCreditAccount.h
Author: Kim Minseo
Last edited: 20/06/2023
Version 0.9
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

// High Credit Account
class HighCreditAccount : public NormalAccount
{
private:
  int specialInterestRate;

public:
  HighCreditAccount(int ID, double money, std::string name, int rate, int specialRate)
      : NormalAccount(ID, money, name, rate), specialInterestRate(specialRate)
  {
  }
  virtual void Deposit(double money) override;
};

// Override Deposit function
void HighCreditAccount::Deposit(double money)
{
  NormalAccount::Deposit(money);                           // Deposit initial amount + normal interest
  Account::Deposit(money * (specialInterestRate / 100.0)); // Deposit special interest
}

#endif