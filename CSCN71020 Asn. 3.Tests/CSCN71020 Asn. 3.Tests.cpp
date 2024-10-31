//TODO: apparently result is an invalid input, idk why its like 2am lole
#include "CppUnitTest.h"

extern "C" {
#include "../CSCN71020 Asn. 3/main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CSCN71020Asn3Tests
{
	TEST_CLASS(CSCN71020Asn3Tests)
	{
	public:
		
		TEST_METHOD(acceptInput) // No crash on entering 2 inputs
		{
			char* result = runGame("Rock", "Paper");
		}

		TEST_METHOD(returnOutput) // Return 1 char*
		{
			char* result = runGame("Rock", "Paper");
			Assert::IsNotNull(result);
		}

		// P1 wins
		TEST_METHOD(rockWins)
		{
			char* result = runGame("Rock", "Scissors");
			Assert::AreEqual("Player1", result);
		}

		TEST_METHOD(paperWins)
		{
			char* result = runGame("Paper", "Rock");
			Assert::AreEqual("Player1", result);
		}

		TEST_METHOD(scissorsWins)
		{
			char* result = runGame("Scissors", "Paper");
			Assert::AreEqual("Player1", result);
		}

		// P2 wins
		TEST_METHOD(rockWinsP2)
		{
			char* result = runGame("Scissors", "Rock");
			Assert::AreEqual("Player2", result);
		}

		TEST_METHOD(paperWinsP2)
		{
			char* result = runGame("Rock", "Paper");
			Assert::AreEqual("Player2", result);
		}

		TEST_METHOD(scissorsWinsP2)
		{
			char* result = runGame("Paper", "Scissors");
			Assert::AreEqual("Player2", result);
		}

		TEST_METHOD(draw)
		{
			char* result = runGame("Rock", "Rock");
			Assert::AreEqual("Draw", result);
		}

		TEST_METHOD(invalidInput) // Detects an input that isnt rock/paper/scissors
		{
			char* result = runGame("swag", "Rock");
			Assert::AreEqual("Invalid input", result);
		}

	};
}
