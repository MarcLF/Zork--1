#include<string.h>
#include"String.h"

MyString::MyString()
{
	max_size = 1;
	buffer = new char[max_size];
	strcpy_s(buffer, max_size, "");
}

MyString::MyString(const char *string)
{
	uint len = strlen(string);
	buffer = new char[len + 1];
	max_size = len + 1;
	strcpy_s(buffer, max_size, string);
}
MyString::MyString(const MyString &other)
{
	max_size = other.max_size;
	buffer = new char[max_size];
	strcpy_s(buffer, max_size, other.buffer);
}


const char* MyString::c_str() const
{
	return buffer;
}

uint MyString::length() const
{
	return strlen(buffer);
}

const uint MyString::capacity() const
{
	return max_size;
}

bool MyString::empty()const
{
	return buffer[0] == 0;
}

bool MyString::operator==(const MyString &other) const
{
	return _stricmp(buffer, other.buffer) == 0;
}

bool MyString::operator==(const char *string) const
{
	return _stricmp(buffer, string) == 0;
}

void MyString::operator=(const MyString &other)
{
	if (max_size < other.length() + 1)
	{
		delete[] buffer;
		max_size = other.length() + 1;
		buffer = new char[max_size];
	}
	strcpy_s(buffer, max_size, other.buffer);
}

void MyString::operator=(const char *other)
{
	uint len = strlen(other);
	if (max_size < len + 1)
	{
		delete[] buffer;
		max_size = len + 1;
		buffer = new char[max_size];
	}
	strcpy_s(buffer, max_size, other);
}

MyString::~MyString()
{
	delete[] buffer;
}