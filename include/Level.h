#ifndef Level_h
#define Level_h
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <random>
#include "SnakeGame.h"

class Level{
    private:
        int linha_lab;      //<! Quantidade de linhas do labirinto
        int coluna_lab;     //<! Quantidade de colunas do labirinto
        int comida_linha;   //<! Coordenada da linha onde está a comida
        int comida_coluna;  //<! Coordenada da coluna onde está a comida
        int quant_comida;   //<! Quantidade de comidas a serem geradas por nível
    
    public:
        /*!
        * @brief Método que retorna a quantidade de colunas do labirinto
        * @return int quantidade de colunas
        **/
        int get_coluna_lab( void ) const;

        /*!
        * @brief Método que retorna a quantidade de linhas do labirinto
        * @return int quantidade de linhas
        **/
        int get_linha_lab( void ) const;

        /*!
        * @brief Método que retorna a coluna que a comida está
        * @return int coluna que a comida está
        **/
        int get_comida_coluna( void ) const;

        /*!
        * @brief Método que retorna a linha que a comida está
        * @return int linha que a comida está
        **/
        int get_comida_linha( void ) const;

        /*!
        * @brief Método que retorna a quantidade de comida
        * @return int quantidade de comida
        **/
        int get_quant_comida( void ) const;
        
        /*!
        * @brief Método que atribui o valor da comida coluna
        * @param coluna valor da comida coluna
        **/
        void set_comida_coluna( int coluna );

        /*!
        * @brief Método que atribui o valor da comida linha
        * @param linha valor da comida linha
        **/
        void set_comida_linha( int linha );
        
        /*!
        * @brief Método que atribui o valor da quant comida
        * @param comida valor da quant comida
        **/
        void set_quant_comida( int comida );

        /*!
        * @brief Método que atribui o valor da quantidade de colunas do labirinto
        * @param col valor da quantidade de colunas do labirinto
        **/
        void set_coluna_lab( int col );

        /*!
        * @brief Método que atribui o valor da quantidade de linhas do labirinto
        * @param lin valor da quantidade de linhas do labirinto
        **/
        void set_linha_lab( int lin );

        /*!
        * @brief Método que realiza o sorteio da posição aleatória da comida
        **/
        void random_comida();
};

#endif //Level_h