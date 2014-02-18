#ifndef CARTA_H
#define CARTA_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <iostream>
using namespace std;
class Carta
{
    public:
        int x, y;
        int valor;
        bool cara;
        string color;
        string signo;
        Carta* siguiente;
        SDL_Surface* imagen;
        SDL_Surface* bak;
        Carta(int valor, string color, string signo, SDL_Surface* imagen, SDL_Surface* bak, bool cara);
        virtual ~Carta();
    protected:
    private:
};

#endif // CARTA_H
