#ifndef _LIMIT_H
#define _LIMIT_H

#include "Descriptor.h"
#include "../../../exportMacros.h"

namespace DatabaseTables
{
namespace Descriptors
{


class DLLCORE_API Limit : public Descriptor
{
private:
	#pragma warning( disable : 4251)
	std::string limit;
	#pragma warning( default : 4251)

public:
	Limit(std::string limit);
	~Limit(void);

	std::string getString();
};

}
}
#endif


