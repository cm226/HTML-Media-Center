

#ifndef TASKERPLUGIN_H_
#define TASKERPLUGIN_H_

#include "../../arsehole/Framework/Plugin/Plugin.h"
#include <string>

class TaskerPlugin : public Plugin
{
private:
	CALLBACk_HANDLE taskAdded;
	CALLBACk_HANDLE fileUploaded;

	std::string plugin_name;

	bool handleTaskAdded(Page* page, PageCallbackContext* context);
	bool handleFileUploaded(Page* page, PageCallbackContext* context);

public:
	TaskerPlugin(CoreModules* framework);
	virtual ~TaskerPlugin();
	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
};

#endif

