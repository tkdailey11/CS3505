/*
 * << Alternative PDF Library 1.0.0 >> -- text_demo2.c
 *
 * Copyright (c) 1999-2006 Takeshi Kanno <takeshi_kanno@est.hi-ho.ne.jp>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 * Modified by Tyler Dailey, University of Utah, 2016.
 *
 * This is a Fascade Class written to provide more convenient access to the HaruPDF library mentioned above.
 * Written By: Tyler Dailey, 9/7/16
 * Assignment 2, CS3505
 */

#include "HaruPDF.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"

using namespace std;

HPDF_Doc pdf;
HPDF_Page page;
char fname[256];
HPDF_Font font;

/*
 * Creates an object which can interact with the Haru Library to create a pdf
 * document, however this class provides an easier to use interface.
 */
HaruPDF::HaruPDF(){
    pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    font = HPDF_GetFont (pdf, "Helvetica", NULL);

    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);

    HPDF_Page_BeginText (page);

    HPDF_Page_SetFontAndSize (page, font, 20);
}

/* Place a character at the current position on the page. */
void HaruPDF::placeCharacter(char character){
    char buf[2];
    // C-style strings are null-terminated. The last character must a 0.
    buf[0] = character; // The character to display
    buf[1] = 0;
    HPDF_Page_ShowText (page, buf);
}

/* Given a double rad1 (determines angle of character, and an x and y coordinate, advance to the next position on the page, determined by the given xy coordinate.) */
void HaruPDF::advancePosition(double rad1, double x, double y){
    HPDF_Page_SetTextMatrix(page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);
}

/* Save the current document to filename.pdf */
void HaruPDF::save(char *filename){
    HPDF_Page_EndText (page);
    strcpy (fname, filename);
    strcat (fname, ".pdf");

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);
}
