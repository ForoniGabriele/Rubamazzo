#include <iostream>
#include "carta.h"

using namespace std;

Carta::Carta() {
    seme = "undefined";
    nome = "undefined";
    numero = 0;
}

Carta::Carta(string seed, string name, int number) {
    seme = seed;
    nome = name;
    numero = number;

    if(seme != "bastoni" && seme != "denari" && seme != "coppe" && seme != "spade")
        seme = "undefined";

    if(nome != "asso" && nome != "due" && nome != "tre" && nome != "quattro" && nome != "cinque" && nome != "sei" && nome != "sette" && nome != "fante" && nome != "cavallo" && nome != "re")
        nome = "undefined";

    if(numero < 1 || numero > 10)
        numero = 0;
}

int Carta::getNumero(){
    return numero;
}

void Carta::setSeme(string seed) {
    seme = seed;
    if(seme != "bastoni" && seme != "denari" && seme != "coppe" && seme != "spade")
        seme = "undefined";
}

void Carta::setNome(string name) {
    nome = name;
    if(nome != "asso" && nome != "due" && nome != "tre" && nome != "quattro" && nome != "cinque" && nome != "sei" && nome != "sette" && nome != "fante" && nome != "cavallo" && nome != "re")
        nome = "undefined";
}

void Carta::setNumero(int number) {
    numero = number;
    if(numero < 1 || numero > 10)
        numero = 0;
}


istream& operator>>(istream& inp, Carta& c) {
    do {
        cout << endl << "Seme: ";
        inp >> c.seme;
    } while (c.seme != "bastoni" && c.seme != "denari" && c.seme != "coppe" && c.seme != "spade");

    do {
        cout << endl << "Nome: ";
        inp >> c.nome;
    } while (c.nome != "asso" && c.nome != "due" && c.nome != "tre" && c.nome != "quattro" && c.nome != "cinque" && c.nome != "sei" && c.nome != "sette" && c.nome != "fante" && c.nome != "cavallo" && c.nome != "re");

    do {
        cout << endl << "Numero: ";
        inp >> c.numero;
    } while (c.numero < 1 || c.numero > 10);

    return inp;
}

ostream& operator<<(ostream& out, const Carta& c) {
    out << endl << " " << c.nome << " di " << c.seme << endl;
    out << " Numero: " << c.numero << endl;

    return out;
}


bool Carta::operator==(Carta c){
    if(c.nome == nome && c.numero == numero && c.seme == seme)
        return true;
    return false;
}
