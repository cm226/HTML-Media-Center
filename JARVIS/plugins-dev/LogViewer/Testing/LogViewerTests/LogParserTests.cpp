#include "stdafx.h"
#include "../../LogEntryParser.h"

BOOST_AUTO_TEST_CASE(parserLocationTests)
{
	LogEntryParser parser;
	BOOST_CHECK_EQUAL(parser.setLogFileLocation("C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\plugins-dev\\LogViewer\\Testing\\LogViewerTests\\parserTestinput.txt"),true);
	BOOST_CHECK_EQUAL(parser.setLogFileLocation("C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\plugins-dev\\LogViewer\\Testing\\LogViewerTests\\parserTestinput12.txt"),false);

}

BOOST_AUTO_TEST_CASE(parserParseTests)
{
	LogEntryParser parser;
	BOOST_CHECK_EQUAL(parser.setLogFileLocation("C:\\wamp\\www\\HTML-Media-Center\\JARVIS\\plugins-dev\\LogViewer\\Testing\\LogViewerTests\\parserTestinput.txt"),true);
	
	std::priority_queue<model::LogEntry> entrys;
	BOOST_CHECK_EQUAL(parser.getAllEntrys(entrys),true);

	model::LogEntry logEntry = entrys.top();
	entrys.pop();

	BOOST_CHECK_EQUAL(logEntry.getSeverity(), model::LogEntry::SEVERITY::WAR);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().year(), 2012);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().month(), 10);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().day(), 17);

	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().hours(), 13);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().minutes(), 35);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().seconds(), 0);

	logEntry = entrys.top();
	entrys.pop();

	BOOST_CHECK_EQUAL(logEntry.getSeverity(), model::LogEntry::SEVERITY::ERROR);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().year(), 2012);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().month(), 9);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().day(), 16);

	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().hours(), 12);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().minutes(), 30);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().seconds(), 14);

	logEntry = entrys.top();
	entrys.pop();


	BOOST_CHECK_EQUAL(logEntry.getSeverity(), model::LogEntry::SEVERITY::INFO);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().year(), 2012);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().month(), 1);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().date().day(), 7);

	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().hours(), 13);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().minutes(), 35);
	BOOST_CHECK_EQUAL(logEntry.logTimeStamp().time_of_day().seconds(), 0);

	
	BOOST_CHECK_EQUAL(entrys.empty(),true);



}