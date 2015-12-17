#crossPlatformCompile
#author:FrozenHeart
objects = main.o processlist.o processesFactory.o \
			processesImpl.o processes.o
GCC = g++ 
Platform = HAVE_LINUX
fat : $(objects)
	$(GCC) -ansi -pendantic -Wall -std=c++11  -D $(Platform) -o fat $(objects)

main.o : processlist.h
processlist.o : processesFactory.h
processesFactory.o : processesImpl.h
processesImpl.o : processes.h
processes.o :

.PHONY : clean
clean : 
	rm process $(objects)
	
