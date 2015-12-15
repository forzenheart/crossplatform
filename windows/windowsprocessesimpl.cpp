#include "windowsprocessesimpl.h"

int
WindowsProcessesImpl::Scan()
{
	m_processList.clear();
	ScanProcess();	
	return m_processList.size();
}

void
WindowsProcessesImpl::PrintProcessNameAndID(DWORD processID)
{
	tchar szProcessName[];
}
