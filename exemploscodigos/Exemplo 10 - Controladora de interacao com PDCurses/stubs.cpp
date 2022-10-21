#include "stubs.h"

const string StubServicoAutenticacao::INVALIDO = "12345";

bool StubServicoAutenticacao::autenticar(CPF cpf, Senha senha){
    if(cpf.getValor().compare(INVALIDO) == 0)
        return false;
    return true;
}


