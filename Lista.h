#ifndef LISTA_H
#define LISTA_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Carta.h"
class Lista
{
    public:
        Carta* inicio;
        bool validacion(Carta* nueva);
        void agregarCartas(Carta*nueva);
        void agregarCarta(Carta*nueva);
        void imprimirLista(SDL_Surface* screen, int x);

        Lista();
        virtual ~Lista();
    protected:
    private:
};

#endif // LISTA_H
