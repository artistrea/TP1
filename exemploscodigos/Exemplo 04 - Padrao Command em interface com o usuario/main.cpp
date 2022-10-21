// Exemplo de uso do padrão de projeto Command na construção de interface com o usuário.

// Incluir cabeçalhos.

#include <stdexcept>
#include <iostream>
#include <string>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

using namespace std;

int main()
{
    // -------------------------------------------------------------------------------------------
    // Declarar ponteiros e instanciar controladoras.

    IAAutenticacao  *cntrIAAutenticacao;
    IAGerente       *cntrIAGerente;

    cntrIAAutenticacao = new CntrIAAutenticacao();
    cntrIAGerente = new CntrIAGerente();

    // -------------------------------------------------------------------------------------------
    // Declarar ponteiros e instanciar stubs.

    ISAutenticacao *stubISAutenticacao;
    ISGerente      *stubISGerente;

    stubISAutenticacao = new StubISAutenticacao();
    stubISGerente = new StubISGerente();

    // -------------------------------------------------------------------------------------------
    // Estabelecer relacionamentos entre instâncias de controladoras e instâncias de stubs.

    cntrIAAutenticacao->setCntrISAutenticacao(stubISAutenticacao);
    cntrIAGerente->setCntrISGerente(stubISGerente);

    bool resultado;

    Matricula matricula;

    while(true){

        // Simular apresentação da tela inicial do sistema.

        cout << endl << "Tela inicial de sistema." << endl;

        try{

            // Solicitar serviço de autenticação.

            resultado = cntrIAAutenticacao->autenticar(&matricula);

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
        catch(const runtime_error &exp){
                 cout << "Erro de sistema." << endl;
        }
    }

    try{

        // Solicitar serviço da controladora de apresentação.

        cntrIAGerente->executar(matricula);
    }
    catch(const runtime_error &exp){
        cout << "Erro de sistema." << endl;
    }

    // Destruir instâncias criadas.

    delete cntrIAAutenticacao;
    delete cntrIAGerente;
    delete stubISAutenticacao;
    delete stubISGerente;

    return 0;
}
