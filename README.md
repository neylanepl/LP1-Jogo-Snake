# Projeto 3 - Snaze: A Snake Trapped in a Maze
Neste projeto vamos desenvolver uma simulação do jogo clássico Snake, com uma diferença, a cobra está presa dentro de um labirinto. A simulação do jogo Snaze carrega o nı́vel do labirinto a partir de um arquivo texto de entrada,
cujo nome é fornecido via argumento de linha de comando, e controla os movimentos da cobra. Para guiar a cobra até a comida que surge em posições aleatórias dentro do labirinto sem que a
cobra colida com as paredes do mesmo ou consigo mesma, projetamos um motor básico de inteligência artificial
(IA). Pode haver um ou mais nı́veis, dependendo do arquivo de entrada, a cobra pode ganhar a simulação do jogo se comer todas as comidas disponı́veis em todos os nı́veis, e pode perder a simulação do jogo quando todas as 5 vidas são gastas.

Realizado pelas alunas: Luma de Abreu Fragoso e Neylane Pereira Lopes.

## Categorias do Projeto
O projeto está organizado da seguinte forma:

```
trabalho-03-neylanepl       ---> Pasta do projeto.
├── build                   ---> Pasta que contém os arquivos executáveis.            
├── data                    ---> Pasta que contém os arquivos de entrada do projeto.
│   ├── maze1.txt           ---> Arquivo com dois níveis sem erro
│   ├── maze2.txt           ---> Arquivo com um nível sem erro
│   ├── maze3.txt           ---> Arquivo com um nível sem a cobra (erro)
│   ├── maze4.txt           ---> Arquivo com um nível valor da linha do labirinto < 0 (erro)
│   ├── maze5.txt           ---> Arquivo com um nível valor da coluna do labirinto < 0 (erro)
│   ├── maze6.txt           ---> Arquivo com um nível valor da linha do labirinto > 100 (erro)
│   └── maze7.txt           ---> Arquivo com um nível valor da coluna do labirinto > 100 (erro)
├── include                 ---> Pasta que contém os headers '.h' do projeto.
│   ├── Level.h             ---> Arquivo com header de 'Level.cpp'
│   ├── Player.h            ---> Arquivo com header de 'Player.cpp'
│   ├── Snake.h             ---> Arquivo com header de 'Snake.cpp'
│   └── SnakeGame.h         ---> Arquivo com header de 'SnakeGame.cpp'
├── src                     ---> Pasta que que contém os arquivos '.cpp' do projeto.
│   ├── Level.cpp           ---> Arquivo com metodos para os níveis
│   ├── Player.cpp          ---> Arquivo com metodos para jogador (IA)
│   ├── Snake.cpp           ---> Arquivo com metodos para a cobra
│   ├── SnakeGame.cpp       ---> Arquivo que coloca o jogo para funcionar
│   └── Snaze.cpp           ---> Arquivo com função main
├── CMakeLists.txt          ---> Arquivo do cmake
├── Makefile                ---> Arquivo makefile
└── README.md               ---> Instruções para compilar e executar o programa.
```
# Compilando e Executando
A compilação e execução do projeto pode ser feita usando *cmake*.

## Como compilar o projeto

### Usando cmake

1. Entre na pasta do projeto, no caso `trabalho-03-neylanepl`.
```console
cd trabalho-03-neylanepl
```

2. Crie a pasta `build`.
```console
mkdir build
```

3. Entre na pasta `build`.
```console
cd build
```

4. Execute o comando do *cmake* para gerar os arquivos intermediários.
```console
cmake ..
```

5. Execute o comando do *cmake* para compilar o projeto. Assim, a pasta build conterá os arquivos *Makefile* e o executável *snake*.
```console
cmake --build .
```

## Como executar o conjunto dos testes planejados

Rode o executável *snake* e forneça como argumento o arquivo de teste. Dessa forma, é necessário informar o endereço do arquivo de teste a partir da pasta que ele se encontra. 

Neste caso, serão executados alguns arquivos de teste que se encontram na pasta `data`. Os comandos ficam do seguinte modo:

1. Teste com dois níveis sem erro
```console
./snake ../data/maze1.txt
```
2. Teste com um nível sem erro
```console
./snake ../data/maze2.txt
```
3. Teste com um nível sem a cobra (erro)
```console
./snake ../data/maze3.txt
```
4. Teste com um nível valor da linha do labirinto < 0 (erro)
```console
./snake ../data/maze4.txt
```
5. Teste com um nível valor da coluna do labirinto < 0 (erro)
```console
./snake ../data/maze5.txt
```
6. Teste com um nível valor da linha do labirinto > 100 (erro)
```console
./snake ../data/maze6.txt
```
7. Teste com um nível valor da coluna do labirinto > 100 (erro)
```console
./snake ../data/maze7.txt
```

# Limitações ou funcionalidades não implementadas no programa

Analisando as implementações realizadas, acredita-se que apenas deixamos de implementar as funcionalidades ligadas ao corpo da cobra. Desse modo, a cobra realiza recursão e encontra a comida, mas o seu corpo não cresce.
