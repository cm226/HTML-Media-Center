#include "../stdafx.h"
#include "../../../Model/LogEntry.h"

BOOST_AUTO_TEST_CASE(LogEntryCtor)
{
	model::LogEntry le("2012-09-16 10:30:10","message", model::LogEntry::SEVERITY::WAR);

	BOOST_CHECK_EQUAL(le.logTimeStamp().date().year(),2012);
	BOOST_CHECK_EQUAL(le.logTimeStamp().date().month(),9);
	BOOST_CHECK_EQUAL(le.logTimeStamp().date().day(),16);

	BOOST_CHECK_EQUAL(le.logTimeStamp().time_of_day().hours(), 10);
	BOOST_CHECK_EQUAL(le.logTimeStamp().time_of_day().minutes(), 30);
	BOOST_CHECK_EQUAL(le.logTimeStamp().time_of_day().seconds(), 10);
}

BOOST_AUTO_TEST_CASE(LogEntryCtorAlternateFormat)
{
	model::LogEntry le("10:30:10 2012-09-16","%H:%M:%S %Y-%m-%d","message", model::LogEntry::SEVERITY::WAR);

	BOOST_CHECK_EQUAL(le.logTimeStamp().date().year(),2012);
	BOOST_CHECK_EQUAL(le.logTimeStamp().date().month(),9);
	BOOST_CHECK_EQUAL(le.logTimeStamp().date().day(),16);

	BOOST_CHECK_EQUAL(le.logTimeStamp().time_of_day().hours(), 10);
	BOOST_CHECK_EQUAL(le.logTimeStamp().time_of_day().minutes(), 30);
	BOOST_CHECK_EQUAL(le.logTimeStamp().time_of_day().seconds(), 10);
}