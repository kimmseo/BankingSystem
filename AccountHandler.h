/*
File name: AccountHandler.h
Author: Kim Minseo
Last edited: 20/06/2023
Version 0.9
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

// Control class AccountHandler
class AccountHandler
{
private:
  BoundCheckArray<Account*> accArr; // Array for storing accounts
  int accNum;           // Number of accounts created
public:
  // Constructor
  AccountHandler();

  // Destructor
  ~AccountHandler();

  // Public methods
  void CreateAccount(void);
  void DepositMoney(void);
  void WithdrawMoney(void);
  void ShowAllAccInfo(void);

protected:
  // Protected methods
  void CreateNormalAccount(void);
  void CreateCreditAccount(void);
};

#endif