# Progetto-Programmazione-1
<b>Traccia 1: Navicelle spaziali</b>

Si vuole sviluppare un programma per la simulazione del gioco di 4 navicelle spaziali. La mappa da gioco è di forma rettangolare e di dimensioni 8x7.
Sulla mappa è posizione un cannoncino fermo (rettangolo rosso in figura)e si muovono 3 navicelle che devono essere colpite (rettangolo giallo, blu e verde).
Le tre navicelle ad ogni passo si muovono nel seguente modo:
• La navicella gialla ha la probabilità del 60% di muoversi di un singolo passo verso destra e il 40% di restare ferma.
• La navicella blue ha la probabilità del 70% di muoversi di due passi verso sinistra e il 30% di muoversi di un singolo passo verso sinistra.
• La navicella verde ha la probabilità del 40% di muoversi di tre passi verso destra, il 30% di muoversi di due passi verso destra e il 30% di muoversi di
un singolo passo verso destra.
Ad ogni passo il cannoncino rosso spara un colpo solo se al precedente passo una delle navicelle ha sostato nella zona gialla. La partita termina o quando l’utente ha distrutto le
3 navicelle o quando si raggiungono 100 passi.
Sviluppare un algoritmo che prevede la visualizzazione della mappa da gioco e delle posizioni delle navicelle. Effettuare almeno 3 simulazioni.

<b>Traccia 2: Distributore di carburante</b>

Si vuole simulare la gestione di un distributore automatico di carburante. Si suppone di avere 3 tipi di carburante identificati da un nome, da un codice identificativo, dal numero
di litri presenti nella scorta e da un prezzo per litro. Il distributore è gestito per un intero mese (31 giorni) (e.g., organizzazione matriciale).
Permettere all’utente di:
- Inserire dei soldi (5,10, 20, 50 euro)
- Scegliere il tipo carburante
  - Controllare se è possibile soddisfare la richiesta
  - Nel caso è possibile soddisfare la richiesta rifornire di carburante (aggiornando la scorta)
- Dato un giorno visualizzare il totale di carburante venduto.
