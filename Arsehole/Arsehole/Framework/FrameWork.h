/*
 * FrameWork.h
 *
 *  Created on: Sep 18, 2012
 *      Author: craig
 */

#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include <vector>
#include <string>

#include "../../ArseholeCoreModules/CoreModules/CoreModules.h"
#include "Plugin/Loader/Loader.h"
#include "PluginPageResponder.h"
#include "MediaStreamResponder.h"

#include "../../Comms/Protocals/IProtocal.h"
#include <boost/scoped_ptr.hpp>

#include <mutex>
#include <condition_variable>

class ArseholeFramework
{
private:
	Loader* pluginLoader;
	boost::scoped_ptr<PluginPageResponder> pluginPageResponder;
	boost::scoped_ptr<MediaStreamResponder> mediaStreamResponder;

	std::shared_ptr<CoreModules> cModules;


	bool shuttingDown;
	std::mutex m_shutdown_mutext;
	std::condition_variable m_shutdown_cv;

public:
	ArseholeFramework();
	virtual ~ArseholeFramework();

	void process();

private:
	void loadedPlugins(ListPluginsMessage*, coremodules::comms::protocals::IProtocal*);
	void processDiagnosticMessage(TranslatedMessages::RequestDisagnosticsMessage*, coremodules::comms::protocals::IProtocal*);

	void loadStartupPlugins();

	void processCommandLoop();


};


#endif /* FRAMEWORK_H_ */
