#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <ostream>
#include <istream>

class Mystring
{
	friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
	friend std::istream& operator>>(std::istream& in, Mystring& rhs);
private:
	char* str;  // pointer to a char[] that holds a C-style string
public:
	Mystring();  // No-args constructor
	Mystring(const char* s);  // overloaded constructor
	Mystring(const Mystring& source); // Copy constructor
	Mystring(Mystring&& source); // Move constructor
	~Mystring(); // Destructor

	Mystring& operator=(const Mystring& rhs); // copy assignment
	Mystring& operator=(Mystring&& rhs); // Move assignment

	void display() const;

	int get_length() const;
	const char* get_str() const;

	Mystring operator- () const; 
	bool operator== (const Mystring& rhs) const;
	bool operator!= (const Mystring& rhs) const;
	bool operator< (const Mystring& rhs) const;
	bool operator> (const Mystring& rhs) const;
	Mystring operator+ (const Mystring& rhs) const;
	Mystring& operator+= (const Mystring& rhs); 
	Mystring operator* (int num) const;
	Mystring& operator*= (int num); 
};

#endif // _MYSTRING_H_