CC = g++
CFLAGS = -Wall -std=c++11

HARUPDFLIBDIR = .

HARUPDFLIBINCLUDE = .

LIBHARUDIR = libharu/src

LIBHARUINCLUDE = libharu/include

EXTRALIBRARIES = -lhpdfs -lm -lz

HaruPDFTest : libHaruPDF.a spiralPDF.o
	$(CC) $(CFLAGS) -o HaruPDFTest spiralPDF.o -I$(HARUPDFLIBINCLUDE) -I$(LIBHARUINCLUDE) -L$(HARUPDFLIBDIR) -L$(LIBHARUDIR) -lHaruPDF $(EXTRALIBRARIES)

#include the spiral.o file here once it is complete
libHaruPDF.a: HaruPDF.o Spiral.o spiralPDF.o
	ar -rcs libHaruPDF.a HaruPDF.o Spiral.o spiralPDF.o

HaruPDF.o : HaruPDF.cpp
	$(CC) $(CFLAGS) -c HaruPDF.cpp -L$(LIBHARUDIR) -I$(HARUPDFLIBINCLUDE) -I$(LIBHARUINCLUDE) $(EXTRALIBRARIES)

spiralPDF.o : spiralPDF.cpp
	$(CC) $(CFLAGS) -c spiralPDF.cpp -I$(HARUPDFLIBINCLUDE)

Spiral.o : Spiral.cpp
	$(CC) $(CFLAGS) -c Spiral.cpp

clean:
	rm HaruPDFTest *.o libHaruPDF.a HaruPDFTest.pdf

test:
	./HaruPDF
