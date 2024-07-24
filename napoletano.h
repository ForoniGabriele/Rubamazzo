#ifndef NAPOLETANO_H
#define NAPOLETANO_H

#include "mazzoDiCarte.h"

class Napoletano : public MazzoDiCarte {
	public:
		Napoletano();
		~Napoletano();

		//restituisce il numero di carte nel mazzo
		int getDim();
		//restituisce il mazzo
		Carta* getMazzo();
		//inizializza il mazzo con seme, nome e numero di carta
		//metodo puro nella classe mazzoDiCarte, di conseguenza implementato nella sua classe figlia
		void inizializza();
		//stampa il mazzo
        void stampa();
        //mescola randomicamente il mazzo
        void mescola();
        //aggiunge una carta a scelta al mazzo
        void aggiungiCarta(Carta carta);
        //estrae l'ultima carta del mazzo
        Carta estraiCarta();
        //estrae la carta in posizione passata come parametro
        Carta estraiCarta(int pos);
        //visualizza la carta il cima al mazzo
        void visualizzaCartaTop();
        // restituisce la carta in cima al mazzo
        Carta getCartaTop();
        //aggiunge il mazzo avversario al proprio
        void rubaMazzo(Napoletano& mazzo);
        //controlla se la carta e' presente nel campo centrale e restituisce la sua posizione, se non e' presente restituisce -1
        int isCartaPresenteInCampo(int num);
        //controlla se il mazzo e' vuoto
        bool isMazzoEmpty();
        //controlla se e' possibile rubare il mazzetto avversario
        bool isMazzettoPrendibile(Carta cartaScelta, Napoletano& mazzoPuntiAvversario);
        //funzione per lo svolgimento del turno del giocatore
        void turnoGiocatore(Napoletano& mazzo, Napoletano& mazzoPunti, Napoletano& mazzoPuntiAvversario);
        //funzione per lo svolgimento del turno del computer
        void turnoComputer(Napoletano& mano, Napoletano& mazzoPunti, Napoletano& mazzoPuntiAvversario);
};

#endif // NAPOLETANO_H

