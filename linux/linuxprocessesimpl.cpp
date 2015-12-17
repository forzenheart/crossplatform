#include "linuxprocessesimpl.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

int
LinuxProcessImpl::Scan()
{
	DIR	*dir;
	m_processList.clear();

	dir = open("/proc");
	if (dir == NULL)
	{
		return 0;
	}
	std::string	name;
	struct dirent	*dirEnt;
	struct stat	statBuf;

	while ((dirEnt = readdir(dir)))
	{
		name = "/proc";
		name += dirEnt->d_name;
		bool allDigits = true;
		while (*p)
		{
			if (! isdigit(*p))
			{
				allDigits = false;
				break;
			}
			p++;
		}
		if (allDigits)
		{
			Process proc;

			proc.SetPID(atoi(dirEnt->d_name));
			std::string path = name + std::string("/cmdline");
			int fd = open(path.c_str(), O_RDONLY);
			if (fd != -1)
			{
				char buf[1024];
				memset(buf, '\0', sizeof(buf));
				int n;
				if ((n = read(fd, buf, sizeof(buf) - 1)) > 0)
				{
					proc.SetName(buf);
					m_processList.push_back(proc);
				}
				else if (n == 0)
				{
					path = name + std::string("/status");
					int fd2 = open(path.c_str(), O_RDONLY);
					if (fd2 != -1)
					{
						memset(buf, '\0', sizeof(buf));
						if ((n =
							read(fd2,
							buf,
							sizeof(buf) - 1)) > 0)
						{
							char *p = buf;
							while (*p)
							{
								if (*p == '\n')
								{
									*p = '\0';
									break;
								}
								p++;
							}
							if ((p = strstr(buf,
								"Name:")))
							{
								while(*p && isspace(*p))
								{
									p++;
								}
							}
							else
								p = buf;
							proc.SetName(p);
							m_processList.push_back(proc);
						}
						close(fd2);
					}
				}
				close(fd);
			}
		}
	}
	closedir(dir);
	return m_processList.size();
}
