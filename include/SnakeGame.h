#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Level.h"
#include "Snake.h"
#include "Player.h"

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING,        //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER,      //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER,   //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        };

    private:
        std::vector<std::string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        int frameCount;                //<! contador de frames, usado apenas como exemplo
        std::string choice;            //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state;              //<! guarda o estado do jogo

        class Level *nivel;             //<! objeto que referencia classe level
        class Snake *cobra;             //<! objeto que referencia classe snake
        class Player *jogador;          //<! objeto que referencia classe player
        
        int fim = 0;            // para indicar que é ultimo nivel
        int quantNivel=0;       // quantidade de níveis
        int pontuacao=0;        // pontuação do jogo
    public:
        /**
        * @brief construtor padrão.
        * @param nivel objeto que referencia classe level
        * @param cobra objeto que referencia classe snake
        * @param jogador objeto que referencia classe player
        **/
        SnakeGame( class Level &nivel, class Snake &cobra, class Player &jogador );

        /**
        * @brief Método que procura a posição que está a cabeça da cobra no labirinto.
        * @param achouCobra Fleg para identificar se a cobra foi encontra ou não.
        */
        void find_cobra(int &achouCobra);

        /**
        * @brief Método que chama o initialize_game.
        * @param arquivo Arquivo texto de entrada que contém o labirinto.
        */
        void set_initialize_game( std::string arquivo);

        /**
        * @brief Método que faz a cobra "andar" e contola as fases que devem ser executadas.
        * @param contador Quantidade de rodadas validas.
        */
        void game(int &contador);

        /**
        * @brief Método que adiciona a comida de forma aleatória em alguma posição do labirinto.
        */
        void set_posicao_comida();
        
        /**
        * @brief Método que imprimi o cabeçalho inicial.
        */
        void cabecalho();

        /**
        * @brief Método que imprimi o cabeçalho em cada rodada.
        * @param contador Quantidade de comida coletada.
        */
        void rodada(int contador);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        /**
        * @brief Método que quebra a linha com as informações do labirinto e da quantidade de comida, e atribui os valores as suas devidas variáveis.
        * @param line String que contém a linha com as informações do labirinto e da quantidade de comida.
        **/
        void first_line( std::string line );

        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game(std::string arquivo);

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h