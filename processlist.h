#ifndef	_PROCESSLIST_H__
#define _PROCESSLIST_H__
#include <string>

class ProcessList {
	ProcessesFactory	m_processesImpl;
	public:
		ProcessList();
		int	Scan()  const;	
		int	GetCount()  const;
		int	GetPID(const int) const;
		const char*	GetName(const int) const; 
};
#endif //_PROCESSLIST_H__
