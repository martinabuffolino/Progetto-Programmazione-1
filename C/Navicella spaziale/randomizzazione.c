#include "mio_header.h"

//function per randomizzazione
void randomizzazione (int* tot_passi, Navicella temp_veicolo[0], char grid_temp[0][7], int* zona_tiro)
{
    int n;           //variabile utilizzata per numero pseudocausale

    n=rand() % 100;     //numero random su base 100
    printf("%c - Numero random: %d\n", temp_veicolo[0].colore, n);
    printf("%c - Posizione[r][c]:[%d][%d] \n", temp_veicolo[0].colore, temp_veicolo[0].pos_r, temp_veicolo[0].pos_c);

    // seleziona il tipo colore
    switch (temp_veicolo[0].colore) {

        case 'G':
            if (n <= 60)    //60% di probabilità (1 passo verso dx)
                {
                    grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';   //cancella la navicella dalla posizione precedente
                    temp_veicolo[0].n_passi = 1;                                     //aggiorna il numero di passi
                    *tot_passi += temp_veicolo[0].n_passi;                           //aggiorna il contatore totale dei passi

                    if (temp_veicolo[0].pos_c + temp_veicolo[0].n_passi >= 7)
                        temp_veicolo[0].pos_c = temp_veicolo[0].pos_c - 1;          //effetto pacman
                    else
                        temp_veicolo[0].pos_c +=  temp_veicolo[0].n_passi;          //avanza del numero di passi

                    printf("Ci stiamo spostando di %d passo verso dx.\n",temp_veicolo[0].n_passi);
                    printf("%c - Posizione[r][c]:[%d][%d] \n", temp_veicolo[0].colore, temp_veicolo[0].pos_r, temp_veicolo[0].pos_c);
                    grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = temp_veicolo[0].colore;    //inserisce navicella nella nuova posizione

                    if (temp_veicolo[0].pos_c == 2 && temp_veicolo[0].pos_r == 0 ) //controlla se siamo in zona tiro
                        {
                            printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                            zona_tiro = 1;
                            temp_veicolo[0].tot_vite -= 1;
                        }
                    if (temp_veicolo[0].pos_c == 3 && temp_veicolo[0].pos_r == 0 ) //controlla se siamo in zona tiro
                        {
                            printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                            zona_tiro = 1;
                            temp_veicolo[0].tot_vite -= 1;
                        }
                    if (temp_veicolo[0].pos_c == 4 && temp_veicolo[0].pos_r == 0 ) //controlla se siamo in zona tiro
                        {
                            printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                            zona_tiro = 1;
                            temp_veicolo[0].tot_vite -= 1;
                        }
                    if (temp_veicolo[0].tot_vite == 0)  //entra se son finite le vite
                        {
                            printf("Navicella distrutta.\n");
                            grid_temp [temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';      //cancellazione navicella da griglia
                        }

                } else {
                    printf("Non ci spostiamo.\n");
                }
                break;

        case 'B':
           if (n <= 70){   //70% di probabilità (2 passi verso sx)
                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';   //cancella la navicella dalla posizione precedente
                temp_veicolo[0].n_passi = 2;
                *tot_passi += temp_veicolo[0].n_passi;  //Aggiorna il contatore totale dei passi

                if (temp_veicolo[0].pos_c - temp_veicolo[0].n_passi  <=  0)
                    temp_veicolo[0].pos_c = temp_veicolo[0].n_passi + 4;        //effetto pacman
                else
                    temp_veicolo[0].pos_c -=  temp_veicolo[0].n_passi;          //avanza del numero di passi

                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = temp_veicolo[0].colore;    //inserisce navicella nella nuova posizione
                printf("Ci stiamo spostando di 2 passi verso sx.\n");
                printf("%c - Posizione[r][c]:[%d][%d] \n", temp_veicolo[0].colore, temp_veicolo[0].pos_r, temp_veicolo[0].pos_c);

                if (temp_veicolo[0].pos_c == 2 && temp_veicolo[0].pos_r == 1 ) //controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 4 && temp_veicolo[0].pos_r == 1 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }

                if (temp_veicolo[0].tot_vite == 0){
                    printf("Navicella distrutta.\n");
                    grid_temp [temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';      //cancellazione navicella da griglia
                }

            } else {       //30% di probabilità (1 passo verso sx)
                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';   //cancella la navicella dalla posizione precedente
                temp_veicolo[0].n_passi = 1;
                *tot_passi += temp_veicolo[0].n_passi;  //Aggiorna il contatore totale dei passi

                if (temp_veicolo[0].pos_c + temp_veicolo[0].n_passi <= 0)
                    temp_veicolo[0].pos_c = temp_veicolo[0].pos_c - 1;        //effetto pacman
                else
                    temp_veicolo[0].pos_c -=  temp_veicolo[0].n_passi;          //avanza del numero di passi

                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = temp_veicolo[0].colore;    //inserisce navicella nella nuova posizione
                printf("Ci stiamo spostando di 1 passo verso sx.\n");
                printf("%c - Posizione[r][c]:[%d][%d] \n", temp_veicolo[0].colore, temp_veicolo[0].pos_r, temp_veicolo[0].pos_c);

                if (temp_veicolo[0].pos_c == 3 && temp_veicolo[0].pos_r == 1 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 4 && temp_veicolo[0].pos_r == 1 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }

                if (temp_veicolo[0].tot_vite == 0){
                    printf("Navicella distrutta.\n");
                    grid_temp [temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';      //cancellazione navicella da griglia
                }
            }
            break;

        case 'V':
           if (n <= 40){           //40% di probabilità (3 passi verso dx)
                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';   //cancella la navicella dalla posizione precedente
                temp_veicolo[0].n_passi = 3;
                *tot_passi += temp_veicolo[0].n_passi;  //Aggiorna il contatore totale dei passi

                if (temp_veicolo[0].pos_c + temp_veicolo[0].n_passi >= 7)
                    temp_veicolo[0].pos_c = temp_veicolo[0].pos_c - 4;        //effetto pacman
                else
                    temp_veicolo[0].pos_c +=  temp_veicolo[0].n_passi;          //avanza del numero di passi

                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = temp_veicolo[0].colore;    //inserisce navicella nella nuova posizione
                printf("Ci stiamo spostando di 3 passi verso dx.\n");
                printf("%c - Posizione[r][c]:[%d][%d] \n", temp_veicolo[0].colore, temp_veicolo[0].pos_r, temp_veicolo[0].pos_c);

                if (temp_veicolo[0].pos_c == 2 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 3 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 4 && temp_veicolo[0].pos_r == 3 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }

                 if (temp_veicolo[0].tot_vite == 0){
                    printf("Navicella distrutta.\n");
                    grid_temp [temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';      //cancellazione navicella da griglia
                }

            } else if (n > 40 && n <= 70){   //30% di probabilità (2 passi verso dx)
                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';   //cancella la navicella dalla posizione precedente
                temp_veicolo[0].n_passi = 2;
                *tot_passi += temp_veicolo[0].n_passi;  //Aggiorna il contatore totale dei passi

                if (temp_veicolo[0].pos_c + temp_veicolo[0].n_passi >= 7)
                    temp_veicolo[0].pos_c = temp_veicolo[0].pos_c - 1;        //effetto pacman
                else
                    temp_veicolo[0].pos_c +=  temp_veicolo[0].n_passi;          //avanza del numero di passi

                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = temp_veicolo[0].colore;    //inserisce navicella nella nuova posizione
                printf("Ci stiamo spostando di 2 passi verso dx.\n");
                printf("%c - Posizione[r][c]:[%d][%d] \n", temp_veicolo[0].colore, temp_veicolo[0].pos_r, temp_veicolo[0].pos_c);

                if (temp_veicolo[0].pos_c == 2 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 3 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 4 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }

                 if (temp_veicolo[0].tot_vite == 0){
                    printf("Navicella distrutta.\n");
                    grid_temp [temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';      //cancellazione navicella da griglia
                }

            } else {   //30% di probabilità (1 passo verso dx)
                grid_temp[temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';   //cancella la navicella dalla posizione precedente
                temp_veicolo[0].n_passi = 1;
                *tot_passi += temp_veicolo[0].n_passi;  //Aggiorna il contatore totale dei passi

                if (temp_veicolo[0].pos_c + temp_veicolo[0].n_passi >= 7)
                    temp_veicolo[0].pos_c = temp_veicolo[0].pos_c - 1;        //effetto pacman
                else
                    temp_veicolo[0].pos_c +=  temp_veicolo[0].n_passi;          //avanza del numero di passi

                grid_temp [temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = temp_veicolo[0].colore;    //inserisce navicella nella nuova posizione
                printf("Ci stiamo spostando di 1 passo verso dx.\n");
                printf("%c - Posizione[r][c]:[%d][%d] \n", temp_veicolo[0].colore, temp_veicolo[0].pos_r, temp_veicolo[0].pos_c);

                if (temp_veicolo[0].pos_c == 2 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 3 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }
                if (temp_veicolo[0].pos_c == 4 && temp_veicolo[0].pos_r == 2 )//controlla se siamo in zona tiro
                    {
                        printf("Siamo in zona tiro. Il cannoncino ha tolto una vita.\n");
                        zona_tiro = 1;
                        temp_veicolo[0].tot_vite -= 1;
                    }

                 if (temp_veicolo[0].tot_vite == 0){
                    printf("Navicella distrutta.\n");
                    grid_temp [temp_veicolo[0].pos_r][temp_veicolo[0].pos_c] = ' ';      //cancellazione navicella da griglia
                }

            }
            break;

        default:
            printf("Non verranno aggiunti passi.\n");
    }

    printf("Totale passi: %d \n\n", *tot_passi);

    system("pause");    //mettere in pausa il sistema fino al prossimo segnale
    system("CLS");      //pulire lo schermo
}
