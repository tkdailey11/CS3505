/*
 * Fascade Class written to provide more convenient access to the HaruPDF C library.
 * Written By: Tyler Dailey, 9/3/16
 * Assignment 2, CS3505
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"
#include "HaruPDF.h"

using namespace std;

HPDF_Doc pdf;
HPDF_Page page;
char fname[256];
HPDF_Font font;

HaruPDF::HaruPDF(){
    pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    font = HPDF_GetFont (pdf, "Helvetica", NULL);

    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);

    HPDF_Page_BeginText (page);

    HPDF_Page_SetFontAndSize (page, font, 30);
}

int main(){
return 0;
}

void HaruPDF::placeCharacter(char character){
    char buf[2];
    // C-style strings are null-terminated. The last character must a 0.
    buf[0] = character; // The character to display
    buf[1] = 0;
    HPDF_Page_ShowText (page, buf);
}

void HaruPDF::save(char *filename){
    HPDF_Page_EndText (page);
    strcpy (fname, filename);
    strcat (fname, ".pdf");

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);
}

void HaruPDF::advancePosition(double a, double b, double c, double d, double x, double y){
    HPDF_Page_SetTextMatrix(page, a, b, c, d, x, y);
}
