// FizzBuzz_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

enum FizzBuzz_id_E
{
	NONFIZZBUZZ,
	FIZZ,
	BUZZ,
	FIZZBUZZ
};
/*
example let number = [1,2,3,4,5]

Fizz and Buzz refer to any number that's a multiple of 3 and 5 respectively. In other words, if a number is divisible
by 3, it is substituted with fizz; if a number is divisible by 5, it is substituted with buzz. If a number is simultaneously
a multiple of 3 AND 5, the number is replaced with "fizz buzz." In essence, it emulates the famous children game
"fizz buzz".

*/

FizzBuzz_id_E CheckNumber(int num, int fizz, int buzz)
{
	FizzBuzz_id_E result ;

	if ((num % fizz == 0) && (num % buzz == 0))
	{
		result = FIZZBUZZ;
	}
	else if (num % fizz == 0)
	{
		result = FIZZ;
	}
	else if (num % buzz == 0)
	{
		result = BUZZ;
	}
	else
	{
		result = NONFIZZBUZZ;
	}
	return result;
}

int main()
{
	FizzBuzz_id_E result = CheckNumber(3,3,5);
	cout << result;
	system("pause");
    return 0;
}

