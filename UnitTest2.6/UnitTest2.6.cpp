#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 2.6/Rational.h"
#include "../lab 2.6/Rational.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest26
{
	TEST_CLASS(UnitTest26)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Rational a;
			int t;
			t = a.Diff_2(1000, 7);
			Assert::AreEqual(t, 7000);
		}
	};
}
