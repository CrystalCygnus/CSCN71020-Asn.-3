//TODO: apparently result is an invalid input, idk why its like 2am lole
#include "CppUnitTest.h"

extern "C" {
#include "../CSCN71020 Asn. 3/main.h"
}

// Shortcuts for this because im sleep deprived and lazy
char* r = new char[4] {'R', 'o', 'c', 'k'};
char* p = new char[5] {'P', 'a', 'p', 'e', 'r'};
char* s = new char[8] {'S', 'c', 'i', 's', 's', 'o', 'r', 's'};

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CSCN71020Asn3Tests
{
	TEST_CLASS(CSCN71020Asn3Tests)
	{
	public:
		
		TEST_METHOD(acceptInput) // No crash on entering 2 inputs
		{
			char* result = runGame(r, p);
		}

		TEST_METHOD(returnOutput) // Return 1 char*
		{
			char* result = runGame(r, p);
			Assert::IsNotNull(result);
		}

		// P1 wins
		TEST_METHOD(rockWins)
		{
			char* result = runGame(r, s);
			Assert::AreEqual("Player1", result);
		}

		TEST_METHOD(paperWins)
		{
			char* result = runGame(p, r);
			Assert::AreEqual("Player1", result);
		}

		TEST_METHOD(scissorsWins)
		{
			char* result = runGame(s, p);
			Assert::AreEqual("Player1", result);
		}

		// P2 wins
		TEST_METHOD(rockWinsP2)
		{
			char* result = runGame(s, r);
			Assert::AreEqual("Player2", result);
		}

		TEST_METHOD(paperWinsP2)
		{
			char* result = runGame(r, p);
			Assert::AreEqual("Player2", result);
		}

		TEST_METHOD(scissorsWinsP2)
		{
			char* result = runGame(r, s);
			Assert::AreEqual("Player2", result);
		}

		TEST_METHOD(draw)
		{
			char* result = runGame(r, r);
			Assert::AreEqual("Draw", result);
		}

		TEST_METHOD(invalidInput) // Detects an input that isnt rock/paper/scissors
		{
			char* result = runGame("swag", r);
			Assert::AreEqual("Invalid input", result);
		}

	};
}
