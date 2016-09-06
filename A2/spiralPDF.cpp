/*
 * Written By: Tyler Dailey, for Assignment 2, CS3505, 9/5/16
 */
#include <string.h>
#include "HaruPDF.h"
#include "Spiral.h"

/*
 * This code is used to test that the HaruPDF and Spiral class implementations work cohesively to produce a nice spiral text pdf document.
 * The parameter argc is the number of arguments, and argv is an array of character arrays. If the program were run like: ./HaruPDFTest
 * "Sample Text", argv[0] would be "HaruPDFTest" (which is used to name the output file), and argv[1] would be "Sample Text",
 * which is the text fed into the program.
 */
int main(int argc, char **argv){
    char *filename = argv[0];
    char *text = argv[1];

    HaruPDF pdf;
    Spiral sp = Spiral(200, 300, 45);

    unsigned int i;

    for(i=0; i < strlen(text); i++){
        pdf.advancePosition(sp.get_text_angle(), sp.get_text_x(), sp.get_text_y());
        pdf.placeCharacter(text[i]);

        //Use either the pre-increment or post-increment operators, they produce the same output.
        //++sp;
        sp++;
    }

    pdf.save(filename);
    return 0;
}
