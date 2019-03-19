#pragma once
#include "TCharArray.h"
class MString : public TCharArray
{

public:
	size_t Size(void) const;
	MString(const char* arr);
	~MString();
	friend ostream &operator<<(ostream &ostr, const MString &s);
};

