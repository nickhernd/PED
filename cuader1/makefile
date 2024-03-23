.PHONY= doc clean test

CC=g++
OPTIONS= -g 
DEBUG= -D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcalendario.o tvectorcalendario.o tlistacalendario.o 
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tad: src/main.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/main.cpp $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

tar: include lib src nombres.txt
	tar cvfz 48776654W.tar.gz include lib src nombres.txt

doc:
	doxygen

clean:
	rm -f $(OBJ) 

test:
	chmod +x test.sh
	./test.sh


