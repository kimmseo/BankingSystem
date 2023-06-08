/*
Banking System Vers 0.7
File name: BankingSystemMain.cpp
Author: Kim Minseo
Last edited: 08/06/2023
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

void menu(void)
{
  std::cout << "======Menu======" << std::endl;
  std::cout << "1. Create Account" << std::endl;
  std::cout << "2. Deposit" << std::endl;
  std::cout << "3. Withdraw" << std::endl;
  std::cout << "4. Show All Account Info" << std::endl;
  std::cout << "5. Exit" << std::endl;
}

int main(void)
{
  AccountHandler manager;
  int choice;

  while (1)
  {
    menu();
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cout << std::endl;

    switch (choice)
    {
    case CREATE:
      manager.CreateAccount();
      break;
    case DEPOSIT:
      manager.DepositMoney();
      break;
    case WITHDRAW:
      manager.WithdrawMoney();
      break;
    case ENQUIRE:
      manager.ShowAllAccInfo();
      break;
    case EXIT:
      return 0;
    default:
      std::cout << "Illegal selection." << std::endl;
    }
  }
  return 0;
}