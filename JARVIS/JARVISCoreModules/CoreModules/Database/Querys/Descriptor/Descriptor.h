#ifndef _DESCRIPTOR_H
#define _DESCRIPTOR_H

#include <string>

namespace DatabaseTables
{
namespace Descriptors
{

class Descriptor
{
public:
	Descriptor(void);
	~Descriptor(void);

	virtual std::string getString()=0;
};

}
}
#endif

