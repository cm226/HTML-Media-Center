/*
 * LessThan.cpp
 *
 *  Created on: Nov 25, 2012
 *      Author: craig
 */

#include "LessThan.h"

namespace DatabaseTables {

LessThan::LessThan(IDatabaseTableField* field, std::string value) : Constraint(field, value){


}

LessThan::~LessThan() {

}

} /* namespace DatabaseTables */
