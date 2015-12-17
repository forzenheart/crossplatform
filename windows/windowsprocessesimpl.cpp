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
	TCHAR szProcessName[max_path] = 
		TEXT("<unknown");
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFOMATION | PROCESS_VM_READ, 
			FALSE, processID);
	if (NULL != hProceess)
	{
		HMODULE = hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, 
					sizeof(hMod), &cbNeeded))
		{
			GetModuleBaseName(hProces, hMod,
					szProcessName, 
					sizeof(szProcessName) / sizeof(TCHAR));
		}
	}

	Process proc;
	proc.SetPID(processID);
	proc.setName(szProcessName);
	m_processList.push_back(proc);
	CloseHandle(hProcess);
}

void WindowsProcessesImpl::ScanProcess()
{
	DWORD aProcesses[1024], cbNeeded, cProcesses; 
	unsigned int i;

	if(!EnumProcesses(aProcesses, sizeof(aProcesses), 
				&cbNeeded))
	{
		return;
	}
	cProcesses = cbNeeded / sizeof(DWORD);
	
	for(i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			PrintProcessNameAndID(aProcesses[i]);
		}
	}
}
