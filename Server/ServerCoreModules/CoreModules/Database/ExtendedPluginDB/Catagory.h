/*
 * Catagory.h
 *
 *  Created on: 8 Jul 2013
 *      Author: craig
 */

#ifndef CATAGORY_H_
#define CATAGORY_H_

#include <list>
#include <string>
#include "SubCatagory.h"


namespace ExtendedDatabase {

class Catagory {

private:
	std::string _CatagorysFolder;
	std::list<SubCatagory> _SubCatagories;
public:
	Catagory(std::string catagoreysFolder);
	virtual ~Catagory();

	void addSubCatagory(std::string catagoryName);

	bool tryLookupSubcatagoryFromName(std::string name,SubCatagory&);
	const std::list<SubCatagory>& ListSubCatagories();

};

} /* namespace ExtendedDatabase */
#endif /* CATAGORY_H_ */
