# Progetto Rubamazzo | Analisi tecnica

## 1. Obiettivo
Rubamazzo è un gioco di carte italiano a due giocatori e l’obiettivo è quello di acquisire il maggior numero di carte dal tavolo, o prendendo una carta dal tavolo uguale a una nella propria mano, oppure rubando il mazzo all’avversario nel caso che la carta in cima al suo mazzetto dei punti e una carta nella propria mano, siano uguali.
Il giocatore che alla fine del gioco ha più carte nel proprio mazzetto vince.

### 1.1 Regole 
Giocatori: 2
Scopo: Lo scopo del gioco e' raccogliere più carte possibili nel proprio mazzetto, rubando anche dal mazzetto avversario oltre che prendendo le carte in campo.
Svolgimento del gioco:
Il mazziere colloca 4 carte al centro del campo e ne dà 3 ad ogni giocatore.
I giocatori, ad uno ad uno, iniziano a scegliere una carta a testa. 
Se il numero della carta scelta è uguale a quello di una carta in campo, allora il giocatore aggiunge al proprio mazzetto dei punti la carta scelta e quella del mazzo centrale con lo stesso valore.
Un giocatore può altrimenti, “rubare” il mazzetto all’avversario, e nel caso avvenisse, allora esso viene posto, quindi, in cima al proprio mazzetto.
Se non è possibile nessuna delle due operazioni, allora la carta viene collocata nel mazzo centrale insieme alle altre.
Termine del gioco: Quando i giocatori rimangono senza carte in mano, e non si ha più la disponibilità di pescare altre carte dal mazzo, siccome è vuoto, si contano le carte del proprio mazzetto e chi ne ha un maggior numero vince.

## 2. Analisi architetturale
Nell’ambito del sottosistema Rubamazzo, sono state realizzate le classi:
Carta
MazzoDiCarte
Napoletano

### 2.1. Carta
In questo paragrafo sono presenti i metodi e gli attributi necessari all’implementazione di tale classe.

Attributi privati: 
- seme: stringa contenente il seme della carta (denari, bastoni, spade e coppe);
- nome: stringa contenente il nome della carta (asso, 2 - 7, fante, cavallo e re);
- numero: intero contenente il numero della carta (1 - 10).

Metodi pubblici:
- Carta(): costruttore di default;
- Carta(string seed, string name, int number): costruttore orientato ai parametri;
- int getNumero(): restituisce il numero della carta;
- void setSeme(string seed): modifica il seme della carta con la stringa passata;
- void setNome(string name): modifica il nome della carta con la stringa passata;
- Progetto Rubamazzo - Analisi tecnica			Foroni Gabriele - Sassi Thomas
- void setNumero(int number): modifica il numero della carta con l’intero passato;
- friend istream& operator>>(istream& inp, Carta& c): metodo amico della classe che prende in input una carta tramite l’overloading dell’operatore >>;
- friend ostream& operator<<(ostream& out, const Carta& c): metodo amico della classe che stampa una carta in output tramite l’overloading dell’operatore <<;
- bool operator==(Carta c): operatore che confronta due carte e verifica la loro uguaglianza tramite l’overloading dell’operatore binario ==.

### 2.2. MazzoDiCarte
In questo paragrafo sono presenti i metodi e gli attributi necessari all’implementazione di tale classe.
Questa è una classe astratta dato che contiene un metodo virtuale puro.
Gli attributi sono protetti per facilitare l’uso degli attributi nella sua classe figlia Napoletano.

Attributi protetti: 
- c: array di Carte;
- dim: intero che contiene la lunghezza relativa all’array di Carte c.

Metodi pubblici:
- MazzoDiCarte(): costruttore di default;
- virtual ~MazzoDiCarte(): distruttore;
- virtual void inizializza() = 0: metodo puro che inizializza il mazzo di 40 carte (non viene implementato in questa classe, ma nella sua classe figlia Napoletano).

### 2.3. Napoletano
In questo paragrafo sono presenti i metodi e gli attributi necessari all’implementazione di tale classe.

Metodi pubblici: 
- Napoletano(): costruttore di default;
- ~Napoletano(): distruttore;
- int getDim(): restituisce la dimensione dell’array di Carte c della classe padre MazzoDiCarte;
- Carta* getMazzo(): restituisce il puntatore alla prima Carta del mazzo che ci permette di utilizzare tutto l’array;
- void inizializza(): inizializza il mazzo di 40 carte con il seme, il nome e il numero di ogni Carta;
- void stampa(): stampa il mazzo di carte Napoletano;
- void mescola(): simula il mescolamento del mazzo di carte Napoletano;
- void aggiungiCarta(Carta carta): aggiunge al mazzo Napoletano una Carta passata come parametro;
- Carta estraiCarta(): estrae e restituisce la Carta in cima all mazzo;
- Carta estraiCarta(int pos): estrae e restituisce la Carta con posizione passata come parametro del mazzo;
- Progetto Rubamazzo - Analisi tecnica			Foroni Gabriele - Sassi Thomas
- void visualizzaCartaTop(): stampa la Carta in cima al mazzo;
- Carta getCartaTop(): restituisce la Carta in cima al mazzo;
- void rubaMazzo(Napoletano& mazzo): aggiunge il mazzo passato come parametro all’istanza chiamante;
- int isCartaPresenteInCampo(int num): verifica se la Carta di posizione passata come parametro sia presente in campo restituendo un intero che rappresenta la posizione della Carta sul campo, restituisce -1 se non è presente;
- bool isMazzoEmpty(): verifica se il mazzo è vuoto;
- bool isMazzettoPrendibile(Carta cartaScelta, Napoletano& mazzoPuntiAvversario): verifica se il numero della carta in cima al mazzo dei punti dell’avversario è uguale a quello della carta che viene scelta da usare, se sono uguali è possibile rubare il mazzo;
- void turnoGiocatore(Napoletano& mazzo, Napoletano& mazzoPunti, Napoletano& mazzoPuntiAvversario): metodo che gestisce il turno di un giocatore;
- void turnoComputer(Napoletano& mano, Napoletano& mazzoPunti, Napoletano& mazzoPuntiAvversario): metodo che gestisce il turno del computer.

Alla classe Napoletano è stato collegato inoltre un file a parte (turni.cpp) contenente le implementazioni dei due metodi utili a gestire i vari turni durante lo svolgimento del gioco:
turnoGiocatore;
turnoComputer.
