#ifndef _DESCRIPTOR_H
#define _DESCRIPTOR_H

#include <string>
#include "../../../exportMacros.h"

namespace DatabaseTables
{
namespace Descriptors
{

class DLLCORE_API Descriptor
{
public:
	Descriptor(void);
	~Descriptor(void);

	virtual std::string getString()=0;
};

}
}
#endif

