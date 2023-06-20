/*
File name: AccountHandler.cpp
Author: Kim Minseo
Last edited: 20/06/2023
Version 0.8
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : accNum(0)
{
}

AccountHandler::~AccountHandler()
{
  for (int i = 0; i < accNum; i++)
    delete accArr[i];
}

void AccountHandler::CreateAccount(void)
{
  int selection;

  std::cout << "Which type of account do you wish to create?" << std::endl;
  std::cout << "1. Normal account ";
  std::cout << "2. High credit account" << std::endl;
  std::cout << "Choice: ";
  std::cin >> selection;
  std::cout << std::endl;

  if (selection == NORMAL)
    CreateNormalAccount();
  else
    CreateCreditAccount();
}

void AccountHandler::CreateNormalAccount(void)
{
  int id, interestRate;
  std::string name;
  double balance;

  std::cout << "Creating normal account..." << std::endl;
  std::cout << "Enter account ID: ";
  std::cin >> id;
  std::cout << "Enter name: ";
  std::cin >> name;
  std::cout << "Enter starting balance: ";
  std::cin >> balance;
  std::cout << "Enter interest rate: ";
  std::cin >> interestRate;
  std::cout << std::endl;

  accArr[accNum++] = new NormalAccount(id, balance, name, interestRate);
}

void AccountHandler::CreateCreditAccount(void)
{
  int id, interestRate, creditLevel;
  std::string name;
  double balance;

  std::cout << "Creating high credit account..." << std::endl;
  std::cout << "Enter account ID: ";
  std::cin >> id;
  std::cout << "Enter name: ";
  std::cin >> name;
  std::cout << "Enter starting balance: ";
  std::cin >> balance;
  std::cout << "Enter interest rate: ";
  std::cin >> interestRate;
  std::cout << "Enter credit level (A:1, B:2, C:3): ";
  std::cin >> creditLevel;
  std::cout << std::endl;

  switch (creditLevel)
  {
  case 1:
    accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_A);
    break;
  case 2:
    accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_B);
    break;
  case 3:
    accArr[accNum++] = new HighCreditAccount(id, balance, name, interestRate, LEVEL_C);
  }
}

void AccountHandler::DepositMoney(void)
{
  int id;
  double money;
  bool found = false;

  std::cout << "Enter account ID: ";
  std::cin >> id;
  for (int i = 0; i < accNum; i++)
  {
    if (id == accArr[i]->GetID())
    {
      found = true;
      std::cout << "Enter amount to deposit: ";
      std::cin >> money;
      accArr[i]->Deposit(money);
      std::cout << "Current balance: " << accArr[i]->GetBalance() << std::endl
                << std::endl;
      break;
    }
  }
  if (!found)
  {
    std::cout << "Account ID not found." << std::endl
              << std::endl;
  }
}

void AccountHandler::WithdrawMoney(void)
{
  int id;
  double money;
  bool found = false;

  std::cout << "Enter account ID: ";
  std::cin >> id;
  for (int i = 0; i < accNum; i++)
  {
    if (id == accArr[i]->GetID())
    {
      found = true;
      std::cout << "Enter amount to withdraw: ";
      std::cin >> money;
      accArr[i]->Withdraw(money);
      break;
    }
  }
  if (!found)
  {
    std::cout << "Account ID not found." << std::endl
              << std::endl;
  }
}

void AccountHandler::ShowAllAccInfo(void)
{
  if (accNum == 0)
  {
    std::cout << "No accounts to show." << std::endl
              << std::endl;
    return;
  }
  for (int i = 0; i < accNum; i++)
  {
    accArr[i]->ShowAccInfo();
    std::cout << std::endl;
  }
}