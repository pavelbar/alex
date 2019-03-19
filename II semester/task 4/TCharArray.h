#pragma once

#include <iostream>

class TCharArray
{
protected:
	char *pMem;
	size_t  len;

public:
	TCharArray(const char* arr);
	TCharArray(const int len);//+
	TCharArray(const TCharArray &arr);//КК
	TCharArray();//КПУ
	~TCharArray();

	size_t GetStrLen(const char* str);
	char& At(const int n) const;
	char& operator[] (const int n) const;
	int operator==(const TCharArray &arr) const;
	int operator!=(const TCharArray &arr) const;
	TCharArray& operator=(const TCharArray &arr);
	TCharArray operator+ (const TCharArray &arr);
	int operator<(const TCharArray &arr) const;
	int operator>(const TCharArray &arr) const;
	
};

