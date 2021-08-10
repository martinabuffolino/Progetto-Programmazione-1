#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definisco la struttura per memorizzare i dati del carburante
struct carburante {
    char    nome[10];	//Tipo di carburante
    int     id_code;	//Codice del carburante
    float   L_scorta;	//Litri presenti nella scorta
    float   L_price;	//Prezzo per litri
};
typedef struct  carburante  Carburante;

//Definisco la struttura data per memorizzare il giorno e il totale venduto di ogni carburante
struct data {
    int     giorno;
    int     metano_venduto;
    int     diesel_venduto;
    int     gpl_venduto;
};
typedef struct data Data;


