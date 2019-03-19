#include "pch.h"
#include "TCharArray.h"
#include <stdio.h>//NULL
#include <iostream>

using  std::endl;
using  std::cout;

TCharArray::~TCharArray()
{
	if (pMem != NULL) {
		delete[]pMem;
		pMem = NULL;
	}
	if (pMem) {
		cout << "Error clean " << pMem << endl;
	}
}

TCharArray::TCharArray() : len(0)
{
}

TCharArray::TCharArray(const char* arr)//+1
{
	len = (*this).GetStrLen(arr);
	pMem = new char[len];
	if (pMem != NULL)
		for (size_t i = 0; i < len; i++) {
			pMem[i] = arr[i];
		}
}

TCharArray::TCharArray(const int nlen) : len(nlen)
{
	//cout << endl << "!DBG TCharArray: Конструктор (const int len)";
	if (len <= 0) {
		len = 0;
		throw ("Len<0...");
	}
	pMem = new char[len];
	if (pMem != NULL)
		for (size_t i = 0; i < len; i++) {
			pMem[i] = '\0';
		}
}

TCharArray::TCharArray(const TCharArray & arr)
{
	//cout << endl << "!DBG TCharArray: Конструктор копирования: (const TCharArray & arr)";
	len = arr.len;
	pMem = new char[len];
	if (pMem != NULL) {
		for (size_t i = 0; i < len; i++) {
			pMem[i] = arr.pMem[i];
		}
	}
}

size_t TCharArray::GetStrLen(const char* str)
{
	//cout << endl << "!DBG TCharArray: GetStrLen";
	const char *eos = str;
	while (*eos++);
	return((int)(eos - str - 1));
}

char& TCharArray::At(const int n) const
{
	//cout << endl << "!DBG TCharArray: At";
	if (n < 0) {
		throw ("n < 0...");
	}
	if (n >= len) {
		throw ("Len < n...");
	}
	return pMem[n];
}

char& TCharArray::operator[] (const int n) const
{
	//cout << endl << "!DBG TCharArray: []";
	return (*this).At(n);
}

int TCharArray::operator==(const TCharArray &arr) const
{
	//cout << endl << "!DBG TCharArray: ==";
	int result = 1;
	if (len != arr.len) {
		result = 0;
	}
	else
		for (size_t i = 0; i < len; i++) {
			if (pMem[i] != arr.pMem[i]) {
				result = 0;
				break;
			}
		}
	return result;
}

int TCharArray::operator!=(const TCharArray &arr) const
{
	//cout << endl << "!DBG TCharArray: !=";
	if (*this == arr) {
		return 0;
	}
	else {
		return 1;
	}
}

TCharArray & TCharArray::operator=(const TCharArray & arr)
{
	//cout << endl << "!DBG TCharArray: =";
	if (pMem != arr.pMem) {
		len = arr.len;
		delete[]pMem;
		pMem = new char[len];
		for (size_t i = 0; i < len; i++) {
			pMem[i] = arr.pMem[i];
		}
	}
	return *this;
}

TCharArray TCharArray::operator+(const TCharArray &arr)
{
	//cout << endl << "!DBG TCharArray: +";
	TCharArray newArr(len + arr.len);
	for (size_t i = 0; i < len; i++)
	{
		newArr.pMem[i] = pMem[i];
	}
	for (size_t i = 0; i < arr.len; i++)
	{
		newArr.pMem[len + i] = arr.pMem[i];
	}

	return newArr;
}

int TCharArray::operator<(const TCharArray &arr) const
{
	//cout << endl << "!DBG TCharArray: <";
	int result = 1;
	if (len > arr.len) {
		result = 0;
	}
	return result;
}

int TCharArray::operator>(const TCharArray &arr) const
{
	//cout << endl << "!DBG TCharArray: >";
	if (*this < arr) {
		return 0;
	}
	else {
		return 1;
	}
}

