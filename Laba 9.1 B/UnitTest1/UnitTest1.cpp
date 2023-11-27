#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 9.1 B/Laba 9.1 B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int N = 1;
			Student* a = new Student[N];
			std::stringstream input;
			input << "fff\n1\n1\n3\n4\n4\n";

			std::streambuf* originalCin = std::cin.rdbuf();
			std::cin.rdbuf(input.rdbuf());

			Create(a, N);
			Assert::AreEqual(std::string("ff"), a[0].surname);
			Assert::AreEqual(4, a[0].physics);
			Assert::AreEqual(4, a[0].math);
			Assert::AreEqual(4, a[0].it);

			delete[] a;
		}
	};
}
