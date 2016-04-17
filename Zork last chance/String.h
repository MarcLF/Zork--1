#ifndef _MYSTRING_
#define _MYSTRING_

#include<string.h>
#include<stdio.h>
#include"Vector.h"

typedef unsigned int uint;

class MyString
{
private:

	char *buffer = nullptr;
	uint max_size;
public:

	MyString();
	MyString(const char *string);
	MyString(const MyString &other);
	~MyString();

	uint length()const;

	const uint capacity() const;
	const char *c_str() const;

	bool empty()const;
	bool operator==(const MyString &other) const;
	bool operator==(const char *string) const;

	void operator=(const MyString &other);
	void operator=(const char *other);

};

#endif 