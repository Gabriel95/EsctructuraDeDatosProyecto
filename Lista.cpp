#include "Lista.h"
#include <iostream>
using namespace std;
Lista::Lista()
{
this->inicio = NULL;
}
void Lista::agregarCarta(Carta* nueva){
if(inicio==NULL)
{
inicio = nueva;
}else{
Carta* temp = inicio;
while(temp->siguiente!=NULL)
temp = temp->siguiente;
temp->siguiente = nueva;
}
}
bool Lista::validacion(Carta *nueva){

}
void Lista::agregarCartas(Carta* nueva){
Carta* temp = inicio;
while(temp->siguiente!=NULL)
temp = temp->siguiente;
temp->siguiente = nueva;
}
void Lista::imprimirLista(SDL_Surface* screen, int x){
Carta* temp = inicio;
int contador = 160;
while(temp!=NULL){
    SDL_Rect offset;
    offset.x = x;
    offset.y = contador;
    if(temp->siguiente==NULL||temp->cara==true){
     SDL_BlitSurface( temp->imagen, NULL, screen, &offset );
    temp->cara = true;
    }
    else
    SDL_BlitSurface( temp->bak, NULL, screen, &offset );
    temp = temp->siguiente;
    contador = contador + 20;

}

}
Lista::~Lista()
{
    //dtor
}
