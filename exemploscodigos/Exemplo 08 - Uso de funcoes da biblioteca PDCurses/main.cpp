// Exemplo de uso de funções da biblioteca PDCurses.

#include <string.h>

// Incluir cabeçalho da biblioteca.

#include "curses.h"

using namespace std;

int main()
{
    char campo1[]="Digite o CPF  : ";
    char campo2[]="Digite a senha: ";
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
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"Digitado CPF   : %s",dado1);        // Imprimir dado.
    mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"Digitada senha : %s",dado2);    // Imprimir dado.
    noecho();                                                                       // Desabilitar eco.
    getch();                                                                        // Ler caracter digitado.
    echo();                                                                         // Habilitar eco.
    endwin();                                                                       // Finalizar curses.

    return 0;
}

