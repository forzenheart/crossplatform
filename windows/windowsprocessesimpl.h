#ifndef	_WINDOWSPROCESSESIMPL_H__
#define	_WINDOWSPROCESSESIMPL_H__

#include "../processesImpl.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

class WindowsProcessesImpl : public ProcessesImpl
{
	public:
		WindowsProcessesImpl();
		virtual ~WindowsProcessesImpl();
		virtual	int Scan();
	private:
		void ScanProcess();
		void PrintProcessNameAndID(DWORD processID);
}

#endif //_WINDOWSPROCESSESIMPL_H__

