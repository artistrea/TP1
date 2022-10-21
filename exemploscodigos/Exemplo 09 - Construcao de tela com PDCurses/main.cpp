// Exemplos desenvolvidos para ilustrar a sintaxe da linguagem.

#include <stdexcept>
#include <iostream>
#include <string>

#include "dominios.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

using namespace std;

int main()
{
    // Declarar ponteiro e instanciar controladora.

    IUAutenticacao  *cntrIUAutenticacao;
    cntrIUAutenticacao = new CntrIUAutenticacao();

    // Declarar ponteiro e instanciar stub.

    ILNAutenticacao *stubLNAutenticacao;
    stubLNAutenticacao = new StubLNAutenticacao();

    // Estabelecer relacionamento entre controladora e stub.

    cntrIUAutenticacao->setCntrLNAutenticacao(stubLNAutenticacao);

    try{
        // Solicitar serviço de autenticação.

        bool resultado = cntrIUAutenticacao->autenticar();

        // Criticar resultado da autenticação.

        if(resultado) {
            cout << "Sucesso na autenticacao." << endl;
        }
        else {
            cout << "Erro na autenticacao." << endl;
        }
    }
    catch(const runtime_error &exp){
        cout << "Erro de sistema." << endl;
    }

    // Destruir objetos criados.

    delete cntrIUAutenticacao;
    delete stubLNAutenticacao;

    return 0;
}
