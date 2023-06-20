/*
File name: BankingCommonDecl.h
Author: Kim Minseo
Last edited: 20/06/2023
Version 0.8
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>

// Menu choice
enum
{
  CREATE = 1,
  DEPOSIT,
  WITHDRAW,
  ENQUIRE,
  EXIT
};

// Credit level
enum
{
  LEVEL_A = 7,
  LEVEL_B = 4,
  LEVEL_C = 2
};

// Types of accounts
enum
{
  NORMAL = 1,
  CREDIT = 2
};

#endif