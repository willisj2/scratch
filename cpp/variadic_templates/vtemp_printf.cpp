/** vtemp_printf.cpp
 * Experimenting with using variadic templates for
 * passing variable numbers of arguments to a function.
 *
 * Pass variable arguments to printf.
 *
 * Requires C++11.
 * 
 * Compile with: 
 * 		g++ -std=c++11 vtemp_adder.cpp
 */

#include<iostream>
#include<string>
#include<sstream>

#include<stdio.h>

class emotional_printf
{
public:
	template <typename... T>
	void enthusiastic_printf(const char* fmt, T... args)
	{
		std::cout << __PRETTY_FUNCTION__ << "\n";

		std::stringstream ss;
		ss << "Wow!\n" << fmt << "That's pretty neat!\n";
		printf(ss.str().c_str(), args...);
	}

	template <typename... T> // must declare T again
	void bored_printf(const char* fmt, T... args)
	{
		std::cout << __PRETTY_FUNCTION__ << "\n";

		std::stringstream ss;
		ss << "meh\n" << fmt << "I've seen better\n";
		printf(ss.str().c_str(), args...);
	}
};

int main()
{
	emotional_printf emp = emotional_printf();
	emp.enthusiastic_printf("Here's an int (%d)\t a str (%s)\t and a float (%e)\t\n",
			123, "boom", 3.1415);

	emp.bored_printf("Here's an int (%d)\t a str (%s)\t and a float (%e)\t\n",
			123, "boom", 3.1415);
}
