#include "dominios.h"

// ----------------------------------------------------------------------
// Implementações de métodos de classe domínio.

void Matricula::validar(int valor) {
    if(valor == MATRICULA_INVALIDA)
        throw invalid_argument("Erro parametro.");
}

void Matricula::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

// ----------------------------------------------------------------------
// Implementações de métodos de classe domínio.

void Senha::validar(int valor) {
    if(valor == SENHA_INVALIDA)
        throw invalid_argument("Erro parametro.");
}

void Senha::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}
