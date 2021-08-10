#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//crezione struttura
struct  navicella{
    char    colore;     //colore navicelle: gialla, blu, verde
    int     pos_r;      //spostamento sull'asse delle ordinate (righe) NOTA: NON VERRA' MAI UTILIZZATA
    int     pos_c;      //spostamento sull'asse delle ascisse (colonne)
    int     n_passi;    //numero passi per spostamento
    int     tot_vite;   //numero di vite
};

//definizione della struttura
typedef struct navicella Navicella;

//Prototipi di funzione
void visualizza_griglia(char grid_temp[8][7], Navicella temp_veicolo[3], int tot_passi);
void randomizzazione (int* tot_passi, Navicella temp_veicolo[0], char grid_temp[8][7], int* zona_tiro);
