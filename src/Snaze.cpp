#include <iostream>
#include "../include/SnakeGame.h"
#include "../include/Level.h"
#include "../include/Snake.h"
#include "../include/Player.h"

using namespace std;

int main(int argc, char *argv[]){ //argc e *argv para receber o arquivo
    Level nivel;
    Snake cobra;
    Player jogador;

    SnakeGame game(nivel, cobra, jogador); // Passa para o construtor as classes necessária no escopo
    
    game.set_initialize_game( argv[argc-1] ); // Inicializa o jogo

    return 0;
}