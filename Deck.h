#ifndef DECK_H
#define DECK_H
#include "Carta.h"
#include <iostream>
using namespace std;
class Deck
{
    public:
        Carta* inicio;
        int contador;
        int x, y;
        Deck(int x, int y);
        void agregarCartas(Carta *nueva);
        void imprimir(SDL_Surface* screen);
        void enviar(Deck* destination);
        void eleminar();
        Carta* recuperar();
        void vaciar(Deck* destination);
        virtual ~Deck();
    protected:
    private:
};

#endif // DECK_H
