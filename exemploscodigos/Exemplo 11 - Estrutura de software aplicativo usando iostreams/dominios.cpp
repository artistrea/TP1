#include "dominios.h"

//--------------------------------------------------------------------------------------------
// Implementações de métodos de classes domínio.
//
// Métodos com implementações simplificadas com o intuito de facilitar a construção do exemplo.


void CPF::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Senha::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Codigo::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Numero::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Nome::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Endereco::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void CEP::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Agencia::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Banco::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}
