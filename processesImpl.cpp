#include "processesImpl.h"

ProcessesImpl::ProcessesImpl()
{}

int
ProcessesImpl::GetCount() const
{
	return  m_processList.size();
}

int
ProcessesImpl::GetPID(const int which) const
{
	return -1;
}
