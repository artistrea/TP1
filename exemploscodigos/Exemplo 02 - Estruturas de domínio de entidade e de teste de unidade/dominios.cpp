#include "dominios.h"

// --------------------------------------------------------------------------
// Implementações de métodos de classe domínio.

void Codigo::validar(int codigo){
    if (codigo > LIMITE)
        throw invalid_argument("Argumento invalido.");
}

void Codigo::setValor(int valor){
    validar(valor);
    this->valor = valor;
}

// --------------------------------------------------------------------------
// Implementações de métodos de classe domínio.

void Prioridade::validar(int valor){
    if (valor == INVALIDO)
        throw invalid_argument("Argumento invalido.");
}

void Prioridade::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}
