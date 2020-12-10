#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/Костя/source/repos/ConsoleApplication10/ConsoleApplication10/ConsoleApplication10.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		Tree tester;
		TEST_METHOD(TestMethod1)
		{
			tester.insert(6);
			Assert::AreEqual(tester.contains(6), true);
		}
	};
}
