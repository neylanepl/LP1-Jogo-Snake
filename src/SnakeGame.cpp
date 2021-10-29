#include "../include/SnakeGame.h"

#include <iostream>
#include <fstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

#include <sstream>
#include <iterator>

using namespace std;
SnakeGame::SnakeGame( class Level &nivel, class Snake &cobra, class Player &jogador ){
    choice = "";
    frameCount = 0;
    this->nivel = &nivel;
    this->cobra = &cobra;
    this->jogador = &jogador;
}

void SnakeGame::set_initialize_game( std::string arquivo ){
    initialize_game(arquivo); // recebe o nome do arquivo e passa para o método inicialize game
}

void SnakeGame::first_line( std::string line){
    std::vector< std::string > numeros{}; // vector que vai receber os 3 valores lidos de linha, coluna e quantidade de comida

    std::istringstream iss(line); // objeto string que permite a leitura como o cin
    
    copy(std::istream_iterator<string>(iss),
         std::istream_iterator<string>(), //' ' é o delimitador padrão para istream_iterator
         std::back_inserter(numeros)); // insere a string separada no vector

    nivel->set_linha_lab(std::stoi(numeros[0]) -1);  // transforma para inteiro
    nivel->set_coluna_lab(std::stoi(numeros[1]) -1); // transforma para inteiro
    nivel->set_quant_comida(std::stoi(numeros[2]));

    if((nivel->get_linha_lab() <= 0) ||  (nivel->get_coluna_lab() <= 0) || (nivel->get_quant_comida() <= 0)){ // Tratamento de erros para linhas, colunas ou comidas menores ou iguais a zero
        cout << "ERRO: Valores de linhas, colunas ou comidas devem ser maiores que 0!\n";
        this_thread::sleep_for(chrono::milliseconds(1900));
        state = GAME_OVER;
        game_over();
    }
    if((nivel->get_linha_lab() > 100) ||  (nivel->get_coluna_lab() > 100)){ // Linhas ou colunas maiores que 100
        cout << "ERRO: Valores de linhas ou colunas devem ser menores ou iguais a 100!\n";
        this_thread::sleep_for(chrono::milliseconds(2900));
        state = GAME_OVER;
        game_over();
    }
}

void SnakeGame::find_cobra( int &achouCobra ){
    // Acha o '*' dentro do labirinto e guarda a posição inicial da cobra
    for(int a = 0; a < nivel->get_linha_lab(); a++){
        for(int b = 0; b < nivel->get_coluna_lab(); b++){
            if(maze[a][b] == '*'){
                cobra->set_cobra_linha(a);  // Coloca na variável a linha da cabeça da cobra
                cobra->set_cobra_coluna(b); // Coloca na variável a coluna da cabeça da cobra
                achouCobra = 1;
            }
        }
    }

    if(state != GAME_OVER){ // Caso não tenha dado erro na entrada dos números
        state = RUNNING;
    }
}

