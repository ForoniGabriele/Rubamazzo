#ifndef MAZZODICARTE_H
#define MAZZODICARTE_H

#include "carta.h"

class MazzoDiCarte {
	protected:
		Carta *c; // array di carte
		int dim; // dimensione relativa all'array di carte

	public:
		MazzoDiCarte();
		virtual	~MazzoDiCarte();
		// metodo virtuale puro che viene poi implementato nella classe Napoletano
		virtual	void inizializza() = 0;
};

#endif // MAZZODICARTE_H
