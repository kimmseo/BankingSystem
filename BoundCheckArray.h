/*
Banking System Vers 0.9
File name: BoundCheckArray.h
Author: Kim Minseo
Last edited: 09/08/2023
*/

#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include <iostream>

template <class T>
class BoundCheckArray
{
private:
  T *arr;
  int arrlen;
  BoundCheckArray(const BoundCheckArray &arr) {}
  BoundCheckArray &operator=(const BoundCheckArray &arr) {}

public:
  BoundCheckArray(int len = 100);
  T &operator[](int idx);
  T operator[](int idx) const;
  int GetArrLen() const;
  ~BoundCheckArray();
};

template <class T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
  arr = new T[len];
}

template <class T>
T &BoundCheckArray<T>::operator[](int idx)
{
  if (idx < 0 || idx >= arrlen)
  {
    std::cout << "Array index out of bound exception." << std::endl;
    exit(1);
  }
  return arr[idx];
}

template <class T>
T BoundCheckArray<T>::operator[](int idx) const
{
  if (idx < 0 || idx >= arrlen)
  {
    std::cout << "Array index out of bound exception." << std::endl;
    exit(1);
  }
  return arr[idx];
}

template <class T>
int BoundCheckArray<T>::GetArrLen() const
{
  return arrlen;
}

template <class T>
BoundCheckArray<T>::~BoundCheckArray()
{
  delete[] arr;
}

#endif