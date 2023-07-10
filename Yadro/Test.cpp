#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Tape.h"
#include "MergeSort.h"
using namespace std;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(TestFuzzyCompare)

	BOOST_AUTO_TEST_CASE(TestSpeed, *utf::timeout(100))
	{
#ifdef BOOST_SIGACTION_BASED_SIGNAL_HANDLING

		Tape t("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\input\\in.dat", 10);

		vector<int> data{ 21,53,1,56,8,9,3,56,34,6,76 };
		
		for (size_t i = 0; i < data.size(); i++)
		{
		    t.Write(data[i]);
		    t.MoveR();
		}

		for (size_t i = 0; i < t.GetLength() / sizeof(int); i++)
		{
			t.MoveR();
		}
		BOOST_TEST(true);
#else
		BOOST_TEST(false);	
#endif
	}

BOOST_AUTO_TEST_CASE(TestMoveL)
{
	Tape t("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\input\\in.dat", 10);

	for (size_t i = 0; i < 12; i++)
	{
		t.MoveL();
	}
	if (t.GetCurPos() == 0)BOOST_TEST(true);
	else BOOST_ERROR("You don't MoveL");
}
BOOST_AUTO_TEST_CASE(TestMoveR)
{
	Tape t("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\input\\in.dat", 10);

	for (size_t i = 0; i < 12; i++)
	{
		t.MoveR();
	}
	t.Clear();
	if (t.GetCurPos() == 0) BOOST_ERROR("You don't MoveR");
	else BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(TestClear)
{
	Tape t("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\input\\in.dat", 10);

	for (size_t i = 0; i < 12; i++)
	{
		t.MoveR();
	}
	t.Clear();
	if (t.GetCurPos() == 0 && t.GetLength() == 0) BOOST_TEST(true);
	else  BOOST_ERROR("File is field");
}

BOOST_AUTO_TEST_CASE(TestResetZeroPos)
{
	Tape t("C:\\Users\\a.lunyov\\source\\repos\\Yadro\\input\\in.dat", 10);

	for (size_t i = 0; i < 12; i++)
	{
		t.MoveR();
	}
	t.ResetZeroPos();
	if (t.GetCurPos() == 0) BOOST_TEST(true);
	else  BOOST_ERROR("ResetZeroPos don't working");
}

BOOST_AUTO_TEST_SUITE_END()