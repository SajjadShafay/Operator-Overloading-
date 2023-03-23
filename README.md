# Section 14 Challenge
## Operator Overloading
-------------------------
Overload the following operators in the provided Mystring class.

To gain experience overloading operators, you should do this challenge twice.
First, overload the operators using member functions and then in another project overload the same operators again
using non-member functions.

Please do it once using member methods and then again using non-member methods.

Here is a list of some of the operators that you can overload for this class:

"- -" unary minus. Returns the lowercase version of the object's string /n
	-s1 /n
"== -" returns true if the two strings are equal /n
	(s1 == s2) /n
"!= -" returns true if the two strings are not equal /n
	(s1 != s2) /n
"< -" returns true if the lhs string is lexically less than the rhs string /n 
	(s1 < s2) /n
"> -" returns true if the lhs string is lexically greater than the rhs string /n
	(s1 > s2) /n
"+ -" concatenation. Returns an object that concatenates the lhs and rhs /n
	s1 + s2 /n
"+= -" concatenate the rhs string to the lhs string and store the result in lhs object /n
	s1 += s2;  equivalent to s1 = s1 + s2; /n
"* -" repeat - results in a string that is copied n times /n
	s2 * 3; ex). s2 = "abc"; /n
					s1 = s2 * 3; /n
					s1 will result in "abcabcabc"/n
"*= -" repeat the string on the lhs n times and store the result back in the lhs object /n
	s1 = "abc"; /n
	s1 *= 4;   s1 will result in "abcabcabcabc" /n

If you wish to overload the ++ and -- operators, remember that they have pre and post versions.
The semantics should be as follows (this shows the member method version):

Mystring &operator++() { // pre-increment
	// do what ever you want increment to do - maybe make all characters uppercase?
	return *this;
}

// Note that post-increment returns a Mystring by value not by reference 
Mystring operator++(int) { // post-increment
	Mystring temp (*this);  // make a copy
	operator++();   // call pre-increment - make sure you call pre-increment!
	return temp   // return by the old value
}

Have fun! Think of some other operators that might be useful!
Don't worry if they all don't  make sense -- this is an exercise about learning how to overload operators.

Hints:
1. Take advantage of the std::strcmp function for the equality operators!
2. The += and *= operators should return a Mystring &
3. Rather than duplicate code in the += and *= functions, use the + and * operators which you have already overloaded!