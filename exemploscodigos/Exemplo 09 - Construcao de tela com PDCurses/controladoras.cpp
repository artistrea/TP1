#include "controladoras.h"
#include "telas.h"

// Definições de métodos da classe CntrIUAutenticacao.

bool CntrIUAutenticacao::autenticar() {

    bool resultado;

    Matricula matricula;
    Senha senha;

    // Apresentar tela de autenticação.

    while(true) {

        try {
            TelaAutenticacao telaAutenticacao;
            telaAutenticacao.apresentar(&matricula, &senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    // Solicitar autenticação.

    resultado = cntrLNAutenticacao->autenticar(matricula, senha);

    return resultado;
}
