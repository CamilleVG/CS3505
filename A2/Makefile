
LIBHARU = ../libharu/include
CC = g++
CFLAGS = -Wall

pdfDemo: Spiral.o HaruPDF.o spiralPDF.cpp $(LIBHARU)/hpdf.h
	$(CC) $(CFLAGS) -I$(LIBHARU) -L../libharu/src -o pdfDemo Spiral.o HaruPDF.o spiralPDF.cpp -lhpdfs

Spiral.o: Spiral.cpp $(LIBHARU)/hpdf.h
	$(CC) $(CFLAGS) -I$(LIBHARU) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp $(LIBHARU)/hpdf.h
	$(CC) $(CFLAGS) -I$(LIBHARU) -c HaruPDF.cpp 

clean: 
	rm -f *.o *.a test