void SnakeGame::initialize_game( std::string arquivo ){
    //carrega o nivel ou os níveis
    ifstream levelFile(arquivo);
    int lineCount = 0;      // conta a quantidade de linhas lidas
    int achouCobra = 0;     // sinaliza se tem a cobra no labirinto
    string line;            // string que vai receber a leitura de cada linha

    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            if(lineCount == 0){ // pega a primeira linha
                first_line(line);
                if(state == GAME_OVER){
                    break;
                }
            }
            if(lineCount > 0 && lineCount <= nivel->get_linha_lab() +1 ){ // pega o labirinto
                maze.push_back(line);           // coloca a linha no labirinto
                jogador->set_mazeFantasma(line);// coloca a linha no labirinto fantasma

                if(lineCount == nivel->get_linha_lab() + 1){ // quando tiver acabado de ler todas as linhas do labirinto 
                    find_cobra(achouCobra);     // função que verifica se a cobra existe no nível 
                    if(achouCobra){             // caso tenha cobra
                        state = RUNNING;
                        if(choice != "n"){                  // caso o usuário deseje continuar
                            quantNivel++;
                            loop();                         // roda a execução do jogo em fases
                            jogador->clear_caminho();       // libera o vector caminho e direcao
                            jogador->clear_mazeFantasma();  // libera o vector mazeFantasma
                            maze.clear();                   // libera o vector maze
                            achouCobra=0;
                            cout<<"O nível terminou!"<<endl;
                            this_thread::sleep_for(chrono::milliseconds(1900));
                            cout<<"Quer continuar?"<<endl;
                            state= WAITING_USER;
                            process_actions();
                            if(choice == "n"){
                                break;
                            }
                        }
                    }
                    else{
                        cout<<"                   NÃO EXISTE COBRA NO LABIRINTO\n";
                        cout<<"                      ---> NÍVEL ENCERRADO <---\n";
                        cout<<"_____________________________________________________________________\n";
                        this_thread::sleep_for(chrono::milliseconds(1900));
                        jogador->clear_caminho();
                        jogador->clear_mazeFantasma();
                        maze.clear();
                    }
                    lineCount = -1;
                }
            }
            lineCount++;
        }
        fim = 1; // quando acabar a leitura de todos os níveis o jogo acaba e encerra a execução
        state = GAME_OVER;
        render();
    }
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(frameCount>0 && (frameCount+1)%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                cout<<"O jogo terminou!"<<endl;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            if(fim == 1){
                cout<<"O jogo terminou!"<<endl;
            }
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::game(int &contador){
    if(choice == "n"){ // Se o jogador não quiser mais continuar o jogo
        state = GAME_OVER;
        fim=1;
        game_over();
    }
    else if(cobra->get_vidas() == 0){ // Se as vidas da cobra tiverem acabado
        std::cout<<"AS VIDAS ACABARAM, QUE PENA!! GAME OVER BABY\n";
        wait(1900);
        clearScreen();
        fim=1;
        state = GAME_OVER;
    }
    else if(contador < nivel->get_quant_comida()){ // Se a quantidade de rodadas validas ainda for menor que a quantidade de comidas que devem ser geradas
        set_posicao_comida();  // Atribui a posição da comida aleatoriamente
        maze[nivel->get_comida_linha()][nivel->get_comida_coluna()] = 'F'; // Coloca a comida no mapa
        jogador->set_direcao_cabeca_cobra(*nivel, *cobra, maze);                 // Vê qual a direção da boca da cobra
        maze[cobra->get_cobra_linha()][cobra->get_cobra_coluna()] = cobra->get_cabeca(); // Atribui no lugar do asterisco a direção da boca da cobra

        if(!jogador->find_solution( cobra->get_cobra_linha(),  cobra->get_cobra_coluna(),  nivel->get_linha_lab(), nivel->get_coluna_lab(), maze)){  // Caso a cobra não ache caminho válido até a comida
            printf("Não há caminho valido...Você perdeu uma vida!\n");
            rodada(contador);
            for(auto line : maze){
                cout<<line<<endl;
            }
            wait(2500);
            clearScreen();
            cobra->set_vidas();
        }
        else{  // Caso a cobra ache caminho válido até a comida
            int linha = cobra->get_cobra_linha();       // Armazena a linha atual da cobra
            int coluna = cobra->get_cobra_coluna();     // Armazena a coluna atual da cobra
            jogador->ultima_posicao();                  // Coloca no vector de direções o último passo para a cabeça ficar em cima da comida

            for(int i = jogador->size_direcao() -1 ; i >= 0; i--){
                maze[linha][coluna] = ' ';  // Atribui na posição atual da cobra o espaço

                switch(jogador->get_direcao(i)){
                    case 0: maze[jogador->next_move(i).first][jogador->next_move(i).second] = 'v'; break; // Norte
                    case 1: maze[jogador->next_move(i).first][jogador->next_move(i).second] = '^'; break; // Sul
                    case 2: maze[jogador->next_move(i).first][jogador->next_move(i).second] = '>'; break; // Oeste
                    case 3: maze[jogador->next_move(i).first][jogador->next_move(i).second] = '<'; break; // Leste
                }

                linha = jogador->next_move(i).first;
                coluna = jogador->next_move(i).second;

                rodada(contador);
                for(auto line : maze){
                    cout<<line<<endl;
                }
                wait(300);
                clearScreen();
            }
            printf("Fase concluída com sucesso!\n");
        }
        jogador->clear_caminho(); // Clear no vector caminho e direção a cada fase
        contador++;
        pontuacao +=10;
    }
    else if(contador == nivel->get_quant_comida()){ // Se a quantidade de rodadas validas for igual a quantidade de comidas
        rodada(contador);
        std::cout<<"PARABÉNS VOCÊ VENCEU!! NÍVEL COMPLETO.\n";
        wait(1500);
        clearScreen();
        state = GAME_OVER;
        //state = GAME_OVER;
    }
    else{
        state = GAME_OVER;
        std::cout<<"GAME OVER BABY\n";
    }
}

void SnakeGame::set_posicao_comida(){
    int controle=0;
    while(nivel->get_linha_lab() * nivel->get_coluna_lab() >= controle){
        nivel->random_comida(); // Gera a comida aleatória
        if(maze[nivel->get_comida_linha()][nivel->get_comida_coluna()] == ' '){
            break;
        }
        controle++;
    } 
}

void SnakeGame::cabecalho(){
    cout<<"        ---> Bem vindx ao classico Snake Game <---\n";
    cout<<"               copyright Luma e Neylane 2021\n";
    cout<<"_____________________________________________________________________\n";
    cout<<"Nível: "<< quantNivel << " | Vidas da cobra: "<< cobra->get_vidas() << " | Maçãs: "<< nivel->get_quant_comida() << "\n";
    cout<<"Conclua todos os níveis e fases para ganhar o jogo. Boa sorte!!!\n";
}

void SnakeGame::rodada(int contador){
    cout<<"____________________________________________________\n";
    cout<<"Vidas: "<< cobra->get_vidas() << " | Score: "<< pontuacao<<" | Quantidade de comida: "<< contador << " de "<< nivel->get_quant_comida() << "\n";
    cout<<"____________________________________________________\n";
}

void SnakeGame::loop(){
    int contador= 0;    // Quantidade de fases rodadas
    cabecalho();        // Imprime o cabeçalho inicial
    wait(1700);
    
    while(state != GAME_OVER){
        process_actions();
        update();
        game(contador);     // Processa as ações do jogo
        render();
        wait(1000);// espera 1 segundo entre cada frame
        maze[nivel->get_comida_linha()][nivel->get_comida_coluna()] = ' ';
    }
}
