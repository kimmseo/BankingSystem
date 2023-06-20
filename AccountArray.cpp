/*
File name: AccountArray.cpp
Author: Kim Minseo
Last edited: 20/06/2023
Version 0.8
*/

#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) : arrlen(len)
{
  arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR &BoundCheckAccountPtrArray::operator[](int idx)
{
  if (idx < 0 || idx >= arrlen)
  {
    std::cout << "Array index out of bound exception" << std::endl;
    exit(1);
  }
  return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int idx) const
{
  if (idx < 0 || idx >= arrlen)
  {
    std::cout << "Array index out of bound exception" << std::endl;
    exit(1);
  }
  return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const
{
  return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
  delete[] arr;
}