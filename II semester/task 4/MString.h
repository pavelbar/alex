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
};
