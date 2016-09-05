CC = g++
CFlags = -Wall -std=c++11

HARUPDFLIBDIR = .

HARUPDFLIBINCLUDE = .

HaruPDFTest : libHaruPDF.a spiralPDF.o
	$(CC) $(CFLAGS) -o HaruPDFTest spiralPDF.o -L$(HARUPDFLIBDIR) -lHaruPDF

#include the spiral.o file here once it is complete
libHaruPDF.a: HaruPDF.o
	ar -rcs libHaruPDF.a HaruPDF.o

HaruPDF.o : HaruPDF.cpp
	$(CC) $(CFLAGS) -c HaruPDF.cpp -L libharu/src -I. -I libharu/include -lhpdfs -lm -lz

spiralPDF.o : spiralPDF.cpp $(HARUPDFINCLUDE)/HaruPDF.h
	$(CC) $(CFLAGS) -c -I$(HARUPDFINCLUDE) spiralPDF.cpp

HaruPDF : HaruPDF.o
	$(CC) $(CFLAGS) -o HaruPDF HaruPDF.cpp -L libharu/src -I. -I libharu/include -lhpdfs -lm -lz

clean:
	rm HaruPDFTest *.o libHaruPDF.a

test:
	./HaruPDF
