#include "Entidades.h"
#include <stdexcept>

Usuario:: Usuario(const string& nome, const string& email, const string& senha,
  const string& idioma, const string& aniversario, const string& descricao):
  nome(nome),     email(email), senha(senha),
  idioma(idioma), aniversario(aniversario),   descricao(descricao) {
}

Hospedagem::Hospedagem(const string& codigo, const string& cidade,
  const string& pais, const string& nota, const string& descricao) :
  codigo(codigo), cidade(cidade), pais(pais),
  nota(nota),     descricao(descricao) {
}

Avaliacao::Avaliacao(const string& codigo, const string& nota, const string& descricao) : 
  codigo(codigo), nota(nota), descricao(descricao) {
}
