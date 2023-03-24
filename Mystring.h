#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <ostream>     // Include to make std::ostream work
#include <istream>     // Include to make std::istream work

class Mystring
{
	friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);   // friend function passes output stream by value because we are changing it and want it to stay changed. 
	friend std::istream& operator>>(std::istream& in, Mystring& rhs); // same as above but rhs is not const because we want to change the rhs variable. 
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

	Mystring operator- () const; // this is the unary - operator. If there was something in the brackets then it would be the binary version. Returns a Mystring object. 
	bool operator== (const Mystring& rhs) const; // is a bool because it returns true or false. Just a comparison. ends with const because we are changing nothing. 
	bool operator!= (const Mystring& rhs) const; // same as above
	bool operator< (const Mystring& rhs) const; // same as above
	bool operator> (const Mystring& rhs) const; // same as above
	Mystring operator+ (const Mystring& rhs) const; // Returns a Mystring object. Const because we will store the result in a new object and not change either of the ones used. 
	Mystring& operator+= (const Mystring& rhs); // Self assignment. 
	Mystring operator* (int num) const; // Returns a Mystring object. Const because we will store the result in a new object and not change either of the ones used. 
	Mystring& operator*= (int num); // Self assignment
};

#endif // _MYSTRING_H_