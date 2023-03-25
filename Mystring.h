#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <ostream>     // Include to make std::ostream work
#include <istream>     // Include to make std::istream work

class Mystring
{
	friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);   // friend function passes output stream by value because we are changing it and want it to stay changed. 
	friend std::istream& operator>>(std::istream& in, Mystring& rhs); // same as above but rhs is not const because we want to change the rhs variable. 
	friend Mystring operator-(Mystring &lhs);
	friend bool operator== (const Mystring& lhs, const Mystring& rhs); 
	friend bool operator!= (const Mystring& lhs, const Mystring& rhs); 
	friend bool operator< (const Mystring& lhs, const Mystring& rhs); 
	friend bool operator> (const Mystring& lhs, const Mystring& rhs); 
	friend Mystring operator+ (const Mystring& lhs, const Mystring& rhs); 
	friend Mystring& operator+= (Mystring& lhs, const Mystring& rhs); 
	friend Mystring operator* (const Mystring& lhs, int num);
	friend Mystring& operator*= (Mystring& lhs, int num); 
private:
	char* str;  // pointer to a char[] that holds a C-style string. Points to the first character of a string. If you dereference then you will only get that first character
public:
	Mystring();  // No-args constructor
	Mystring(const char* s);  // overloaded constructor  // normal c-style string that we don't want to change
	Mystring(const Mystring& source); // Copy constructor 
	Mystring(Mystring&& source); // Move constructor
	~Mystring(); // Destructor

	Mystring& operator=(const Mystring& rhs); // copy assignment - returns the address of a Mystring object
	Mystring& operator=(Mystring&& rhs); // Move assignment - returns the address of a Mystring object

	void display() const;

	int get_length() const;
	const char* get_str() const;
};

#endif // _MYSTRING_H_