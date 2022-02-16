/* 
 * Camille van Ginkel u0953582 Jan 31, 2022
 */

#ifndef HARUPDF_H
#define HARUPDF_H
#include "hpdf.h"

class HaruPDF {
private:
    HPDF_Doc  pdf;
    HPDF_Page page;
    HPDF_Font font;

public:
    HaruPDF();
    void placeText(double x, double y, double angle);
    void showText(char text[]);
    void saveToHPDF(char filename[]);
};

#endif // include guard for Spiral.h


