#include "processesFactory.h"
#include "processlist.h"

ProcessList::ProcessList()
	:m_processesImpl(NULL)
{
	ProcessesFactory *factory = ProcessesFactory::GetProcessesFactory();
	//It make the difference between the platform
	if (factory)
		m_processesImpl = factory->MakeProcess();
}

int
ProcessList::Scan() const
{
	if (m_processesImpl)
		return m_processesImpl->GetCount();
	return -1;
}

int
ProcessList::GetCount()  const
{
	if (m_processesImpl)
		return m_processesImpl->GetCount();
	return -1;
}

int
ProcessList::GetPID(const int i)  const
{
	if (m_processesImpl)
		return m_processesImpl->GetPID(i);
	return -1;
}

const char*
ProcessList::GetName(const int i)  const
{
	if (m_processesImpl)
		return m_processesImpl->GetName(i);
	return NULL; 
}
