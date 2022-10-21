// Exemplo de controladora de interação com PDCurses.

#include <string.h>
#include <stdexcept>
#include <iostream>

// Incluir cabeçalho da biblioteca PDCurses.

#include "curses.h"

#include "dominios.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"


using namespace std;

int main()
{
    IApresentacaoAutenticacao *cntr;
    IServicoAutenticacao *stub;

    CPF cpf;

    bool resultado;

    cntr = new CntrApresentacaoAutenticacao();                                      // Instanciar controladora.
    stub = new StubServicoAutenticacao();                                           // Instanciar stub.

    cntr->setCntrServicoAutenticacao(stub);                                         // Inteligar controladora e stub.

    initscr();                                                                      // Iniciar curses.

    resultado = cntr->autenticar(&cpf);                                             // Solicitar serviço de autenticacao.

    endwin();                                                                       // Finalizar curses.

    // Apresentar resultado do processo de autenticação.

    if(resultado)
        cout << "Sucesso na autenticacao";
    else
        cout << "Falha na autenticacao";

    return 0;
}

