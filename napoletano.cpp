#include <iostream>
#include "napoletano.h"
#include <cstdlib>
#include <ctime>

Napoletano::Napoletano()
{
	dim = 0;
	c = nullptr;
}

Napoletano::~Napoletano()
{}

bool Napoletano::isMazzoEmpty(){
    if(getDim() > 0)
        return false;
    return true;
}

bool Napoletano::isMazzettoPrendibile(Carta cartaScelta, Napoletano& mazzoPuntiAvversario){
    if(mazzoPuntiAvversario.c[mazzoPuntiAvversario.dim - 1].getNumero() == cartaScelta.getNumero())
        return true;
    return false;
}

void Napoletano::inizializza() {
    delete[] c;

	dim = 40;
	c = new Carta[dim];
    int i;
    for(i = 0; i < dim; i++){
        c[i].setNumero(i % 10 + 1);
        switch(i % 10){
            case 0:
                c[i].setNome("asso");
                break;
            case 1:
                c[i].setNome("due");
                break;
            case 2:
                c[i].setNome("tre");
                break;
            case 3:
                c[i].setNome("quattro");
                break;
            case 4:
                c[i].setNome("cinque");
                break;
            case 5:
                c[i].setNome("sei");
                break;
            case 6:
                c[i].setNome("sette");
                break;
            case 7:
                c[i].setNome("fante");
                break;
            case 8:
                c[i].setNome("cavallo");
                break;
            case 9:
                c[i].setNome("re");
        }
    }
    for(i = 0; i < 10; i++)
        c[i].setSeme("coppe");
    for(i = 10; i < 20; i++)
        c[i].setSeme("denari");
    for(i = 20; i < 30; i++)
        c[i].setSeme("spade");
    for(i = 30; i < 40; i++)
        c[i].setSeme("bastoni");
}

void Napoletano::stampa() {
    for(int i = 0; i < dim; i++) {
        cout << endl << " " << i + 1;
        cout << c[i];

    }
}

void Napoletano::mescola() {
    srand(time(0));
    for(int i = 0; i < dim; i++) {
        int pos = rand() % dim;
        Carta tmp = c[i];
        c[i] = c[pos];
        c[pos] = tmp;
    }
}

void Napoletano::aggiungiCarta(Carta carta) {
    // creazione di un array di appoggio, per la creazione di uno nuovo
    // con la dimensione aumentata di 1 per permettere l'aggiunta della carta

    Carta *tmp = new Carta[dim];

    for(int i = 0; i < dim; i++)
        tmp[i] = c[i];

    delete[] c;
    c = new Carta[++dim];

    for(int i = 0; i < dim - 1; i++)
        c[i] = tmp[i];

    c[dim - 1] = carta;

    delete[] tmp;
    tmp = nullptr;
}

Carta Napoletano::estraiCarta() {
    // creazione di un array di appoggio, per la creazione di uno nuovo
    // con la dimensione decrementata di 1 per permettere l'estrazione della carta

    // estrazione della carta in cima al mazzo

    if(dim > 0) {
        Carta *tmp = new Carta[dim];

        for(int i = 0; i < dim - 1; i++)
            tmp[i] = c[i];

        Carta carta = c[dim - 1];

        delete[] c;
        c = new Carta[--dim];

        for(int i = 0; i < dim; i++)
            c[i] = tmp[i];

        return carta;
    } else {
        Carta carta;
        return carta;
    }
}

Carta Napoletano::estraiCarta(int pos){
    // creazione di un array di appoggio, per la creazione di uno nuovo
    // con la dimensione decrementata di 1 per permettere l'estrazione della carta

    // estrazione della carta data la posizione

    if(dim > 0) {
        Carta *tmp = new Carta[dim];
        Carta carta = c[pos - 1];

        for(int i = pos - 1; i < dim - 1; i++)
            c[i] = c[i + 1];

        for(int i = 0; i < dim - 1; i++)
            tmp[i] = c[i];

        delete[] c;
        c = new Carta[--dim];

        for(int i = 0; i < dim; i++)
            c[i] = tmp[i];

        return carta;
    } else {
        Carta carta;
        return carta;
    }
}

Carta Napoletano::getCartaTop() {
    if(getDim() == 0) {
        Carta carta;
        return carta;
    }

    return c[dim - 1];
}

void Napoletano::visualizzaCartaTop() {
    cout << endl << c[dim - 1];
}

void Napoletano::rubaMazzo(Napoletano& mazzo) {
    // creazione di un array di appoggio che ci permetterà poi, tramite
    // la deallocazione dell'array principale dalla memoria, di crearne uno nuovo
    // la cui dimensione vale quanto la somma delle dimensioni del mazzo
    // chiamante e quello passato come parametro

    Carta *tmp = new Carta[dim];

    for(int i = 0; i < dim; i++)
        tmp[i] = c[i];

    delete[] c;
    c = new Carta[dim + mazzo.dim + 1];

    int i;

    for(i = 0; i < dim; i++)
        c[i] = tmp[i];
    for(i = dim; i < dim + mazzo.dim; i++)
        c[i] = mazzo.c[i - dim];
    c[i] = mazzo.c[i - dim - 1];

    delete[] tmp;
    dim = dim + mazzo.dim;
    mazzo.dim = 0;
    stampa();
}

int Napoletano::isCartaPresenteInCampo(int num){
    int i = 0;

    while(i < dim && num != c[i].getNumero()){
        i++;
    }

    if(i < dim)
        return i + 1;
    return -1;
}

int Napoletano::getDim() {
    return dim;
}

Carta* Napoletano::getMazzo(){
    return c;
}
