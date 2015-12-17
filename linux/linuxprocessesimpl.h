#ifndef	_LINUXPROCESSESIMPL_H__
#define	_LINUXPROCESSESIMPL_H__

#include "../processesImpl.h"
#include <dirent.h>

class LinuxProcessImpl : public ProcessesImpl
{
	public:
		LinuxProcessImpl()
		{}
		virtual ~LinuxProcessImpl()
		{}
		virtual	int Scan();
};

#endif //_LINUXSPROCESSESIMPL_H__

