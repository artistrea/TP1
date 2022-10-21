#include "stubs.h"

// -------------------------------------------------------------------------------------------
// Definições de constantes.

const int StubLNAutenticacao::TRIGGER_FALHA;
const int StubLNAutenticacao::TRIGGER_ERRO_SISTEMA;

// -------------------------------------------------------------------------------------------
// Implementação de método.

bool StubLNAutenticacao::autenticar(const Matricula &matricula, const Senha &senha) {

    // Apresentar dados recebidos.

    cout << endl << "StubLNAutenticacao::autenticar" << endl ;
    cout << "Matricula = " << matricula.getValor()   << endl ;
    cout << "Senha     = " << senha.getValor()       << endl ;

    // Diferentes comportamentos dependendo do valor da matrícula.

    switch(matricula.getValor()){
        case TRIGGER_FALHA:
            return false;
        case TRIGGER_ERRO_SISTEMA:
            throw runtime_error("Erro de sistema");
    }

    return true;
}

