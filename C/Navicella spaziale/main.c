#include "mio_header.h"

void main()
{
    //dichiarazione variabili
    int     tot_passi = 0;  //variabile  utilizzata per incremento dei passi fatti dalle navicelle inizializzata inizialmente a 0
    int     zona_tiro = 0;  //se true una navice è in zona tiro
    char    spazi[] = "                 ";

    //dichiarazione indici di interazione
    int     index_r;    //indice per scorrere sulle righe
    int     index_c;    //indice per scorrere sulle colonne

    //dichiarazione griglia
	char grid_matrix[8][7];

	//inizializzo a vuoto
    for (index_r = 0; index_r < 8; index_r++)
        {
        for (index_c = 0; index_c < 7; index_c++)
        {
            grid_matrix[index_r][index_c] = ' ';
        }
    }

    //definizione array iniziale
    Navicella array_veicoli[3]={
        {'G',0,0,0,3},
        {'B',1,3,0,3},
        {'V',2,6,0,3}
    };

    //posizione navicelle
    grid_matrix[array_veicoli[0].pos_r][array_veicoli[0].pos_c] = array_veicoli[0].colore;
    grid_matrix[array_veicoli[1].pos_r][array_veicoli[1].pos_c] = array_veicoli[1].colore;
    grid_matrix[array_veicoli[2].pos_r][array_veicoli[2].pos_c] = array_veicoli[2].colore;

    //Visualizzazione iniziale della griglia
    visualizza_griglia(grid_matrix, array_veicoli, tot_passi);

    //pulisci schermo
    system("CLS");

    //cicla finchè il numero dei passi è < di 100 o finchè le navicelle hanno almeno una vita
    do  //Inizio ciclo do-while
    {
        //aggiorniamo il valore totale dei passi e salviamo le coordinate della nuova posizione delle navicelle

        if (array_veicoli[0].tot_vite > 0){
            //randomizzazione - g
            randomizzazione(&tot_passi, &array_veicoli[0], &grid_matrix, &zona_tiro);

            //visualizzazione iniziale della griglia
            visualizza_griglia(grid_matrix, array_veicoli, tot_passi);
        }

        if (array_veicoli[1].tot_vite > 0){
            //randimizzazione - b
            randomizzazione(&tot_passi, &array_veicoli[1], &grid_matrix, &zona_tiro);

            //Visualizzazione iniziale della griglia
            visualizza_griglia(grid_matrix, array_veicoli, tot_passi);
        }

        if (array_veicoli[2].tot_vite > 0){
            //randimizzazione - v
            randomizzazione(&tot_passi, &array_veicoli[2], &grid_matrix, &zona_tiro);

            //Visualizzazione iniziale della griglia
            visualizza_griglia(grid_matrix, array_veicoli, tot_passi);
        }

    } while (tot_passi < 100 || (array_veicoli[0].tot_vite + array_veicoli[1].tot_vite + array_veicoli[2].tot_vite) > 0);

    system("pause");

}

