#include "controladoras.h"

//--------------------------------------------------------------------------------------------------------------------
// Implementação de método.

bool CntrApresentacaoAutenticacao::autenticar(CPF *cpf){

    char texto1[]="Digite o CPF  : ";                                                   // Mensagens a serem apresentadas.
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado de entrada em formato incorreto.";
    char texto4[]="Digite novos dados.";
    char texto5[]="Falha na autenticacao, digite algo para continuar.";

    char campo1[80];                                                                    // Campos de entrada.
    char campo2[80];

    Senha senha;                                                                        // Instanciar a classe Senha.

    int linha,coluna;                                                                   // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                      // Armazenar quantidade de linhas e colunas.

    echo();                                                                             // Habilitar eco.

    while(true){
        clear();                                                                        // Limpar janela.

        mvprintw(linha/2,(coluna - strlen(texto1))/4,"%s",texto1);                      // Imprimir nome do campo.
        getstr(campo1);                                                                 // Ler valor do campo.
        mvprintw(linha/2 + 2,(coluna - strlen(texto1))/4,"%s",texto2);                  // Imprimir nome do campo.
        getstr(campo2);                                                                 // Ler valor do campo.

        try{
            cpf->setValor(string(campo1));                                              // Instanciar CPF e atribuir valor.
            senha.setValor(string(campo2));                                             // Instanciar Senha e atribuir valor.
            break;                                                                      // Abandonar laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                   // Capturar exceção devido a formato incorreto.
            clear();                                                                    // Limpar janela.
            mvprintw(linha/2,(coluna - strlen(texto1))/4,"%s",texto3);                  // Imprimir mensagem.
            mvprintw(linha/2 + 2,(coluna - strlen(texto1))/4,"%s",texto4);              // Imprimir nome do campo.
            getch();                                                                    // Ler caracter digitado.
        }
    }

    if(cntr->autenticar(*cpf, senha))                                                   // Solicitar serviço de autenticação.
        return true;                                                                    // Retornar informando sucesso na autenticação.

    clear();                                                                            // Limpar janela.
    mvprintw(linha/2,(coluna - strlen(texto1))/4,"%s",texto5);                          // Imprimir mensagem.
    noecho();                                                                           // Desabilitar eco.
    getch();                                                                            // Ler caracter digitado.
    echo();                                                                             // Habilitar eco.

    return false;                                                                       // Retornar informando falha na autenticação.
}
