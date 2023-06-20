/*
File name: Account.h
Author: Kim Minseo
Last edited: 20/06/2023
Version 0.8
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <string>
using std::string;

// Entity class Account
class Account
{
private:
  int id;
  std::string name;
  double balance;

public:
  Account(int id, double startingAmt, std::string inputName);
  Account &operator=(const Account &ref);

  int GetID() const;
  std::string GetName() const;
  double GetBalance() const;
  void SetID(int id);
  void SetName(std::string inputName);
  void SetBalance(double balance);
  void ShowAccInfo() const;
  virtual void Deposit(double money);
  void Withdraw(double money);
};

#endif