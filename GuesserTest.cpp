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
	Guesser g("test");
	ASSERT_EQ(g.match("wrong"), false);
}
TEST(GuesserTest, extralength)
{
	Guesser g("test");
	ASSERT_EQ(g.match("test_"), false);
}
TEST(GuesserTest, preextralength)
{
	Guesser g("test");
	ASSERT_EQ(g.match("_test"), false);
}
TEST(GuesserTest, lockout)
{
	Guesser g("test");
	ASSERT_EQ(g.match("wrong"), false);
	ASSERT_EQ(g.remaining(), 2);
	ASSERT_EQ(g.match("wrong"), false);
	ASSERT_EQ(g.remaining(), 1);
	ASSERT_EQ(g.match("wrong"), false);
	ASSERT_EQ(g.remaining(), 0);
	ASSERT_EQ(g.match("test"), false);
}
TEST(GuesserTest, reset)
{
	Guesser g("test");
	ASSERT_EQ(g.match("wrong"), false);
	ASSERT_EQ(g.remaining(), 2);
	ASSERT_EQ(g.match("wrong"), false);
	ASSERT_EQ(g.remaining(), 1);
	ASSERT_EQ(g.match("test"), true);
	ASSERT_EQ(g.remaining(), 3);
}