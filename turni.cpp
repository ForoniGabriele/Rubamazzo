#include "napoletano.h"
#include <iostream>
#include <ctime>

using namespace std;

void Napoletano::turnoGiocatore(Napoletano& mano, Napoletano& mazzoPunti, Napoletano& mazzoPuntiAvversario){
    int utilizza; // carta da usare
    // variabile che indica l'azione eseguita dal computer durante il suo turno
    int flag = 0; // 1: mazzo rubato all'avversario, 2: presa carta dal centro, 3: scartata una carta della propria mano al centro
    Carta ca; // carta salvata per gestire l'output che descrive l'azione eseguita dal computer

    //estrae la carta da usare
    do{
        cout << endl << " Carta da usare: ";
        cin >> utilizza;
    }while(utilizza < 1 || utilizza > mano.dim);

    int cartaInCampo = isCartaPresenteInCampo(mano.c[utilizza - 1].getNumero());

    // controlla se e' possibile rubare il mazzetto avversario
    if(mazzoPuntiAvversario.isMazzoEmpty() == false && isMazzettoPrendibile(mano.c[utilizza - 1], mazzoPuntiAvversario)){
        mazzoPunti.rubaMazzo(mazzoPuntiAvversario);
        mazzoPunti.aggiungiCarta(mano.c[utilizza - 1]);
        mano.estraiCarta(utilizza);
        flag = 1;
    // se invece la carta si trova in campo
    } else if(cartaInCampo != -1) {
        mazzoPunti.aggiungiCarta(mano.estraiCarta(utilizza));
        mazzoPunti.aggiungiCarta(c[cartaInCampo - 1]);
        ca = estraiCarta(cartaInCampo);
        flag = 2;
    //se le condizioni precedenti non sono verificate allora aggiunge la carta al mazzo centrale
    } else {
        aggiungiCarta(mano.c[utilizza - 1]);
        ca = mano.estraiCarta(utilizza);
        flag = 3;
    }

    system("CLS");

    switch(flag) {
        case 1:
            cout << endl << " Il giocatore avversario ti ha rubato il mazzetto dei punti!" << endl;
            break;
        case 2:
            cout << endl << " Il giocatore avversario ha preso una carta dal centro di valore " << ca.getNumero() << endl;
            break;
        case 3:
            cout << endl << " Il giocatore avversario ha scartato una carta al centro di valore " << ca.getNumero() << endl;
    }
}

void Napoletano::turnoComputer(Napoletano& mano, Napoletano& mazzoPunti, Napoletano& mazzoPuntiAvversario){
    int i = 0, j = 0, k = 0, pos = 0;
    bool trovata = false;
    // variabile che indica l'azione eseguita dal computer durante il suo turno
    int flag = 0; // 1: mazzo rubato all'avversario, 2: presa carta dal centro, 3: scartata una carta della propria mano al centro
    Carta ca; // carta salvata per gestire l'output che descrive l'azione eseguita dal computer

    // confronto delle carte nella mano del computer con la carta in cima al mazzetto dei punti avversario
    while(i < mano.dim && mano.c[i].getNumero() != mazzoPuntiAvversario.getCartaTop().getNumero())
        i++;

    if(i < mano.dim) { // se trova una carta uguale alla carta in cima al mazzetto dei punti avversario
        // ruba il mazzetto avversario, aggiunge la carta usata per rubare il mazzo al proprio mazzetto dei punti e la toglie dalle carte nella propria mano
        mazzoPunti.rubaMazzo(mazzoPuntiAvversario);
        mazzoPunti.aggiungiCarta(mano.c[i]);
        mano.estraiCarta(i + 1);
        flag = 1;
    } else { // altrimenti
        // confronto delle carte nella mano del computer con quelle nel centro
        while(j < mano.dim && !trovata) {
            k = 0;
            while(k < getDim() && !trovata) {
                if(mano.c[j].getNumero() == c[k].getNumero()) {
                    trovata = true;
                    pos = k;
                }
                k++;
            }
            j++;
        }

        // se non trova una corrispondenza tra una carta nella propria mano e una di quelle al centro
        if (!trovata) {
            // scelta di una carta casuale da giocare tra quelle nella mano
            srand(time(0));
            int randomIndex = rand() % mano.dim;
            aggiungiCarta(mano.c[randomIndex]);
            ca = mano.estraiCarta(randomIndex + 1);
            flag = 3;

        } else {
            // aggiornamento del mazzetto dei punti del computer e della sua mano
            mazzoPunti.aggiungiCarta(c[pos]);
            mazzoPunti.aggiungiCarta(mano.c[j - 1]);
            ca = estraiCarta(pos + 1);
            mano.estraiCarta(j);
            flag = 2;
        }
    }

    system("CLS");

    // selezione multipla per gestire l'output che descrive all'utente l'azione svolta dal computer durante il suo turno
    switch(flag) {
        case 1:
            cout << endl << " Il computer ti ha rubato il mazzetto dei punti!" << endl;
            break;
        case 2:
            cout << endl << " Il computer ha preso una carta dal centro di valore " << ca.getNumero() << endl;
            break;
        case 3:
            cout << endl << " Il computer ha scartato una carta al centro di valore " << ca.getNumero() << endl;
    }

    //stampa del mazzetto del giocatore
    cout << endl << " ------------------------------------"<< endl;
    cout << endl << " MAZZETTO GIOCATORE ";
    if(mazzoPuntiAvversario.dim != 0)
        mazzoPuntiAvversario.visualizzaCartaTop();
    else
        cout << endl << endl << " Mazzetto vuoto" << endl;

    //stampa del mazzetto del comnputer
    cout << endl << " ------------------------------------"<< endl;
    cout << endl << " MAZZETTO COMPUTER ";
    if(mazzoPunti.dim != 0)
        mazzoPunti.visualizzaCartaTop();
    else
        cout << endl << endl << " Mazzetto vuoto" << endl;
}
