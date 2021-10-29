#ifndef Player_h
#define Player_h
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include "SnakeGame.h"
#include "Snake.h"

class Player{
    private:
        /*!
        * @brief Descreve os possíveis estados da cabeça da cobra.
        **/
        enum direction{
            NORTE       = 0 ,  // V
            SUL         = 1,   // ^
            ESQUERDA    = 2,   // >
            DIREITA     = 3    // <
        };
        
        /*!
        * @brief Coordenada da linha e da coluna que a cobra deve pecorrer para chegar na comida.
        **/
        struct posicaoCobra{
            int x;
            int y;
        };
        
        std::vector<std::string> mazeFantasma; //<! Labirinto auxiliar do maze.
        std::vector<posicaoCobra> caminho;     //<! Caminho que a cobra deve pecorrer para chegar na comida.
        std::vector<int> direcao;              //<! Direções que a cobra deve seguir para chegar na comida. 
        
    public:
        /*!
        * @brief Método que adiciona cada linha do labirinto ao vector mazeFantasma.
        * @param line String que contém uma linha do labirinto.
        **/
        void set_mazeFantasma( std::string line );

        /*!
        * @brief Método que defina e atribui qual a direção que a cabeça da cobra começa o jogo.
        * @param nivel objeto que referencia classe level
        * @param cobra objeto que referencia classe snake
        * @param labirinto O labirinto atual.
        **/
        void set_direcao_cabeca_cobra( class Level &nivel, class Snake &cobra, std::vector<std::string> &labirinto);
        
        /*!
        * @brief Método que dada a localização atual da cobra dentro do labirinto e a localização da comida, ele retorna true se ele encontrou à comida, ou false caso contrário.
        * @param lin Coordenada da linha onde a cobra é gerada.
        * @param col Coordenada da coluna onde a cobra é gerada.
        * @param limiteX Quantidade de linhas do labirinto.
        * @param limiteY Quantidade de colunas do labirinto.
        * @param labirinto O labirinto atual.
        * @return true se ele encontrou (e armazenou) uma sequência de direções que leva à comida, ou false caso contrário.
        **/
        bool find_solution(int lin, int col, int limiteX, int limiteY, std::vector<std::string> &labirinto);

        /*!
        * @brief Método que retorna uma posição para a cobra com base na sequência de caminhos encontrados e armazenados para chegar na comida.
        * @param indice Posição do vetor que deve ser retornada.
        * @return Um par(linha e coluna) que a cobra deve pecorrer para chegar na comida.
        **/
        std::pair<int,int> next_move(int indice);

        /*!
        * @brief Método que retorna uma direção para a cobra com base na sequência de direções encontrados e armazenados para chegar na comida.
        * @param indice Posição do vetor que deve ser retornada.
        * @return Um int que é associado a uma direção que a cobra deve seguir para chegar na comida.
        **/
        int get_direcao(int indice);
        
        /*!
        * @brief Método que atribui a última direção, que a cobra deve fazer para chegar na comida ,no vetor direção(é a mesma direção que foi seguida anteriormente).
        **/
        void ultima_posicao();

        /*!
        * @brief Método que retorna o número de elementos no vetor direcao.
        * @return O número de elementos no vetor direcao.
        **/
        int size_direcao();

        /*!
        * @brief Método que Apaga todos os elementos do vetor caminho e direcao.
        **/
        void clear_caminho();

        /*!
        * @brief Método que Apaga todos os elementos do vetor mazeFantasma.
        **/
        void clear_mazeFantasma();

};

#endif //Player_h