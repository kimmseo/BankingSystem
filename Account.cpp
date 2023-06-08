/*
File name: Account.cpp
Author: Kim Minseo
Last edited: 08/06/2023
Version 0.7
*/

#include "BankingCommonDecl.h"
#include "Account.h"

// Account Constructor
Account::Account(int id, double startingAmt, std::string inputName)
    : id(id), balance(startingAmt)
{
  std::string *name = new std::string(inputName);
  this->name = name;
}

// Account Copy Constructor
Account::Account(const Account &ref)
    : id(ref.id), balance(ref.balance)
{
  std::string *name = new std::string(*ref.name);
  this->name = name;
}

// Account Destructor
Account::~Account()
{
  delete name;
}

// Account Get methods
int Account::GetID() const
{
  return id;
}

std::string Account::GetName() const
{
  return *name;
}

double Account::GetBalance() const
{
  return balance;
}

// Set methods
void Account::SetID(int id)
{
  this->id = id;
}

void Account::SetName(std::string inputName)
{
  std::string *name = new std::string(inputName);
  this->name = name;
}

void Account::SetBalance(double balance)
{
  this->balance = balance;
}

// Account Public methods

void Account::ShowAccInfo() const
{
  std::cout << "Account ID: " << id << std::endl;
  std::cout << "Name: " << *name << std::endl;
  std::cout << "Balance: " << balance << std::endl
            << std::endl;
}

void Account::Deposit(double money)
{
  if (money <= 0)
  {
    std::cout << "Invalid amount to deposite." << std::endl
              << std::endl;
    return;
  }
  balance += money;
}

void Account::Withdraw(double money)
{
  if (money <= 0)
  {
    std::cout << "Invalid amount to withdraw." << std::endl
              << std::endl;
    return;
  }
  if (money > balance)
  {
    std::cout << "Withdrawal amount out of limit." << std::endl
              << std::endl;
    return;
  }
  balance -= money;
  std::cout << "Current balance: " << balance << std::endl
            << std::endl;
}