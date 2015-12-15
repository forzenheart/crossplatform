#ifndef	_PROCESSES_IMPL_H__
#define	_PROCESSES_IMPL_H__
#include "processes.h"
#include <vector>

class ProcessesImpl 
{
	public:
		ProcessesImpl()
		{};
		virtual ~ProcessesImpl()
		{};
		virtual	int Scan() const = 0;
		int GetCount() const;
		const char* GetName(const int which) const;
		int GetPID(const int which) const;
	protected:
		std::vector<Process> m_processList;
};
#endif //_PROCESSES_IMPL_H__

