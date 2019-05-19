#pragma once
#include "TCharArray.h"

using  std::ostream;
using  std::istream;

class MString : public TCharArray
{

public:
	size_t Size(void) const;
	MString();
	MString(const char* arr);
	~MString();
	friend ostream &operator<<(ostream &ostr, const MString &s);
	char* GetCharArray(void) const;
	int GetCountdelim(const char delim) const;
	MString GetSubString(const int pos) const;
	int Find(const char symbol) const;
	MString GetSubString(const int spos, const int fpos) const;
	int ToInteger(void) const;
};
