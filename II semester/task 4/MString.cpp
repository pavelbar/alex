#include "pch.h"
#include "MString.h"

using  std::endl;
using  std::cout;

MString::MString(const char* arr) : TCharArray(arr)
{
	//cout << endl << "!!!DBG MString: Конструктор (const char* arr)" << endl;
}

MString::MString() : TCharArray()
{
	//cout << endl << "!!!DBG MString: Конструктор по умолчанию" << endl;
}

MString::~MString()
{
	//cout << endl << "!!!DBG MString: Деструктор" << endl;
}

size_t MString::Size(void) const
{
	//cout << endl << "!!!DBG MString: Size" << endl;
	return len;
}

ostream& operator<<(ostream &ostr, const MString &arr)
{
	//cout << endl << "!!!DBG MString: <<";
	for (size_t i = 0; i < arr.len; i++) {
		ostr << arr.pMem[i];
	}
	return ostr;
}

char* MString::GetCharArray(void) const
{
	return pMem;
}
