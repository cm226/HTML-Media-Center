

#ifndef TASKERPLUGIN_H_
#define TASKERPLUGIN_H_

#include "../../JARVIS/Framework/Plugin/Plugin.h"
#include <string>

class TaskerPlugin : public Plugin
{
private:
	CALLBACk_HANDLE taskAdded;
	std::string plugin_name;

	void wStringToString(std::wstring& in, std::string& out);
	void makeURLWeblink(std::wstring& location, bool& success);

	void buildCommandPresets(Page* p, Form* form);
	void buildBlendFileList(Page* p);
	void buildOutputFileList(Page* p);
	bool handleTaskAdded(Page* page, PageCallbackContext* context);

public:
	TaskerPlugin(CoreModules* framework);
	virtual ~TaskerPlugin();
	virtual bool whatDoYouLookLike(Page*);
	virtual const char* pluginName();
};

#endif

