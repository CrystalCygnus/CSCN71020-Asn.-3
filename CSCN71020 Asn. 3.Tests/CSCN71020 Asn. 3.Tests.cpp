#include "CppUnitTest.h"

extern "C" {
#include "../CSCN71020 Asn. 3/main.h"
}

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
			// Ok so this is actually done above, that won't succeed if it returned multiple char arrays
		}

		// P1 wins
		TEST_METHOD(rockWins)
		{
			char* result = runGame(r, s);
			Assert::AreEqual(result, "Player1");
		}

		TEST_METHOD(paperWins)
		{
			char* result = runGame(p, r);
			Assert::AreEqual(result, "Player1");
		}

		TEST_METHOD(scissorsWins)
		{
			char* result = runGame(s, p);
			Assert::AreEqual(result, "Player1");
		}

		// P2 wins
		TEST_METHOD(rockWinsP2)
		{
			char* result = runGame(s, r);
			Assert::AreEqual(result, "Player2");
		}

		TEST_METHOD(paperWinsP2)
		{
			char* result = runGame(r, p);
			Assert::AreEqual(result, "Player2");
		}

		TEST_METHOD(scissorsWinsP2)
		{
			char* result = runGame(r, s);
			Assert::AreEqual(result, "Player2");
		}

		TEST_METHOD(draw)
		{
			char* result = runGame(r, r);
			Assert::AreEqual(result, "Draw");
		}

		TEST_METHOD(invalidInput) // Detects an input that isnt rock/paper/scissors
		{
			char* result = runGame("swag", r);
			Assert::AreEqual(result, "Invalid");
		}

	};
}
