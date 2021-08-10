#include "mio_header.h"

void main()
{
	//dichiarazioni variabili
    int     cash_value;                 //variabile utilizzata per il valore della cash_value inserita
    int     tot_cash = 0;		        //variabile utilizzata per il calcolo delle banconote versate, azzeramento variabile
	int		user_carburante;	        //variabile utilizzata per il tipo di carburante scelto
	float	user_litri;			        //variabile utilizzata per il numero di litri richiesti
	float	agg_scorta;                 //variabile utilizzata per l'aggiornamento della scorta
	int    	procedi;			        //variabile utilizzata per consentire l'uscita dai cicli (do-while)
	int     inserisci;                  //variabile utilizzata per consentire l'uscita dal ciclio (do-while) per la richiesta giorno
    int     giorno_richiesto;			//variabili utilizzate per inserire giorno
    char    spazi[] = "                 "; //per spazio


	//Dichiarazione variabili iterative
	int     i;                  //Indice di iterazione

	//definizione array iniziale
    Carburante array_carburante[3]={{"METANO",0,100,0.70},
                                    {"DIESEL",1,100,1.35},
                                    {"GPL", 2,100,0.90}
                                    };

    Data array_data[31]={{0,54,66,87},
                         {1,150,70,80},
                         {2,140,78,88},
                         {3,50,74,66},
                         {4,160,63,50},
                         {5,80,35,60},
                         {6,139,77,54},
                         {7,66,43,67},
                         {8,89,86,54},
                         {9,75,73,35},
                         {10,54,35,80},
                         {11,71,70,77},
                         {12,155,300,60},
                         {13,167,70,54},
                         {14,122,45,84},
                         {15,121,76,86},
                         {16,145,54,77},
                         {17,125,46,58},
                         {18,198,198,110},
                         {19,200,167,90},
                         {20,43,190,80},
                         {21,57,378,100},
                         {22,86,202,93},
                         {23,74,301,80},
                         {24,63,267,96},
                         {25,76,200,90},
                         {26,77,189,97},
                         {27,53,150,90},
                         {28,56,546,80},
                         {29,133,54,80},
                         {30,45,345,83}

    };

	//Messaggio iniziale
	printf("%s****************************************",spazi);
	printf("\n%s*      DISTRIBUTORE DI CARBURANTE      *\n",spazi);
	printf("%s****************************************",spazi);

//Inizio ciclo di ripetizione do-while
	do {
        //Inserimento Banconote
        do	{

            printf("\n\n**INSERIRE BANCONOTE**\n(Tagli Consentiti: 5 euro / 10 euro / 20 euro / 50 euro) : \n");
                //prendi valore
            scanf ("%d",&cash_value);

            /*Entra in IF se il predicato risulta vero. Terminata l'istruzione esce dal costrutto di selezione (if).
            Altrimenti, in caso contrario, eseguie l'istruzione ed esce*/
            if (cash_value == 5 || cash_value == 10 || cash_value == 20 || cash_value == 50)
                tot_cash += cash_value;     //aggiorna il toale dei soldi inseriti
            else
                printf("La banconota inserita non e' consentita.\n\n");

            //Chiede se si vogliono inserire altre banconote
            printf("\nSe vuoi inserire altre banconote digita 0 altrimenti digita un altro numero: ");
            scanf("%d", &procedi);

        }  while (procedi == 0);	//Resta nel ciclo finchè la condizione non è soddisfatta  //da vedere la tipologia perchè se inseriamo un carattere mi sa che va in crash!!!

        printf("Totale inserito: %d euro\n\n",tot_cash);

        do	{

            printf("***CARBURANTI PRESENTI NEL DISTRUBUTORE***\n");

            //Stampa per ogni carburante: nome, codice, litri presenti nella scorta e prezzo per litro
            for (i = 0; i < 3; i++)
            {
                printf("\n [%d] %s - Scorta: %.2f - Prezzo: %.2f", array_carburante[i].id_code,array_carburante[i].nome, array_carburante[i].L_scorta, array_carburante[i].L_price); // AGGIUNTI LE UNITA' DI MISURA ed a cosa fanno riferimento i valori NEL MESSAGGIO VISUALIZZATO!!!
            }

            //fai selezionare all'utente il carburante
            printf("\n\nSeleziona il numero riferito al carburante: ");
            scanf("%d", &user_carburante);

            //Calcolare quanti litri occorrono in base al prezzo del carburante selezionato e alle banconote versate
            user_litri = tot_cash / array_carburante[user_carburante].L_price;

            /*Se la scorta di litri risulta maggiore di zero e maggiore uguale dei litri richiesti,
            quindi se le due istruzioni risultano entrambi vere si entra nel then stampando la richiesta e l'aggiornamento dell scorta*/
            if ((array_carburante[user_carburante].L_scorta > 0) && (array_carburante[user_carburante].L_scorta >= user_litri))
            {
                printf("\nErogazione in corso...\n");

                printf("Carburante erogato.\n");

                //Calcolare aggiornamento della scorta sottraendo ai litri presenti quelli richiesti
                array_carburante[user_carburante].L_scorta -= user_litri;

                printf("\nScorta Restante: %.2f", array_carburante[user_carburante].L_scorta); //aggiungi la dicitura L di litri alla fine del messaggio!!!
            }
            else	//Altrimenti se il predicato risulta falso entra nell'else
            {

                if (array_carburante[user_carburante].L_scorta == 0)
                    printf("\nScorta di carburante terminata. \n");

                else if (array_carburante[user_carburante].L_scorta < user_litri)
                    printf("\nNon è possibile soddisfare la richiesta in quanto la scorta necessaria è inferiore a quanto richeisto. \n");

                procedi = 0;
            };

        }  while (procedi == 0);	//Resta nel ciclo finchè la condizione non è soddisfatta

        //Visualizza un divisore per dividere la parte user (autista) dalla parte di amministrazione (admin)
        printf("\n\n***RIFORNIMENTO COMPLETATO***\n");

        //Visualizza un divisore per dividere la parte user (autista) dalla parte di amministrazione (admin)
        printf("\n*********************************\n\n");

        //Dato un giorno visualizzare il totale di carburante venduto
        printf("Se vuoi visualizzare il totale carburante venduto in un dato giorno digita 0 altrimenti digita un altro numero: ");
        scanf("%d", &procedi);


        //richiesta giorno
        if (procedi == 0)
        {
            printf("\n***VISUALLIZZAZIONE DEL TOTALE CARBURANTE VENDUTO IN UN DATO GIORNO***");

        do {
            printf("\nDigita il giorno richiesto: ");
            scanf("%d", &giorno_richiesto);


                    //Confronto del giorno  inserito dall'utente con la data nella struct
                    if ( giorno_richiesto == array_data[giorno_richiesto].giorno )
                        {
                            printf("ricerca in corso..");
                            printf("\nData trovata.\n");
                            printf("\nDigita 1 per visualizzare: ");
                            scanf("%d", &inserisci);
                        }

                    else
                    {
                        printf("\nLa data inserita non esiste\n");
                        printf("Per inserire un'altra data digita 0 altrimenti digita 1 per uscire: ");
                        scanf("%d", &inserisci);
                    }

                }while (inserisci == 0);

            //stampa del totale di carburante venuto in tale giorno
            printf("\nIl totale carburane venduto il giorno %d e':\n%d per il METANO\n%d per DIESEL\n%d per il GPL", giorno_richiesto,array_data[giorno_richiesto].metano_venduto, array_data[giorno_richiesto].diesel_venduto, array_data[giorno_richiesto].gpl_venduto);
        }

        //Possibilità di effettare un'altra erogazione o di terminare il programma
        printf("\n\nDigita 0 se vuoi effettuare un'altra erogazione altrimenti digita un altro numero: ");
        scanf("%d", &procedi);

	}   while(procedi ==0);

	printf("\n\n%s*************************",spazi);
	printf("\n%s***PROGRAMMA TERMINATO***\n",spazi);
	printf("%s**************************\n\n",spazi);
}
