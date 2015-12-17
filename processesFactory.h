#ifndef	_PROCESSFACTORY_H__
#define	_PROCESSFACTORY_H__
#include "processesImpl.h"

class ProcessesFactory
{
	public:
		virtual ~ProcessesFactory()
		{};
		virtual ProcessesImpl* MakeProcess() = 0;
		static ProcessesFactory* GetProcessesFactory();
};


#endif //_PROCESSFACTORY_H__
