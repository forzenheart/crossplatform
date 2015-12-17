#ifndef _LINUX_FACTORY_H__
#define _LINUX_FACTORY_H__
#include "../prcessesFactory.h"
#include "../processesImpl.h"

class LinuxFactory : public ProcessesFactory
{
	public:
		static LinuxFactory* GetFactoryInstance()
		{
			if (!factory)
			{
				factory = new LinuxFactory;
			}
			return factory;
		}
		virtual ~LinuxFactory();

		virtual ProcessesImpl* MakeProcesses();
	private:
		LinuxFactory();
};


#endif	//_LINUX_FACTORY_H__
