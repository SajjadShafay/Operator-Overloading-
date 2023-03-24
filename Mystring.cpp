#include "Mystring.h"
#include <iostream>
#include <cstring>

//no-args constructor
Mystring::Mystring() : str{ nullptr } // initialise the objects str pointer to null 
{
	str = new char[1];  // point to a new char array that will hold a string terminator
	*str = '\0'; // string terminator
}

//overloaded constructor
Mystring::Mystring(const char* s) : str{ nullptr }
{
	if (s == nullptr)
	{
		str = new char[1];          // if s is a pointer pointing to null
		*str = '\0'; 
	}
	else
	{
		str = new char[strlen(s) + 1];  // create a new char array that is 1 more than the size of s
		strcpy(str, s); // copy the contents of s into str. 
	}
}

//Copy constructor
Mystring::Mystring(const Mystring& source) : str{ nullptr }
{
	str = new char[strlen(source.str) + 1];   
	strcpy(str, source.str);
	std::cout << "Copy constructor used" << std::endl;
}

//Move constructor
Mystring::Mystring(Mystring&& source) : str{ source.str }
{
	source.str = nullptr;
	std::cout << "Move constructor used" << std::endl;
}

//Destructor
Mystring::~Mystring()
{
	delete[] str;
}

//Copy assignment
Mystring& Mystring::operator= (const Mystring& rhs)
{
	std::cout << "Using copy assignment" << std::endl;

	if (this == &rhs)  // check for self assignment
		return *this;
	delete[] str;  // empty out the contents of str
	str = new char[strlen(rhs.str) + 1]; // set str to a new char that is the length of rhs.str + 1 for the string terminator
	strcpy(str, rhs.str); // copy the contents of rhs.str into str 
	return *this; // return the actual object. 
}

//Move assignment
Mystring& Mystring::operator= (Mystring&& rhs) 
{
	std::cout << "Using move assignment" << std::endl;  // 
	if (this == &rhs)
		return *this;   // check if the address of this object is the same as the address for the rhs object for self assignment
	delete[] str; // empty out the contents of str
	str = rhs.str; // set the str of this object to the same value of the str of the rhs object 
	rhs.str = nullptr; // set the str pointer of the rhs object to null 
	return *this; // return this actual object
}

//Display method
void Mystring::display() const
{
	std::cout << str << " : " << get_length() << std::endl;
}

//getters
int Mystring::get_length() const { return strlen(str); }
const char* Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Mystring& rhs) {
	os << rhs.str;
	return os;
}

// overloaded extraction operator
std::istream& operator>>(std::istream& in, Mystring& rhs) {
	char* buff = new char[1000];
	in >> buff;
	rhs = Mystring{ buff };
	delete[] buff;
	return in;
}

Mystring Mystring::operator-() const {
	char* buff = new char[std::strlen(str) + 1];
	std::strcpy(buff, str);
	for (size_t i = 0; i < std::strlen(buff); i++)
		buff[i] = std::tolower(buff[i]);
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

bool Mystring::operator== (const Mystring& rhs) const
{
	if (strcmp(str, rhs.str) == 0)
		return true;
	return false;
}

bool Mystring::operator!= (const Mystring& rhs) const
{
	if (strcmp(str, rhs.str) != 0)
		return true;
	return false;
}

bool Mystring::operator< (const Mystring& rhs) const
{
	if (strcmp(str, rhs.str) < 0)
		return true;
	return false;
}

bool Mystring::operator> (const Mystring& rhs) const
{
	if (strcmp(str, rhs.str) > 0)
		return true;
	return false;
}

Mystring Mystring::operator+ (const Mystring& rhs) const
{
	size_t buff_size{ std::strlen(str) + std::strlen(rhs.str) };
	char* buff = new char[buff_size + 1];
	std::strcpy(buff, str);
	std::strcat(buff, rhs.str); 
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

Mystring& Mystring::operator+= (const Mystring& rhs)
{
	size_t buff_size{ std::strlen(str) + std::strlen(rhs.str) };
	char* buff = new char[buff_size + 1];
	std::strcpy(buff, str); 
	std::strcat(buff, rhs.str); 
	delete[] str; 
	str = buff;
	return *this;
}

Mystring Mystring::operator* (int num) const
{
	size_t buff_size{ std::strlen(str) * num };
	char* buff = new char[buff_size + 1]; 
	for (int i = 0; i < num; i++)
		std::strcpy(buff, str); 
	Mystring temp{ buff }; 
	delete[] buff; 
	return temp; 
}

Mystring& Mystring::operator*= (int num)
{
	size_t buff_size{ std::strlen(str) * num }; 
	char* buff = new char[buff_size + 1]; 
	for (int i = 0; i < num; i++)
		std::strcpy(buff, str); 
	delete[] str;
	str = buff;
	return *this;
}
