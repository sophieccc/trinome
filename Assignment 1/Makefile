.PHONY: all, clean

CPP = g++
CFLAGS = -ansi -pedantic -Wall -Werror -std=c++11 -DMAP -g

LIBS += -lpthread

PROGS = main.o Trajet.o Catalogue.o TrajetSimple.o TrajetComplexe.o	

Final : $(PROGS)
	$(CPP) -o $@ $^

%.o : %.cpp
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f $(PROGS) *.o
	