#include "Deck.h"

Deck::Deck(int x, int y)
{
this->inicio=NULL;
this->x = x;
this->y = y;
this->contador = 0;
}
void Deck::agregarCartas(Carta* nueva){
if(inicio==NULL)
{
inicio = nueva;
contador++;
}else{
Carta* temp = inicio;
while(temp->siguiente!=NULL)
temp = temp->siguiente;
temp->siguiente = nueva;
contador++;
}
}
void Deck::imprimir(SDL_Surface* screen){
if(inicio!=NULL){
Carta* temp = inicio;
while(temp!=NULL){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    if(temp->cara==true){
    SDL_BlitSurface( temp->imagen, NULL, screen, &offset );
    }
    else
    SDL_BlitSurface( temp->bak, NULL, screen, &offset );
    temp = temp->siguiente;
}
}
}
void Deck::eleminar(){
Carta* temp = inicio;
if(contador == 2){
inicio->siguiente = NULL;
contador--;
}else if(contador == 1){
inicio = NULL;
contador--;
}else{
while(temp->siguiente->siguiente!=NULL)
temp = temp ->siguiente;
temp ->siguiente = NULL;
contador--;
}
}
Carta* Deck::recuperar(){
Carta* temp = inicio;
while(temp->siguiente!=NULL)
temp = temp->siguiente;
return temp;
}
void Deck::enviar(Deck* destination){
Carta *temp = recuperar();
if(temp->cara==true)
    temp->cara = false;
else if(temp->cara==false)
    temp->cara = true;
destination->agregarCartas(temp);
eleminar();
}
void Deck::vaciar(Deck* destination){
int c = contador;
for(int i = 0; i < c; i++){
enviar(destination);
}
}

Deck::~Deck()
{
    //dtor
}
