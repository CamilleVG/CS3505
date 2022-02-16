/* 
 * Camille van Ginkel u0953582 Jan 31, 2022
 */


#include "HaruPDF.h"
#include "Spiral.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class SpiralPDF{
    private:
        char fname[256];
        const char* TXT;
        unsigned int i;
    public:
            SpiralPDF(char fileName[], char text[]){
            TXT = text;

            // This makes an output pdf named after the program's name
            strcpy (fname, fileName); 
            strcat (fname, ".pdf");

            Spiral spiral(210, 300, 0, 40);
            HaruPDF doc;

            for (i = 0; i < strlen(TXT); i++) {
                char buf[2];
                ++spiral;
                doc.placeText(spiral.getTextX(), spiral.getTextY(), spiral.getLetterAngle());
                buf[0] = TXT[i]; // The character to display
                buf[1] = 0;
                doc.showText(buf); 
                
            }
            doc.saveToHPDF(fname);
        }
};

// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main (int argc, char **argv)
{
    SpiralPDF(argv[0], argv[1]);
    cout << "Done." << endl;
}
    