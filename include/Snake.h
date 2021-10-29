#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <map>
#include <utility>
#include "SnakeGame.h"

class Snake{
    private:
        //int tamanhoCobra;     //<! Tamanho da cobra
        int cobra_linha;        //<! Coordenada da linha onde está a cabeça da cobra
        int cobra_coluna;       //<! Coordenada da coluna onde está a cabeça da cobra
        char cabeca;            //<! Símbolo que representa a cabeça da cobra
        int vidas = 5;          //<! Quantidade de vidas da cobra
        
    public:
        /*!
        * @brief Método que atribui a coordenada da linha onde está a cabeça da cobra a variável cobra_linha.
        * @param a A coordenada da linha onde está a cabeça da cobra.
        **/
        void set_cobra_linha( int a );

        /*!
        * @brief Método que atribui a coordenada da coluna onde está a cabeça da cobra a variável cobra_coluna.
        * @param b A coordenada da coluna onde está a cabeça da cobra.
        **/
        void set_cobra_coluna( int b );

        /*!
        * @brief Método que retorna a coordenada da linha onde está a cabeça da cobra no labirinto.
        * @return Coordenada da linha onde está a cabeça da cobra.
        **/
        int get_cobra_linha( void ) const;

        /*!
        * @brief Método que retorna a coordenada da coluna onde está a cabeça da cobra no labirinto.
        * @return Coordenada da coluna onde está a cabeça da cobra.
        **/
        int get_cobra_coluna( void ) const;

        /*!
        * @brief Método que atribui um símbolo que representa a cabeça da cobra a variável cabeça.
        * @param c A cabeça da cobra.
        **/
        void set_cabeca( char c);
        
        /*!
        * @brief Método que retorna o símbolo que representa a cabeça da cobra.
        * @return A cabeça da cobra.
        **/
        char get_cabeca( void ) const;

        /*!
        * @brief Método que retorna as vidas da cobra.
        * @return A quantidade de vidas da cobra.
        **/
        int get_vidas() const;

        /*!
        * @brief Método que atribui a quantidade de vidas da cobra a variável vidas.
        **/
        void set_vidas();
        
        /*!
        * @brief Pega o tamanho da cobra
        * @return o tamanho da cobra
        **/
        //int get_tamanhoCobra( void ) const;

        /*!
        * @brief Altera o tamanho da cobra
        * @param tam tamanho novo da cobra
        **/
        //void set_tamanhoCobra( void );
};

#endif //Snake_h