#ifndef CARTA_H
#define CARTA_H

#include <iostream>

using namespace std;

class Carta {
    private:
        string seme; // seme della carta
        string nome; // nome della carta
        int numero; // numero della carta

    public:
        // costruttore di default
        Carta();
        // costruttore orientato ai parametri
        Carta(string seed, string name, int number);
        // restituisce il numero della carta
        int getNumero();
        // per modificare il seme della carta
        void setSeme(string seed);
        // per modificare il nome della carta
        void setNome(string name);
        // per modificare il number della carta
        void setNumero(int number);
        // overloading operatore >> per la stampa in output di una carta
        friend istream& operator>>(istream& inp, Carta& c);
        // overloading operatore << per prendere in input una carta
        friend ostream& operator<<(ostream& out, const Carta& c);
        // overloading operatore == per il confronto tra 2 carte
        bool operator==(Carta c);
};

#endif // CARTA_H
