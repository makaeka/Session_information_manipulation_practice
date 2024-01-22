#include "pch.h"
#include "CppUnitTest.h"
#include "../SessyaLaba910/structures.h" 
#include "../SessyaLaba910/process.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittest
{
	TEST_CLASS(Unittest)
	{
	public:

		TEST_METHOD(Test1)
		{

			int testSize = 10;
			student_record** testSubscriptions = new student_record * [testSize];

			// Prepare test data
			testSubscriptions[0] = new student_record{ {"John", "Smith", "Michael"}, {1, 6, 2005}, 8, "History" };
			testSubscriptions[1] = new student_record{ {"Alice", "Johnson", "Anne"}, {2, 6, 2005}, 9, "Mathematics" };
			testSubscriptions[2] = new student_record{ {"Bob", "Williams", "David"}, {3, 6, 2005}, 10, "Science" };
			testSubscriptions[3] = new student_record{ {"Emily", "Brown", "Sarah"}, {4, 6, 2005}, 11, "Art" };
			testSubscriptions[4] = new student_record{ {"James", "Wilson", "Thomas"}, {5, 6, 2005}, 12, "Language" };
			testSubscriptions[5] = new student_record{ {"Olivia", "Lee", "Elizabeth"}, {6, 6, 2005}, 13, "Computer Science" };
			testSubscriptions[6] = new student_record{ {"William", "Miller", "Richard"}, {7, 6, 2005}, 14, "Music" };
			testSubscriptions[7] = new student_record{ {"Ethan", "Davis", "Charles"}, {8, 6, 2005}, 15, "Physical Education" };
			testSubscriptions[8] = new student_record{ {"Sophia", "Garcia", "Patricia"}, {9, 6, 2005}, 16, "Biology" };
			testSubscriptions[9] = new student_record{ {"Charlotte", "Rodriguez", "Linda"}, {10, 6, 2005}, 17, "Chemistry" };
			// Act
			int result = calculateSessionDuration(testSubscriptions, testSize);

			// Assert
			Assert::AreEqual(10, result);
		}

		TEST_METHOD(Test2)
		{

			int testSize = 2;
			student_record** testSubscriptions = new student_record * [testSize];

			// Prepare test data
			testSubscriptions[0] = new student_record{ {"John", "Smith", "Michael"}, {1, 6, 2005}, 8, "History" };
			testSubscriptions[1] = new student_record{ {"Alice", "Johnson", "Anne"}, {2, 6, 2005}, 9, "Mathematics" };
			// Act
			int result = calculateSessionDuration(testSubscriptions, testSize);

			// Assert
			Assert::AreEqual(2, result);
		}

		TEST_METHOD(Test3)
		{

			int testSize = 6;
			student_record** testSubscriptions = new student_record * [testSize];

			// Prepare test data
			testSubscriptions[0] = new student_record{ {"John", "Smith", "Michael"}, {1, 6, 2005}, 8, "History" };
			testSubscriptions[1] = new student_record{ {"Alice", "Johnson", "Anne"}, {2, 6, 2005}, 9, "Mathematics" };
			testSubscriptions[2] = new student_record{ {"Bob", "Williams", "David"}, {3, 6, 2005}, 10, "Science" };
			testSubscriptions[3] = new student_record{ {"Emily", "Brown", "Sarah"}, {4, 6, 2005}, 11, "Art" };
			testSubscriptions[4] = new student_record{ {"James", "Wilson", "Thomas"}, {5, 6, 2005}, 12, "Language" };
			testSubscriptions[5] = new student_record{ {"Olivia", "Lee", "Elizabeth"}, {6, 6, 2005}, 13, "Computer Science" };
			// Act
			int result = calculateSessionDuration(testSubscriptions, testSize);

			// Assert
			Assert::AreEqual(6, result);
		}
	};
}