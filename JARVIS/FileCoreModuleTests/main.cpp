#define BOOST_TEST_MAIN

#ifndef WIN32
#define BOOST_TEST_DYN_LINK 
/* seems we want to define this in linux only if defined in windows
1>boost_unit_test_framework-vc100-mt-gd-1_52.lib(boost_unit_test_framework-vc100-mt-gd-1_52.dll) : error LNK2005: "public: static class boost::unit_test::unit_test_log_t & __cdecl boost::unit_test::singleton<class boost::unit_test::unit_test_log_t>::instance(void)" (?instance@?$singleton@Vunit_test_log_t@unit_test@boost@@@unit_test@boost@@SAAAVunit_test_log_t@23@XZ) already defined in
*/
#endif

#include "stdafx.h"
