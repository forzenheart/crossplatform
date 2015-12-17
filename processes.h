#ifndef _PROCESSES_H__
#define	_PROCESSES_H__
#include <string>

class	Process {
	public:
		void SetPid(int pid);
		void SetName(const std::string name);
		const std::string GetName() const;
		int GetPid() const;
	private:
		int	m_pid;
		const char *	m_name;
};

#endif //_PROCESSES_H__

