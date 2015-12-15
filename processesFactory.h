#ifndef	_PROCESSFACTORY_H__
#define	_PROCESSFACTORY_H__
#incldue "processesImpl.h"

class processesFactory
{
	public:
		virtual ~ProcessesFactory()
		{};
		virtual ProcessesImpl* MakeProcess() = 0;
		static ProcessesFactory* GetProcessesFactory();
};


#endif //_PROCESSFACTORY_H__
