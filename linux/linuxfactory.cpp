//the factory touch with the impl
#inclue "linuxfactory.h"
#inclue "linuxprocesssesimpl.h"

ProcessesImpl*
LinuxFactory::MakeProcesses()
{
	return new LinuxProcessImpl;
}
