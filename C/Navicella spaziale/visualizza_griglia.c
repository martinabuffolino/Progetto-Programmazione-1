#include "mio_header.h"

//function per la visualizzazione della griglia
void visualizza_griglia(char grid_temp[8][7], Navicella temp_veicolo[3], int tot_passi)
{
    char spazi[] = "                 ";

    //Dichiarazione variabili
    int     userR = 8;
    int     userC = 7;

    //Dichiarazione variabili
    char    cannoncino = '^';       //dichiarazione cannone
    char    zona_gialla = '#';      //dichiarazione zona gialla dove le navicelle possono essere colpite

    //Dichiarazione indici di interazione
    int     index_r;  //indice per scorrere sulle righe
    int     index_c;  //indice per scorrere sulle colonne

    //moltiplicatore per visualizzazione
    int     molt = 2;

    //Init posizione cannoncino
    grid_temp [7][3] = cannoncino;

    //posizione zona gialla
    if (grid_temp [0][2] != 'G'){ grid_temp [0][2] = zona_gialla; }
    if (grid_temp [0][3] != 'G'){ grid_temp [0][3] = zona_gialla; }
    if (grid_temp [0][4] != 'G'){ grid_temp [0][4] = zona_gialla; }
    if (grid_temp [1][2] != 'B'){ grid_temp [1][2] = zona_gialla; }
    if (grid_temp [1][4] != 'B'){ grid_temp [1][4] = zona_gialla; }
    if (grid_temp [2][2] != 'V'){ grid_temp [2][2] = zona_gialla; }
    if (grid_temp [2][3] != 'V'){ grid_temp [2][3] = zona_gialla; }
    if (grid_temp [2][4] != 'V'){ grid_temp [2][4] = zona_gialla; }

    //Messaggio iniziale
	printf("%s ****************************\n", spazi);
	printf("%s  *   NAVICELLA SPAZIALE   * \n", spazi);
	printf("%s ****************************\n", spazi);

    //cicla righe
    for(index_r = 0; index_r <= molt * userR; index_r++){     /* per index_r che è = a 0 fino a 2 * numero di righe
                                                                ogni riga ha: spazio vuoto - | - spazio vuoto; quindi
                                                                avremo tre posizioni 0-1-2*/

        //printa --- nelle posizioni pari
        if(index_r%2 == 0)//se la posizione iesima / 2 da resto zero
        {
            printf("%s ", spazi); //visualizza spazi
        } else {
            printf("%s", spazi); //visualizza spazi
        }

        //cicla colonne
        //per index_c che va da 0 a 2 che moltiplica nr. colonne(2*7); incrementa
        for(index_c = 0; index_c <= molt * userC; index_c++){

            //printa --- nelle posizioni pari
            if(index_r%2 == 0)//se la posizione iesima / 2 da resto zero
            {
                if(index_c%2 == 0)//se j/2 da resto 0 printa spazio
                    printf(" ");
                else    //altrimenti mi trovo in posizione dispari e printa ---
                    printf("---");
            }
            //printa | nelle posizioni dispari
            else{
                //se pari printa |
                if(index_c%2 == 0){
                    printf(" | ");
                }
                else{
                    printf("%c", grid_temp[index_r/2][index_c/2]);
                }
            }
        }
        printf("\n");
    }

    printf("**LEGENDA**\n");
    printf("- G: Navicella gialla.\n- B: Navicella blu.\n- V: Navicella verde.\n- ^: Cannoncino.\n- #: Zona dove le navicelle possono essere complite.\n");

    printf("\n**VITE TOTALI**\n");
    printf(" %c : %d | %c : %d | %c : %d | \n", temp_veicolo[0].colore, temp_veicolo[0].tot_vite, temp_veicolo[1].colore, temp_veicolo[1].tot_vite, temp_veicolo[2].colore, temp_veicolo[2].tot_vite);

    if (tot_passi > 0)
        printf("Numero passi totale: %d \n", tot_passi);

    system("pause");
    system("CLS");
}
