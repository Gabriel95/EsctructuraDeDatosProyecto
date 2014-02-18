#include "Carta.h"

Carta::Carta(int valor, string color, string signo, SDL_Surface* imagen, SDL_Surface* bak, bool cara)
{
this->valor = valor;
this->imagen = imagen;
this->cara =  cara;
this->bak = bak;
this->color = color;
this->signo = signo;
this->siguiente = NULL;
}

Carta::~Carta()
{
    //dtor
}
