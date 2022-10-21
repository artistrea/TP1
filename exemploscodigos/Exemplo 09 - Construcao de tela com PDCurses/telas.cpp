#include "telas.h"

//-------------------------------------------------------------------------------------------------------------------------
// Implementações de métodos de classes tela.

void TelaAutenticacao::apresentar(Matricula *matricula, Senha *senha) {

    char campo1[]="Digite a matricula : ";
    char campo2[]="Digite a senha     : ";
    char dado1[80];
    char dado2[80];
    int linha,coluna;

    initscr();                                                                      // Iniciar curses.
    getmaxyx(stdscr,linha,coluna);                                                  // Armazenar quantidade de linhas e de colunas.
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);                        // Imprimir nome do campo.
    getstr(dado1);                                                                  // Ler dado.
    mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);                    // Imprimir nome do campo.
    getstr(dado2);                                                                  // Ler dado.
    clear();                                                                        // Limpar janela.
    endwin();                                                                       // Finalizar curses.

    matricula->setValor(atoi(dado1));
    senha->setValor(atoi(dado2));
}

void TelaMensagem::apresentar(string mensagem) {

    int linha,coluna;

    initscr();                                                                      // Iniciar curses.
    getmaxyx(stdscr,linha,coluna);                                                  // Armazenar quantidade de linhas e de colunas.
    mvprintw(linha/2,(coluna-strlen(mensagem.c_str()))/2,"%s", mensagem.c_str());   // Imprimir dado.
    noecho();                                                                       // Desabilitar eco.
    getch();                                                                        // Ler caracter digitado.
    echo();                                                                         // Habilitar eco.
    clear();                                                                        // Limpar janela.
    endwin();
}
