/* Test code for the HaruPDF class*/
#include <string.h>
#include "HaruPDF.h"
#include "Spiral.h"

int main(int argc, char **argv){
    char *filename = argv[0];
    char *text = argv[1];

    HaruPDF pdf;
    Spiral sp = Spiral(250, 250, 2);

    unsigned int i;

    for(i=0; i < strlen(text); i++){
        pdf.advancePosition(sp.get_text_angle(), sp.get_text_x(), sp.get_text_y());
        pdf.placeCharacter(text[i]);
        std::cout << sp;
        ++sp;
    }

    pdf.save(filename);



    return 0;
}
