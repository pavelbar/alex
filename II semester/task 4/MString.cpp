#include "pch.h"
#include "MString.h"

MString::MString(const char* arr) : TCharArray(arr)
{
}

MString::MString() : TCharArray()
{
}

MString::~MString()
{
}

size_t MString::Size(void) const
{
	return len;
}

ostream& operator<<(ostream &ostr, const MString &arr)
{
	for (size_t i = 0; i < arr.len; i++) {
		ostr << arr.pMem[i];
	}
	return ostr;
}

char* MString::GetCharArray(void) const
{
	return pMem;
}
