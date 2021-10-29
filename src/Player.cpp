#include "../include/Player.h"
#include <iostream>

void Player::set_mazeFantasma( std::string line ){
    mazeFantasma.push_back(line);
}

void Player::set_direcao_cabeca_cobra( class Level &nivel, class Snake &cobra, std::vector<std::string> &labirinto){
    if(nivel.get_comida_linha() != cobra.get_cobra_linha()){ // linhas diferentes
        if(nivel.get_comida_linha() > cobra.get_cobra_linha() && labirinto[cobra.get_cobra_linha() + 1][cobra.get_cobra_coluna()] != '#'){ // SUL e a proxima posição da linha é vazia 
            cobra.set_cabeca('^');
        }
        else if(nivel.get_comida_linha() < cobra.get_cobra_linha() && labirinto[cobra.get_cobra_linha() - 1][cobra.get_cobra_coluna()] != '#'){ // NORTE e a posição anterior da linha é vazia
            cobra.set_cabeca('v');
        }
        else if(nivel.get_comida_coluna() > cobra.get_cobra_coluna() && labirinto[cobra.get_cobra_linha()][cobra.get_cobra_coluna()+1] != '#'){ // LESTE e a proxima posição da coluna é vazia 
            
            cobra.set_cabeca('<');
        }
        else if(cobra.get_cobra_linha() != 0 && cobra.get_cobra_coluna() != 0){//OESTE e a posição anterior da coluna é vazia
            cobra.set_cabeca('>');
        }
    }
    else{ // linha iguais
        if(nivel.get_comida_coluna() > cobra.get_cobra_coluna() && labirinto[cobra.get_cobra_linha()][cobra.get_cobra_coluna()+1] != '#'){ // LESTE e a proxima posição da coluna é vazia 
            cobra.set_cabeca('<');
        }
        else if(nivel.get_comida_coluna() > cobra.get_cobra_coluna() && labirinto[cobra.get_cobra_linha()][cobra.get_cobra_coluna()-1] != '#'){ // OESTE e a posição anterior da coluna é vazia
            cobra.set_cabeca('>');
        }
        else if(labirinto[cobra.get_cobra_linha() + 1][cobra.get_cobra_coluna()] != '#'){ // SUL e a proxima posição da linha é vazia 
            cobra.set_cabeca('^');
        }
        else if(cobra.get_cobra_linha() != 0 && cobra.get_cobra_coluna() != 0){ // NORTE e a posição anterior da linha é vazia
            cobra.set_cabeca('v');

        }
    }
}


bool Player::find_solution(int lin, int col, int limiteX, int limiteY, std::vector<std::string> &labirinto){
    bool achou;

    if( labirinto[lin][col] == 'F'){  // Caso base: se achou a comida.
        caminho.push_back(posicaoCobra{lin, col});
        return true;
    }

    // Além de testar as bordas e se o movimento é possível, testa também se ele ainda não passou pela comida.
    if(lin-1 >=0 && (labirinto[lin-1][col] == ' ' || labirinto[lin-1][col] == 'F') && (mazeFantasma[lin-1][col] == ' ')){ // Testa se dá para andar para cima. A casa tem que ser vazia ou a comida.
        mazeFantasma[lin][col] = '#'; // Marca que passou pela posição.
        achou = find_solution(lin-1, col, limiteX, limiteY, labirinto);
        mazeFantasma[lin][col] = ' '; // Na volta, desmarca para testar outros caminhos.
        
        // Se achou caminho
        if(achou){
            direcao.push_back(NORTE);
            caminho.push_back(posicaoCobra{lin, col});
            return true;
        } 
    }

    if(lin+1 <limiteX && (labirinto[lin+1][col] == ' ' || labirinto[lin+1][col] == 'F') && (mazeFantasma[lin+1][col] == ' ')){ // Testa se dá para andar para baixo.
        mazeFantasma[lin][col] = '#'; // Marca que passou pela posição.
        achou = find_solution(lin+1, col, limiteX, limiteY, labirinto);
        mazeFantasma[lin][col] = ' '; // Na volta, desmarca para testar outros caminhos.

        //Se achou caminho
        if(achou){
            direcao.push_back(SUL);
            caminho.push_back(posicaoCobra{lin, col});
            return true;
        }
    }
    
    if(col-1 >=0 && (labirinto[lin][col-1] == ' ' || labirinto[lin][col-1] == 'F') && (mazeFantasma[lin][col-1] == ' ')){ // Testa se dá para andar para a esquerda.
        mazeFantasma[lin][col] = '#'; // Marca que passou pela posição.
        achou = find_solution(lin, col-1, limiteX, limiteY, labirinto);
        mazeFantasma[lin][col] = ' '; // Na volta, desmarca para testar outros caminhos.
        
        // Se achou caminho
        if(achou){
            direcao.push_back(ESQUERDA);
            caminho.push_back(posicaoCobra{lin, col});
            return true;
        }
    }

    if(col+1 < limiteY && (labirinto[lin][col+1] == ' ' || labirinto[lin][col+1] == 'F') && (mazeFantasma[lin][col+1] == ' ')){ // Testa se dá para andar para direita.
        mazeFantasma[lin][col] = '#'; // Marca que passou pela posição.
        achou = find_solution(lin, col+1, limiteX, limiteY, labirinto);
        mazeFantasma[lin][col] = ' '; // Na volta, desmarca para testar outros caminhos.
        
        //Se achou caminho
        if(achou){
            direcao.push_back(DIREITA);
            caminho.push_back(posicaoCobra{lin, col});
            return true;
        }
    } 

    return false;   //Não encontrou solução e pecorreu todo labirinto
}

void Player::ultima_posicao(){
    direcao.push_back(direcao[direcao.size()-1]);
}

int Player::size_direcao(){
    return direcao.size();
}

std::pair<int,int> Player::next_move(int indice){
    return {caminho[indice].x, caminho[indice].y};
}
 
int Player::get_direcao(int indice){
    return direcao[indice];
}

void Player::clear_caminho(){
    caminho.clear();
    direcao.clear();
}

void Player::clear_mazeFantasma(){
    mazeFantasma.clear();
}