
// Libraries ----------------------------------

// stdio.h för printf och scanf
#include <stdio.h>
//string för string funktioner
#include <string.h>
//ctype för att använde toupper och tolower
#include <ctype.h>

//Definera antal elever och prov
#define AntalElever 5
#define AntalProv 13

//Main funktionen --------------------------
int main() {
    //Set Array
    char namn[AntalElever][11];
    //Set poäng
    int scores[AntalElever][AntalProv];
    //Antal poäng
    double medelvärde[AntalElever];
    //medelvärde
    double totalmedelvärde = 0.0;

    //variabeln för elever och prov
    int i, j;

    //Läs in data för 5 elever
    for (i = 0; i < AntalElever; i++) {
        //Läser in bara 10 bokstaver av namn
        scanf("%10s", namn[i]);

        for (j = 0; j < AntalProv; j++) {
            //läser in dem 13 prov
            scanf("%d", &scores[i][j]);
        }
    }

    //Gör första bokstaven stor och resten små
    for (i = 0; i < AntalElever; i++) {
        namn[i][0] = toupper(namn[i][0]);

        for (j = 1; namn[i][j] != '\0'; j++) {
            namn[i][j] = tolower(namn[i][j]);
        }
    }

    //Beräkna medelvärde för varje elev
    for (i = 0; i < AntalElever; i++) {
        int sum = 0;

        for (j = 0; j < AntalProv; j++) {
            //plussar alla prov poäng
            sum += scores[i][j];
        }

        //Set medelvärde och totalt medelvärde
        medelvärde[i] = (double)sum / AntalProv;
        totalmedelvärde += medelvärde[i];
    }

    // Gruppens medelvärde
    totalmedelvärde /= AntalElever;

    // Hitta högsta medelvärde
    int bestElev = 0;

    for (i = 1; i < AntalElever; i++) {
        //Updaterar i
        if (medelvärde[i] > medelvärde[bestElev]) {
            bestElev = i;
        }
    }

    // Skriv ut elev med högst medelvärde
    printf("%s\n", namn[bestElev]);

    // Skriv ut elever under gruppens snitt
    for (i = 0; i < AntalElever; i++) {
        if (medelvärde[i] < totalmedelvärde) {
            printf("%s\n", namn[i]);
        }
    }

    //Klart
    return 0;
}