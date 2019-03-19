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

int MString::GetCountdelim(const char delim) const
{
	int count = 0;
	for (size_t i = 0; i < len; i++) {
		if (pMem[i] == delim) {
			count++;
		}
	}
	return count;
}

MString MString::GetSubString(const int pos) const
{
	if (pos > len) {
		throw ("pos>len...");
	}
	if (pos < 0) {
		throw ("pos<0...");
	}
	size_t nlen = len - pos;
	char* buf = new char[nlen + 1];
	int j = 0;
	for (size_t i = pos; i < len; i++) {
		buf[j] = pMem[i];
		j++;
	}
	buf[nlen] = '\0';
	return MString(buf);
}

int MString::Find(const char symbol) const
{
	for (int i = 0; i < len; i++) {
		if (pMem[i] == symbol) {
			return i;
		}
	}
}

MString MString::GetSubString(const int spos, const int fpos) const
{
	if (fpos > len) {
		throw ("fpos>len...");
	}
	if (fpos < 0) {
		throw ("fpos<0...");
	}
	if (spos > len) {
		throw ("spos>len...");
	}
	if (spos < 0) {
		throw ("spos<0...");
	}
	if (spos > fpos) {
		throw ("spos>fpos...");
	}

	size_t nlen = fpos - spos;
	char* buf = new char[nlen +1];
	int j = 0;
	for (size_t i = spos; i < fpos; i++) {
		buf[j] = pMem[i];
		j++;
	}
	buf[nlen] = '\0';
	return MString(buf);
}
