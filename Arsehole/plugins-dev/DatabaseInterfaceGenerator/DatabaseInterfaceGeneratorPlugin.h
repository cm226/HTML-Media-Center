/*
 * DatabaseInterfaceGeneratorPlugin.h
 *
 *  Created on: 15 May 2013
 *      Author: craig
 */

#ifndef DATABASEINTERFACEGENERATORPLUGIN_H_
#define DATABASEINTERFACEGENERATORPLUGIN_H_

#include "../../arsehole/Framework/Plugin/Plugin.h"


class DatabaseInterfaceGeneratorPlugin : public Plugin
{
private:
	CALLBACk_HANDLE fileUploadedHandle;
	bool fileUploaded(Page* page, PageCallbackContext* context);

	std::string getFilenameFromContext(std::vector<std::string>& context);

	std::string clearTempLocation();
	std::string getTempLocation();

	void buildDownloadPage(Page* p);

public:
	DatabaseInterfaceGeneratorPlugin(CoreModules* cm);
	virtual ~DatabaseInterfaceGeneratorPlugin();

	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
};

#endif /* DATABASEINTERFACEGENERATORPLUGIN_H_ */
