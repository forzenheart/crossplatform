#include "processesImpl.h"

int
ProcessesImpl::GetCount() const
{
	return  m_processList.size();
}

int
ProcessesImpl::GetPID(const int which) const
{
	return m_processList[which].GetPid();
}

const std::string
ProcessesImpl::GetName(const int which) const
{
	return m_processList[which].GetName();
}
