#ifndef	_WINDOWS_FACTORY_H__	
#define _WINDOWS_FACTORY_H__

#include "../processesFactory.h"
#include "../processesImpl.h"

class WindowsFactory : public ProcessesFactory
{
	public:
		static WindowsFactory* GetFactoryInstance()
		{
			static	WindowsFactory	*factory = 0;
			if (!factory)
			{
				factory = new WindowsFactory;
			}
			return factory;
		}
		virtual ~WindowsFactory();
		virtual	ProcessesImpl*	MakeProcesses();
	private:
		WindowsFactory();

};

#endif //_WINDOWS_FACTORY_H__
