#include "processesFactory.h"

#if	defined(HAVE_WIN32)
#include "windows\windowsfactory.h"
#elif	defined(HAVE_LINUX)
#include "linux/linuxfactory.h"
#endif //platform

ProcessesFactory *
ProcessesFactory::GetProcessesFactory()
{
	static ProcessesFactory *processesFactory = 0;
	
	if (!processesFactory)
	{
#if	defined(HAVE_WIN32)
		processesFactory = 
			WindowsFactory::GetFactoryInstance();
#endif
#if	defined(HAVE_LINUX)	
		processesFactory = 
			LinuxFactory::GetFactoryInstance();
#endif
	}
	return processesFactory;
}
