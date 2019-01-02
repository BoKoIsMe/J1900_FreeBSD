objects = main.o subproc1.o subproc2.o

maketest : $(objects)
	c++ -std=c++11 -o maketest $(objects)
main.o : subproc1.h subproc2.h
subproc2.o : subproc2.h
subproc1.o : subproc1.h subproc2.h
.PHONY : clean
clean : 
	rm maketest $(objects)

