#include "processes.h"

void
Process::SetPid(int pid)
{
	m_pid = pid;
}

void
Process::SetName(const std::string name)
{
	m_name = name;
}
const std::string
Process::GetName() const
{
	return m_name;
}

int
Process::GetPid() const;
{
	return	m_pid;
}
