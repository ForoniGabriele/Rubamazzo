#include <iostream>
#include "carta.h"
#include "mazzoDiCarte.h"
#include "napoletano.h"

using namespace std;

int main()
{
    Napoletano mazzo; // mazzo iniziale
    Napoletano mazzoBanco; // mazzo centrale, inizialmente formato da 4 carte
    Napoletano manoG1; // mano del giocatore 1
    Napoletano manoG2; // mano del giocatore 2 / computer
    Napoletano mazzoPuntiG1; // mazzo punti giocatore 1
    Napoletano mazzoPuntiG2; // mazzo punti giocatore 2 / computer
    int turno = 1; // variabile utilizzata per capire se il turno attuale è del giocatore 1 oppure del giocatore 2 / computer

    // inizializzazione mazzo, poi mescolato
    mazzo.inizializza();
    mazzo.mescola();

    cout << "  _____            _                                                      " << endl;
    cout << " |  __ \\          | |                                                     " << endl;
    cout << " | |__) |  _   _  | |__     __ _   _ __ ___     __ _   ____  ____   ___  " << endl;
    cout << " |  _  /  | | | | | '_ \\   / _` | | '_ ` _ \\   / _` | |_  / |_  /  / _ \\ " << endl;
    cout << " | | \\ \\  | |_| | | |_) | | (_| | | | | | | | | (_| |  / /   / /  | (_) |" << endl;
    cout << " |_|  \\_\\  \\__,_| |_.__/   \\__,_| |_| |_| |_|  \\__,_| /___| /___|  \\___/ " << endl;

    // gestione scelta dell'utente
    int scelta = 0;
    do {
        cout << endl << " ( 1 ) Giocatore 1 VS Giocatore 2";
        cout << endl << " ( 2 ) Giocatore 1 VS Computer";
        cout << endl << " Scelta: ";
        cin >> scelta;
    } while (scelta < 1 || scelta > 2);

    system("CLS");

    //estrae le 4 carte da mettere al centro
    for(int i = 0; i < 4; i++) {
        mazzoBanco.aggiungiCarta(mazzo.estraiCarta());
    }

    // svolgimento - giocatore 1 vs giocatore 2
    if(scelta == 1) {
        do {
            cout << endl << " ------------------------------------"<< endl << endl;
            cout << endl << " CARTE AL CENTRO";
            mazzoBanco.stampa();
            cout << endl << endl << " ------------------------------------"<< endl << endl;

            // quando le mani dei giocatori sono vuote vengono pescate 3 carte
            if(manoG1.getDim() == 0) {
                for(int i = 0; i < 3; i++) {
                    manoG1.aggiungiCarta(mazzo.estraiCarta());
                }
            }
            if(manoG2.getDim() == 0) {
                for(int i = 0; i < 3; i++) {
                    manoG2.aggiungiCarta(mazzo.estraiCarta());
                }
            }

            // gestione del turno in base al giocatore
            if(turno == 1){
                cout << " CARTE IN MANO GIOCATORE 1";
                manoG1.stampa();
                cout << endl << " ------------------------------------"<< endl;
                cout << endl << " TURNO G1";
                mazzoBanco.turnoGiocatore(manoG1, mazzoPuntiG1, mazzoPuntiG2);
                turno = 2;
            }else{
                cout <<endl<< " CARTE IN MANO GIOCATORE 2";
                manoG2.stampa();
                cout << endl << " ------------------------------------"<< endl;
                cout << endl << " TURNO G2";
                mazzoBanco.turnoGiocatore(manoG2, mazzoPuntiG2, mazzoPuntiG1);
                turno = 1;
            }

            cout << endl << " ------------------------------------"<< endl;
            cout <<endl<< " MAZZETTO GIOCATORE 1";
            if(mazzoPuntiG1.getDim() != 0)
                mazzoPuntiG1.visualizzaCartaTop();
            else
                cout << endl << endl << " Mazzetto vuoto" << endl;

            cout << endl << " ------------------------------------"<< endl;
            cout << endl << " MAZZETTO GIOCATORE 2";
            if(mazzoPuntiG2.getDim() != 0)
                mazzoPuntiG2.visualizzaCartaTop();
            else
                cout << endl << endl << " Mazzetto vuoto" << endl;

        } while (mazzo.getDim() > 0 || manoG2.getDim() > 0);
    } else {
        // svolgimento - giocatore 1 vs computer

        do {
            cout << endl << " ------------------------------------"<< endl << endl;
            cout <<endl<< " CARTE AL CENTRO";
            mazzoBanco.stampa();
            cout << endl << endl << " ------------------------------------"<< endl << endl;

            //quando le mani del giocatore o del computer sono vuote vengono pescate 3 carte
            if(manoG1.getDim() == 0) {
                for(int i = 0; i < 3; i++) {
                    manoG1.aggiungiCarta(mazzo.estraiCarta());
                }
            }
            if(manoG2.getDim() == 0) {
                for(int i = 0; i < 3; i++) {
                    manoG2.aggiungiCarta(mazzo.estraiCarta());
                }
            }

            // gestione del turno in base al giocatore
            if(turno == 1){
                cout << " CARTE IN MANO GIOCATORE 1";
                manoG1.stampa();
                cout << endl << " ------------------------------------"<< endl;
                cout << endl << " TURNO G1";
                mazzoBanco.turnoGiocatore(manoG1, mazzoPuntiG1, mazzoPuntiG2);
                turno = 2;
            }else{
                cout << endl << " TURNO COMPUTER";
                mazzoBanco.turnoComputer(manoG2, mazzoPuntiG2, mazzoPuntiG1);
                turno = 1;
            }
        } while (mazzo.getDim() || manoG2.getDim() > 0);
    }

    system("CLS");

    cout << endl << " ------------------------------------"<< endl;
    cout << endl << " CARTE RIMASTE AL CENTRO: " << mazzoBanco.getDim() << endl;

    // stampa punti finali
    cout << endl << " ------------------------------------"<< endl;
    cout <<endl<< " PUNTI G1: ";
    cout << mazzoPuntiG1.getDim() << endl;

    cout << endl << " ------------------------------------" << endl;
    if(scelta == 1)
        cout << endl << " PUNTI G2: ";
    else
        cout << endl << " PUNTI COMPUTER: ";
    cout << mazzoPuntiG2.getDim() << endl;
    cout << endl << " ------------------------------------" << endl << endl;

    //stabilisce la vittoria in base al numero di carte nel mazzetto dei punti
    if(mazzoPuntiG1.getDim() > mazzoPuntiG2.getDim())
        cout << " VINCE IL GIOCATORE 1";
    else if(mazzoPuntiG1.getDim() < mazzoPuntiG2.getDim()){
        if(scelta == 1)
            cout << " VINCE IL GIOCATORE 2";
        else
            cout << " VINCE IL COMPUTER";
    } else
        cout << " PAREGGIO";
    cout << endl << endl << " ------------------------------------" << endl << endl;

    return 0;
}

