#Written by Tyler Dailey, 9/5/16, for CS3505 Assignment 2.

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
	./HaruPDFTest "This is the text that will be turned into a spiral. It was borrowed from the example given in the Assignment 2 Specifications."

test2:
	./HaruPDFTest "This is a short text test."

test3:
	./HaruPDFTest "This is to test to see what happens when I enter a really long string. Hopefully it will just reach the edges of the page and then be cut off because the page is too small to contain the text. This is probably long enough to test this boundary case."

test4:
	make HaruPDFTest
	make test
