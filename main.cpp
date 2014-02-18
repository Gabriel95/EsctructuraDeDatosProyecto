#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <algorithm>    // std::random_shuffle
#include <list>
#include <cstdlib>
#include "Carta.h"
#include "Lista.h"
#include "Deck.h"
#include <iostream>
using namespace std;
//Screen attributes
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 690;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *up = NULL;
SDL_Surface *down = NULL;
SDL_Surface *left = NULL;
SDL_Surface *right = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Solitario Jesus Gabriel Paz 21241123 Heil Der Fuhrer!", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "background.png" );

    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 72 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( up );
    SDL_FreeSurface( down );
//    SDL_FreeSurface( left );
//    SDL_FreeSurface( right );

    //Close the font
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}
int randomizer (int i) {
     return std::rand()%i;
    }
int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;
    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    //Render the text
    up = TTF_RenderText_Solid( font, "Up", textColor );
    down = TTF_RenderText_Solid( font, "Down", textColor );
//    left = TTF_RenderText_Solid( font, "Left", textColor );
//    right = TTF_RenderText_Solid( font, "Right", textColor );
    SDL_Surface *bak = load_image("back.png");
    SDL_Surface *bak2 = load_image("back2.png");
std::vector<Carta*>baraja;
std::srand ( unsigned ( std::time(0) ) );
baraja.push_back(new Carta(1,"NEGRO","TREBOLES",load_image("assests/c01.png"),bak,false));
baraja.push_back(new Carta(2,"NEGRO","TREBOLES",load_image("assests/c02.png"),bak,false));
baraja.push_back(new Carta(3,"NEGRO","TREBOLES",load_image("assests/c03.png"),bak,false));
baraja.push_back(new Carta(4,"NEGRO","TREBOLES",load_image("assests/c04.png"),bak,false));
baraja.push_back(new Carta(5,"NEGRO","TREBOLES",load_image("assests/c05.png"),bak,false));
baraja.push_back(new Carta(6,"NEGRO","TREBOLES",load_image("assests/c06.png"),bak,false));
baraja.push_back(new Carta(7,"NEGRO","TREBOLES",load_image("assests/c07.png"),bak,false));
baraja.push_back(new Carta(8,"NEGRO","TREBOLES",load_image("assests/c08.png"),bak,false));
baraja.push_back(new Carta(9,"NEGRO","TREBOLES",load_image("assests/c09.png"),bak,false));
baraja.push_back(new Carta(10,"NEGRO","TREBOLES",load_image("assests/c10.png"),bak,false));
baraja.push_back(new Carta(11,"NEGRO","TREBOLES",load_image("assests/c11.png"),bak,false));
baraja.push_back(new Carta(12,"NEGRO","TREBOLES",load_image("assests/c12.png"),bak,false));
baraja.push_back(new Carta(13,"NEGRO","TREBOLES",load_image("assests/c13.png"),bak,false));
baraja.push_back(new Carta(1,"ROJO","DIAMANTES",load_image("assests/d01.png"),bak,false));
baraja.push_back(new Carta(2,"ROJO","DIAMANTES",load_image("assests/d02.png"),bak,false));
baraja.push_back(new Carta(3,"ROJO","DIAMANTES",load_image("assests/d03.png"),bak,false));
baraja.push_back(new Carta(4,"ROJO","DIAMANTES",load_image("assests/d04.png"),bak,false));
baraja.push_back(new Carta(5,"ROJO","DIAMANTES",load_image("assests/d05.png"),bak,false));
baraja.push_back(new Carta(6,"ROJO","DIAMANTES",load_image("assests/d06.png"),bak,false));
baraja.push_back(new Carta(7,"ROJO","DIAMANTES",load_image("assests/d07.png"),bak,false));
baraja.push_back(new Carta(8,"ROJO","DIAMANTES",load_image("assests/d08.png"),bak,false));
baraja.push_back(new Carta(9,"ROJO","DIAMANTES",load_image("assests/d09.png"),bak,false));
baraja.push_back(new Carta(10,"ROJO","DIAMANTES",load_image("assests/d10.png"),bak,false));
baraja.push_back(new Carta(11,"ROJO","DIAMANTES",load_image("assests/d11.png"),bak,false));
baraja.push_back(new Carta(12,"ROJO","DIAMANTES",load_image("assests/d12.png"),bak,false));
baraja.push_back(new Carta(13,"ROJO","DIAMANTES",load_image("assests/d13.png"),bak,false));
baraja.push_back(new Carta(1,"ROJO","CORAZONES",load_image("assests/h01.png"),bak,false));
baraja.push_back(new Carta(2,"ROJO","CORAZONES",load_image("assests/h02.png"),bak,false));
baraja.push_back(new Carta(3,"ROJO","CORAZONES",load_image("assests/h03.png"),bak,false));
baraja.push_back(new Carta(4,"ROJO","CORAZONES",load_image("assests/h04.png"),bak,false));
baraja.push_back(new Carta(5,"ROJO","CORAZONES",load_image("assests/h05.png"),bak,false));
baraja.push_back(new Carta(6,"ROJO","CORAZONES",load_image("assests/h06.png"),bak,false));
baraja.push_back(new Carta(7,"ROJO","CORAZONES",load_image("assests/h07.png"),bak,false));
baraja.push_back(new Carta(8,"ROJO","CORAZONES",load_image("assests/h08.png"),bak,false));
baraja.push_back(new Carta(9,"ROJO","CORAZONES",load_image("assests/h09.png"),bak,false));
baraja.push_back(new Carta(10,"ROJO","CORAZONES",load_image("assests/h10.png"),bak,false));
baraja.push_back(new Carta(11,"ROJO","CORAZONES",load_image("assests/h11.png"),bak,false));
baraja.push_back(new Carta(12,"ROJO","CORAZONES",load_image("assests/h12.png"),bak,false));
baraja.push_back(new Carta(13,"ROJO","CORAZONES",load_image("assests/h13.png"),bak,false));
baraja.push_back(new Carta(1,"NEGRO","ESPADAS",load_image("assests/s01.png"),bak,false));
baraja.push_back(new Carta(2,"NEGRO","ESPADAS",load_image("assests/s02.png"),bak,false));
baraja.push_back(new Carta(3,"NEGRO","ESPADAS",load_image("assests/s03.png"),bak,false));
baraja.push_back(new Carta(4,"NEGRO","ESPADAS",load_image("assests/s04.png"),bak,false));
baraja.push_back(new Carta(5,"NEGRO","ESPADAS",load_image("assests/s05.png"),bak,false));
baraja.push_back(new Carta(6,"NEGRO","ESPADAS",load_image("assests/s06.png"),bak,false));
baraja.push_back(new Carta(7,"NEGRO","ESPADAS",load_image("assests/s07.png"),bak,false));
baraja.push_back(new Carta(8,"NEGRO","ESPADAS",load_image("assests/s08.png"),bak,false));
baraja.push_back(new Carta(9,"NEGRO","ESPADAS",load_image("assests/s09.png"),bak,false));
baraja.push_back(new Carta(10,"NEGRO","ESPADAS",load_image("assests/s10.png"),bak,false));
baraja.push_back(new Carta(11,"NEGRO","ESPADAS",load_image("assests/s11.png"),bak,false));
baraja.push_back(new Carta(12,"NEGRO","ESPADAS",load_image("assests/s12.png"),bak,false));
baraja.push_back(new Carta(13,"NEGRO","ESPADAS",load_image("assests/s13.png"),bak,false));
std::random_shuffle ( baraja.begin(), baraja.end(),randomizer );
Lista *list1 = new Lista();
Lista *list2 = new Lista();
Lista *list3 = new Lista();
Lista *list4 = new Lista();
Lista *list5 = new Lista();
Lista *list6 = new Lista();
Lista *list7 = new Lista();
Deck *deck1 = new Deck(20,20);
Deck *deck2 = new Deck(160,20);
list1->agregarCarta(baraja[0]);
for(int i = 1; i<3; i++)
list2->agregarCarta(baraja[i]);
for(int i = 3; i<6; i++)
list3->agregarCarta(baraja[i]);
for(int i = 6; i<10; i++)
list4->agregarCarta(baraja[i]);
for(int i = 10; i<15; i++)
list5->agregarCarta(baraja[i]);
for(int i = 15; i<21; i++)
list6->agregarCarta(baraja[i]);
for(int i = 21; i<28; i++)
list7->agregarCarta(baraja[i]);
for(int i = 28; i<baraja.size(); i++)
deck1->agregarCartas(baraja[i]);
bool pressed=false;
bool up=false;
    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
         switch(event.button.button){
                case SDL_BUTTON_LEFT:
                    if(up)
                        pressed=true;
                    up=false;
                break;

        default: break;
         }
        }

        if(event.type == SDL_MOUSEBUTTONUP){
         switch(event.button.button){
                case SDL_BUTTON_LEFT:
                up=true;
                break;

        default: break;
         }
        }

        if(pressed)
        {
                if(event.button.x>=20&&event.button.x<=113&&event.button.y>=20&&event.button.y<=148){
                if(deck1->contador == 0)
                deck2->vaciar(deck1);
                else
                deck1->enviar(deck2);
                }
                pressed=false;
                up=false;
        }
            /*if(event.type == SDL_MOUSEBUTTONDOWN){
                if(event.button.button == SDL_BUTTON_LEFT){

                if(event.button.x>=20&&event.button.x<=113&&event.button.y>=20&&event.button.y<=148){
                if(deck1->contador == 0)
                deck2->vaciar(deck1);
                else
                deck1->enviar(deck2);
                }
                }
            }*/
        //Apply the background
        apply_surface( 0,0, background, screen );
       // apply_surface(20,20,bak,screen);
       // apply_surface(160,20,bak,screen);
        apply_surface(440,20,bak,screen);
        apply_surface(580,20,bak,screen);
        apply_surface(720,20,bak,screen);
        apply_surface(860,20,bak,screen);
        list1->imprimirLista(screen,20);
        list2->imprimirLista(screen,160);
        list3->imprimirLista(screen,300);
        list4->imprimirLista(screen,440);
        list5->imprimirLista(screen,580);
        list6->imprimirLista(screen,720);
        list7->imprimirLista(screen,860);
        deck1->imprimir(screen);
        deck2->imprimir(screen);


            //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    //Clean up
    clean_up();

    return 0;
}
