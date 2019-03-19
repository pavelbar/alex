#include "pch.h"
#include "MString.h"

using  std::endl;
using  std::cout;

MString::MString(const char* arr) : TCharArray(arr)
{
	cout << endl << "!!!DBG MString: Конструктор (const char* arr)" << endl;
}

MString::~MString()
{
	cout << endl << "!!!DBG MString: Деструктор" << endl;
}

size_t MString::Size(void) const
{
	cout << endl << "!!!DBG MString: Size" << endl;
	return len;
}

ostream& operator<<(ostream &ostr, const MString &arr)
{
	cout << endl << "!!!DBG MString: <<";
	ostr << endl << endl << "-> Print MString" << endl;
	ostr << "-> lenght of MString = " << arr.len << endl;
	for (size_t i = 0; i < arr.len; i++) {
		ostr << endl << "-> [" << i << "]= " << arr[i] << endl;
	}
	ostr << "-> end." << endl;
	return ostr;
}
