#include "processlist.h"
#include <cstdio>

int
main(void)
{
	ProcessList processlist;

	processlist.Scan();

	for (int i = 0; i < processlist.GetCount(); i++)
	{
		printf("%d %s\n",
			processlist.GetPID(i),
			processlist.GetName(i));
	}
	return 0;
}

