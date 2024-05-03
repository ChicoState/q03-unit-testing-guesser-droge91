/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/
TEST(GuesserTest, base)
{
	Guesser g("test");
	ASSERT_EQ(g.match("test"), true);
}
TEST(GuesserTest, wrong)
{
	Guesser g("terminal");
	ASSERT_EQ(g.match("referred"), false);
}
TEST(GuesserTest, extralength)
{
	Guesser g("banana");
	ASSERT_EQ(g.match("banana_"), false);
}
TEST(GuesserTest, preextralength)
{
	Guesser g("preferred");
	ASSERT_EQ(g.match("_preferred"), false);
}
TEST(GuesserTest, lockout)
{
	Guesser g("gorilla");
	ASSERT_EQ(g.match("termite"), false);
	ASSERT_EQ(g.remaining(), 2);
	ASSERT_EQ(g.match("pigeon"), false);
	ASSERT_EQ(g.remaining(), 1);
	ASSERT_EQ(g.match("wren"), false);
	ASSERT_EQ(g.remaining(), 0);
	ASSERT_EQ(g.match("pheasant"), false);
}
TEST(GuesserTest, reset)
{
	Guesser g("litmus");
	ASSERT_EQ(g.match("rotation"), false);
	ASSERT_EQ(g.remaining(), 2);
	ASSERT_EQ(g.match("certainty"), false);
	ASSERT_EQ(g.remaining(), 1);
	ASSERT_EQ(g.match("litmus"), true);
	ASSERT_EQ(g.remaining(), 3);
}
TEST(GuesserTest, longsecret)
{
	Guesser g("al;sioku.jedfhnaswk;jldhnfa;kjsdhfa;ljksdhf;ljkasaw;opuiehfi;awpoiehnf;apiuoewwrhnfg;lioukjaewdhnrfguio;aehnrdfgv;iouaehnjdfugijvo;lahnewriuo;jkfghnaWE;oikrlgfvjhnaWI;OERDJHNFGVIo;awsrdhnjfgiou;awejhnmedsrfvg;oikaEWSjnmhsrdifov;'AHJNMWSEESD;OIPRFGVHJNaW:OIKedsfvchjnaio;krewhnfg");
	ASSERT_EQ(g.match("al;sioku.jedfhnaswk;jldhnfa;kjsdhfa;ljksdhf;ljkasaw;opuiehfi;awpoiehnf;apiuoewwrhnfg;lioukjaewdhnrfguio;aehnrdfgv;iouaehnjdfugijvo;lahnewriuo;jkfghnaWE;oikrlgfvjhnaWI;OERDJHNFGVIo;awsrdhnjfgiou;awejhnmedsrfvg;oikaEWSjnmhsrdifov;'AHJNMWSEESD;OIPRFGVHJNaW:OIKedsfvchjnaio;krewhnfg"), false);
	ASSERT_EQ(g.match("al;sioku.jedfhnaswk;jldhnfa;kjsd"), true);
}
TEST(GuesserTest, longguess)
{
	Guesser g("test");
	ASSERT_EQ(g.match("al;sioku.jedfhnaswk;jldhnfa;kjsdhfa;ljksdhf;ljkasaw;opuiehfi;awpoiehnf;apiuoewwrhnfg;lioukjaewdhnrfguio;aehnrdfgv;iouaehnjdfugijvo;lahnewriuo;jkfghnaWE;oikrlgfvjhnaWI;OERDJHNFGVIo;awsrdhnjfgiou;awejhnmedsrfvg;oikaEWSjnmhsrdifov;'AHJNMWSEESD;OIPRFGVHJNaW:OIKedsfvchjnaio;krewhnfg"), false);
}
TEST(GuesserTest, multGuessRem)
{
	Guesser g("horticulture");
	Guesser g2("test");
	ASSERT_EQ(g.match("awsefh"), false);
	ASSERT_EQ(g.remaining(), 2);
	ASSERT_EQ(g2.remaining(), 3);
	ASSERT_EQ(g2.match("asddjc"), false);
}
TEST(GuesserTest, emptyguess)
{
	Guesser g("test");
	ASSERT_EQ(g.match(""), false);
}
TEST(GuesserTest, emptysecret)
{
	Guesser g("");
	ASSERT_EQ(g.match("test"), false);
	ASSERT_EQ(g.match(""), true);
}
TEST(GuesserTest, emptyboth)
{
	Guesser g("");
	ASSERT_EQ(g.match(""), true);
}
TEST(GuesserTest, close)
{
	Guesser g("test");
	ASSERT_EQ(g.match("tesp"), false);
}
TEST(GuesserTest, closeButWhitespace)
{
	Guesser g("test");
	ASSERT_EQ(g.match("test "), false);
}
TEST(GuesserTest, closeButWhitespace2)
{
	Guesser g("test");
	ASSERT_EQ(g.match(" test"), false);
}
TEST(GuesserTest, closeButWhitespace3)
{
	Guesser g("test");
	ASSERT_EQ(g.match("te st"), false);
}
TEST(GuesserTest, closeButCapital)
{
	Guesser g("desperation");
	ASSERT_EQ(g.match("desperAtion"), false);
}
TEST(GuesserTest, remNotNeg)
{
	Guesser g("plywood");
	ASSERT_EQ(g.match("dakota"), false);
	ASSERT_EQ(g.match("montana"), false);
	ASSERT_EQ(g.match("vermont"), false);
	ASSERT_EQ(g.match("mississippi"), false);
	ASSERT_EQ(g.match("nevada"), false);
	ASSERT_EQ(g.match("california"), false);
	ASSERT_EQ(g.match("oregon"), false);
	ASSERT_EQ(g.remaining(), 0);
}