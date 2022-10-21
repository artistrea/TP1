#include "dominios.h"

//---------------------------------------------------------------------------
// Implementações de métodos.

void CPF::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Senha::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}
