#pragma once

#include <iostream>

using std::ostream;

class TCharArray
{
private:
	int  len;
	char *pMem;

protected:
	size_t GetStrLen(const char* str);

public:
	TCharArray(const char* arr);
	TCharArray(const int len);
	TCharArray(const TCharArray &arr);//КК
	TCharArray();//КПУ
	~TCharArray();
	int Size(void) const;
	char& At(const int n) const;
	char& operator[] (const int n) const;
	int operator==(const TCharArray &arr) const;
	int operator!=(const TCharArray &arr) const;
	friend ostream &operator<<(ostream &ostr, const TCharArray &arr);
	TCharArray& operator=(const TCharArray &arr);
	TCharArray operator+ (const TCharArray &arr);
	int operator<(const TCharArray &arr) const;
	int operator>(const TCharArray &arr) const;
};

