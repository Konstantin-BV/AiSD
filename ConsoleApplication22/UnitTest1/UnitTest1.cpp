#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include "pch.h"
#include "CppUnitTest.h"
#include <C:\Users\Костя\source\repos\ConsoleApplication22\UnitTest1\Header.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		char c[30];
		TEST_METHOD(TestMethod1)
		{
			c[0] = '1';
			c[1] = '+';
			c[2] = '1';
			Assert::AreEqual(calculator(c), (double)2);
		}
		TEST_METHOD(TestMethod2)
		{
			c[0] = '2';
			c[1] = '*';
			c[2] = '(';
			c[3] = '2';
			c[4] = '+';
			c[5] = '2';
			c[6] = ')';
			Assert::AreEqual(calculator(c), (double)8);
		}
		TEST_METHOD(TestMethod3)
		{
			c[0] = '2';
			c[1] = '*';
			c[2] = '(';
			c[3] = '2';
			c[4] = '+';
			c[5] = '2';
			c[6] = ')';
			c[7] = '+';
			c[8] = '2';
			Assert::AreEqual(calculator(c), (double)10);
		}
		TEST_METHOD(TestMethod4)
		{
			c[0] = '2';
			c[1] = '*';
			c[2] = '(';
			c[3] = '2';
			c[4] = '+';
			c[5] = '2';
			c[6] = ')';
			c[7] = '*';
			c[8] = '(';
			c[9] = '1';
			c[10] = '+';
			c[11] = '2';
			c[12] = ')';
			Assert::AreEqual(calculator(c), (double)24);
		}
		TEST_METHOD(TestMethod5)
		{
			c[0] = 's';
			c[1] = 'i';
			c[2] = 'n';
			c[3] = 'p';
			c[4] = 'i';
			Assert::AreEqual(calculator(c), (double)0);
		}
		TEST_METHOD(TestMethod6)
		{
			c[0] = 'c';
			c[1] = 'o';
			c[2] = 's';
			c[3] = 'p';
			c[4] = 'i';
			Assert::AreEqual(calculator(c), (double)1);
		}
		TEST_METHOD(TestMethod7)
		{
			c[0] = '(';
			c[1] = 'c';
			c[2] = 'o';
			c[3] = 's';
			c[4] = '1';
			c[5] = ')';
			Assert::AreEqual(calculator(c), cos(1));
		}
		TEST_METHOD(TestMethod8)
		{
			c[0] = 'c';
			c[1] = 'o';
			c[2] = 's';
			c[3] = '1';
			c[4] = '^';
			c[5] = '2';
			Assert::AreEqual(calculator(c), cos(1)*cos(1));
		}
		TEST_METHOD(TestMethod9)
		{
			c[0] = 'l';
			c[1] = 'o';
			c[2] = 'g';
			c[3] = '1';
			Assert::AreEqual(calculator(c), log(1));
		}
		TEST_METHOD(TestMethod10)
		{
			c[0] = 'l';
			c[1] = 'o';
			c[2] = 'g';
			c[3] = '1';
			c[4] = '^';
			c[5] = '2';
			Assert::AreEqual(calculator(c), log(1) * log(1));
		}
		TEST_METHOD(TestMethod11)
		{
			c[0] = '1';
			c[1] = '+';
			c[2] = '1';
			Assert::AreEqual(check(c),-1);
		}
		TEST_METHOD(TestMethod12)
		{
			c[0] = '2';
			c[1] = '*';
			c[2] = '+';
			c[3] = '2';
			c[4] = '+';
			c[5] = '2';
			Assert::AreEqual(check(c), 2);
		}
		TEST_METHOD(TestMethod13)
		{
			c[0] = '2';
			c[1] = '.';
			c[2] = '1';
			c[3] = '2';
			c[4] = '+';
			c[5] = '2';
			c[6] = '4';
			c[7] = '+';
			c[8] = '2';
			Assert::AreEqual(check(c), -1);
		}
		TEST_METHOD(TestMethod14)
		{
			c[0] = 's';
			c[1] = 'i';
			c[2] = 'n';
			c[3] = '2';
			c[4] = '+';
			c[5] = '2';
			c[6] = '1';
			c[7] = '+';
			c[8] = '2';
			Assert::AreEqual(check(c), -1);
		}
		TEST_METHOD(TestMethod15)
		{
			c[0] = 'c';
			c[1] = 't';
			c[2] = 'g';
			c[3] = 'p';
			c[4] = 'i';
			Assert::AreEqual(check(c), -1);
		}
		TEST_METHOD(TestMethod16)
		{
			c[0] = 'c';
			c[1] = 'o';
			c[2] = 's';
			c[3] = 'p';
			c[4] = 'i';
			c[5] = '-';
			c[6] = 'l';
			c[7] = 'o';
			c[8] = 'g';
			Assert::AreEqual(check(c), 6);
		}
		TEST_METHOD(TestMethod17)
		{
			c[0] = '(';
			c[1] = 'c';
			c[2] = 'o';
			c[3] = 's';
			c[4] = '1';
			c[5] = ')';
			c[5] = '^';
			c[5] = '2';
			Assert::AreEqual(check(c), -1);
		}
		TEST_METHOD(TestMethod18)
		{
			c[0] = 'e';
			c[1] = '^';
			c[5] = '2';
			Assert::AreEqual(check(c), -1);
		}
		TEST_METHOD(TestMethod19)
		{
			c[0] = 'e';
			c[1] = 'o';
			c[2] = 'g';
			c[3] = '1';
			Assert::AreEqual(check(c), 2);
		}
		TEST_METHOD(TestMethod20)
		{
			c[0] = 'l';
			c[1] = 'o';
			c[2] = 'g';
			c[3] = '1';
			c[4] = '^';
			c[5] = '2';
			Assert::AreEqual(check(c), -1);
		}
	};
}
