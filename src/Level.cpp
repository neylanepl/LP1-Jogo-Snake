#include "../include/Level.h"
#include <iostream>


int Level::get_comida_coluna( void ) const{
    return comida_coluna;
}

int Level::get_comida_linha( void ) const{
    return comida_linha;
}

int Level::get_quant_comida( void ) const{
    return quant_comida;
}

int Level::get_coluna_lab( void ) const{
    return coluna_lab;
}

int Level::get_linha_lab( void ) const{
    return linha_lab;
}

void Level::set_comida_coluna( int coluna ){
    comida_coluna = coluna;
}

void Level::set_comida_linha( int linha ){
    comida_linha = linha;
}

void Level::set_quant_comida( int comida ){
    quant_comida = comida;
}

void Level::set_coluna_lab( int col ){
    coluna_lab = col;
}

void Level::set_linha_lab( int lin ){
    linha_lab = lin;
}

void Level::random_comida(){
    std::random_device random;
    std::default_random_engine gerador(random()); // motores de números aleatórios
    std::uniform_int_distribution<int> distribuicao(0, linha_lab); // gera um número no intervalo 0 e o valor de linhas
    std::uniform_int_distribution<int> distribuicao2(0, coluna_lab); // gera um número no intervalo 0 e o valor de colunas
    comida_linha = distribuicao(gerador);
    comida_coluna = distribuicao2(gerador);
    
}