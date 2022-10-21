// Exemplos de estruturas de classe controladora e stub.

// Incluir cabeçalhos.

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
    // ---------------------------------------------------------------------------------
    // Instanciar classe controladora e classe stub.

    IUAutenticacao  *cntrIUAutenticacao = new CntrIUAutenticacao();
    ILNAutenticacao *stubLNAutenticacao = new StubLNAutenticacao();

    // Ligar instância de controladora a instância de stub.

    cntrIUAutenticacao->setCntrLNAutenticacao(stubLNAutenticacao);

    bool resultado;

    Matricula matricula;

    while(true){

        // Simular apresentação de tela inicial do sistema.

        cout << endl << "Tela inicial de sistema." << endl;

        try{

            // Soliciatar serviço de autenticação.

            resultado = cntrIUAutenticacao->autenticar(&matricula);
        }
        catch(const runtime_error &exp){
                 cout << "Erro de sistema." << endl;
                 break;
        }

        // Criticar resultado da autenticação.

        if(resultado) {
            cout << endl << "Sucesso autenticacao." << endl;
            cout << endl << "Matricula = " << matricula.getValor() << endl;
            break;
        }
        else {
            cout << endl << "Erro autenticacao." << endl;
            break;
        }
    }

    // Destruir instância de controladora e instância de stub.

    delete cntrIUAutenticacao;
    delete stubLNAutenticacao;

    return 0;
}
