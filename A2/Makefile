CC = g++
CFLAGS = -Wall -std=c++11

HARUPDFLIBDIR = .

HARUPDFLIBINCLUDE = .

HaruPDFTest : libHaruPDF.a spiralPDF.o
	$(CC) $(CFLAGS) -o HaruPDFTest spiralPDF.o -L$(HARUPDFLIBDIR) -lHaruPDF

#include the spiral.o file here once it is complete
libHaruPDF.a: HaruPDF.o Spiral.o spiralPDF.o
	ar -rcs libHaruPDF.a HaruPDF.o Spiral.o spiralPDF.o

HaruPDF.o : HaruPDF.cpp
	$(CC) $(CFLAGS) -c HaruPDF.cpp -L libharu/src -I. -I libharu/include -lhpdfs -lm -lz

spiralPDF.o : spiralPDF.cpp
	$(CC) $(CFLAGS) -c spiralPDF.cpp -I.

Spiral.o : Spiral.cpp
	$(CC) $(CFLAGS) -c Spiral.cpp

clean:
	rm HaruPDFTest *.o libHaruPDF.a

test:
	./HaruPDF
