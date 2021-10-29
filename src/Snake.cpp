#include "../include/Snake.h"

void Snake::set_cobra_linha( int a ){
    cobra_linha = a;
}

void Snake::set_cobra_coluna( int b ){
    cobra_coluna = b;
}

int Snake::get_cobra_linha( void ) const{
    return cobra_linha;
}

int Snake::get_cobra_coluna( void ) const{
    return cobra_coluna;
}

void Snake::set_cabeca( char c ){
    cabeca = c;
}
char Snake::get_cabeca( void ) const{
    return cabeca;
}

int Snake::get_vidas() const{
    return vidas;
}

void Snake::set_vidas(){
    vidas--;
}

/* int Snake::get_tamanhoCobra( void ) const{
    return tamanhoCobra;
}

void Snake::set_tamanhoCobra( void ){
    tamanhoCobra +=1;
}*/
