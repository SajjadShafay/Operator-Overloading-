#include <iostream>
#include "Mystring.h"

int main()
{
	std::cout << std::boolalpha << std::endl;
	Mystring a{ "frank" };
	Mystring b{ "frank" };

	std::cout << (a == b) << std::endl; // true
	std::cout << (a != b) << std::endl; // false

	b = "george";
	std::cout << (a == b) << std::endl; // false
	std::cout << (a != b) << std::endl; // true
	std::cout << (a < b) << std::endl; // true
	std::cout << (a > b) << std::endl; //false

	Mystring s1{ "FRANK" };
	s1 = - s1;
	std::cout << s1 << std::endl; // frank

    s1 = s1 + "*****";
    std::cout << s1 << std::endl;               // frank*****       

    s1 += "-----";                        // frank*****-----
    std::cout << s1 << std::endl;

    Mystring s2{ "12345" };
    s1 = s2 * 3;
    std::cout << s1 << std::endl;              // 123451234512345

    Mystring s3{ "abcdef" };
    s3 *= 5;
    std::cout << s3 << std::endl;             // abcdefabcdefabcdefabcdefabcdef

	return 0;
}