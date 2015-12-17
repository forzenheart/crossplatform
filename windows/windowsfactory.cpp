/*the factory touch with the imp*/
#include "windowsfactory.h"
#include "windowsprocessesimpl.h"

ProcessesImpl*
WindowsFactory::MakeProcesses()
{
	return new WindowsProcessesImpl;
}
