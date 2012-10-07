/*
 * EvntHandlerBase.h
 *
 *  Created on: Sep 28, 2012
 *      Author: craig
 */

#ifndef EVNTHANDLERBASE_H_
#define EVNTHANDLERBASE_H_

template <typename ReturnT, typename ParamT>
class EvntHandlerBase {
public:
	EvntHandlerBase(){};
	virtual ~EvntHandlerBase(){};

	virtual ReturnT notify(ParamT param) = 0;
};

#endif /* EVNTHANDLERBASE_H_ */
