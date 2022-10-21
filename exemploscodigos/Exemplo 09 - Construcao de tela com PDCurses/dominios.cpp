#include "dominios.h"

//-------------------------------------------------------------------------------
// Implementações de métodos da classe Matricula.

void Matricula::validar(int valor) {
    if (valor == MATRICULA_INVALIDA)
        throw invalid_argument("Argumento invalido.");
}

void Matricula::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

//-------------------------------------------------------------------------------
// Implementações de métodos da classe Senha.

void Senha::validar(int valor) {
    if(valor == SENHA_INVALIDA)
        throw invalid_argument("Erro parametro.");
}

void Senha::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}
