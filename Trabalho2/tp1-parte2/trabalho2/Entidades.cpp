#include "Entidades.h"
#include <stdexcept>

Usuario::Usuario(const string& nome, const string& email, const string& senha,
  const string& idioma, const string& aniversario, const string& descricao) :
  nome(nome), email(email), senha(senha),
  idioma(idioma), aniversario(aniversario), descricao(descricao) {
}

Hospedagem::Hospedagem(const string& codigo, const string& cidade,
  const string& pais, const string& nota, const string& descricao, const string& email_anfitriao) :
  codigo(codigo), cidade(cidade), pais(pais),
  nota(nota), descricao(descricao), email_anfitriao(email_anfitriao) {
}

Avaliacao::Avaliacao(const string& codigo, const string& nota, const string& descricao, const Hospedagem& hospedagem, const string& email_usuario) :
  codigo(codigo), nota(nota), descricao(descricao), email_usuario(email_usuario), codigo_hospedagem(hospedagem.getCodigo()) {
}

