/* 
 * Camille van Ginkel u0953582 Jan 31, 2022
 */

#include <math.h>
#include "HaruPDF.h"
#include "hpdf.h"
HaruPDF::HaruPDF() { //: pdf(HPDF_New (NULL, NULL), page(HPDF_AddPage (pdf)), font(HPDF_GetFont (pdf, "Helvetica", NULL))) {
    pdf = HPDF_New (NULL, NULL);
    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    //    print_grid  (pdf, page);
    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);

    HPDF_Page_BeginText (page);
    // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 12);
}

void HaruPDF::placeText(double x, double y, double angle) {
    // This ugly function defines where any following text will be placed
    // on the page. The cos/sin stuff is actually defining a 2D rotation
    // matrix.
     HPDF_Page_SetTextMatrix(page,cos(angle), sin(angle), -sin(angle), cos(angle),x, y);
}

void HaruPDF::showText(char buf[]){
    HPDF_Page_ShowText (page, buf);
    return;
}
void HaruPDF::saveToHPDF(char filename[]){
    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, filename);

    /* clean up */
    HPDF_Free (pdf);
    return;
}

