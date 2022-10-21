#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"

// #-----------------------------------------classe Usuario-----------------------------------------#

/// \brief Entidade Usuario
///
/// Usu�rio que utilizar� a aplica��o. Interage com hospedagem e avalia��o.
class Usuario {
private:
    Nome nome;
    Email email;
    Senha senha;
    Idioma idioma;
    Data aniversario;
    Descricao descricao;

public:
    void setNome(const string&);
    string getNome() const;

    void setEmail(const string&);
    string getEmail() const;

    void setSenha(const string&);
    string getSenha() const;

    void setIdioma(const string&);
    string getIdioma() const;

    void setAniversario(const string&);
    string getAniversario() const;

    void setDescricao(const string&);
    string getDescricao() const;
    /// Construtor da entidade Usu�rio que utiliza os testes para valida��o dos atributos a serem inseridos
    /// @param nome, email, senha, idioma, aniversario, descricao
    Usuario(const string&, const string&, const string&, const string&, const string&, const string&);
};


inline void Usuario::setNome(const string& nome) {
    this->nome.setValor(nome);
}

inline string Usuario::getNome() const {
    return nome.getValor();
}

inline void Usuario::setEmail(const string& email) {
    this->email.setValor(email);
}

inline string Usuario::getEmail() const {
    return email.getValor();
}

inline void Usuario::setSenha(const string& senha) {
    this->senha.setValor(senha);
}

inline string Usuario::getSenha() const {
    return senha.getValor();
}

inline void Usuario::setIdioma(const string& idioma) {
    this->idioma.setValor(idioma);
}

inline string Usuario::getIdioma() const {
    return idioma.getValor();
}

inline void Usuario::setAniversario(const string& aniversario) {
    this->aniversario.setValor(aniversario);
}

inline string Usuario::getAniversario() const {
    return aniversario.getValor();
}

inline void Usuario::setDescricao(const string& descricao) {
    this->descricao.setValor(descricao);
}

inline string Usuario::getDescricao() const {
    return descricao.getValor();
}


// #-----------------------------------------classe hospedagem-----------------------------------------#

/// Campo que define o objeto Hospedagem e seus atributos.
class Hospedagem {
private:
    Codigo codigo;
    Cidade cidade;
    Pais pais;
    Nota nota;
    Descricao descricao;
    Email email_anfitriao;

public:
    void setCodigo(const string&);
    string getCodigo() const;

    void setCidade(const string&);
    string getCidade() const;

    void setPais(const string&);
    string getPais() const;

    void setNota(const string&);
    string getNota() const;

    void setDescricao(const string&);
    string getDescricao() const;

    string getEmailAnfitriao() const;
    /// Cada atributo da entidade possui um set/get<b>NomeDoAtributo</b>
    ///
    /// � necess�rio inserir cinco par�metros para os construtores da Hospedagem
    /// @param (codigo, cidade, pais, nota, descricao)
    Hospedagem(const string&, const string&, const string&, const string&, const string&, const string&);
};

inline void Hospedagem::setCodigo(const string& codigo) {
    this->codigo.setValor(codigo);
}

inline string Hospedagem::getCodigo() const {
    return codigo.getValor();
}

inline void Hospedagem::setCidade(const string& cidade) {
    this->cidade.setValor(cidade);
}

inline string Hospedagem::getCidade() const {
    return cidade.getValor();
}

inline void Hospedagem::setPais(const string& pais) {
    this->pais.setValor(pais);
}

inline string Hospedagem::getPais() const {
    return pais.getValor();
}

inline void Hospedagem::setNota(const string& nota) {
    this->nota.setValor(nota);
}

inline string Hospedagem::getNota() const {
    return nota.getValor();
}

inline void Hospedagem::setDescricao(const string& descricao) {
    this->descricao.setValor(descricao);
}

inline string Hospedagem::getDescricao() const {
    return descricao.getValor();
}

inline string Hospedagem::getEmailAnfitriao() const {
    return email_anfitriao.getValor();
}


// #-----------------------------------------classe Avaliacao-----------------------------------------#
/// Avaliacao, dada por um usuario sobre uma hospedagem.
class Avaliacao {
private:
    Codigo codigo;  ///< Dominio Codigo. Serve como primary key da classe
    Nota nota;  ///< Dominio Nota. Guarda a nota dada
    Descricao descricao;  ///< Dominio Nota. Guarda a nota dada
    Codigo codigo_hospedagem;
    Email email_usuario;

public:
    /// chama setValor() de dominio
    void setCodigo(const string&);
    string getCodigo() const;

    void setNota(const string&);
    string getNota() const;

    void setDescricao(const string&);
    string getDescricao() const;

    string getEmailUsuario() const;

    string getCodigoHospedagem() const;
    /// Construtor da entidade Avalia��o, por meio da valida��o de cada um das strings introduzidas
    /// @param codigo, nota, descricao
    Avaliacao(const string&, const string&, const string&, const Hospedagem&, const string&);
};

inline void Avaliacao::setCodigo(const string& codigo) {
    this->codigo.setValor(codigo);
}

inline string Avaliacao::getCodigo() const {
    return codigo.getValor();
}

inline void Avaliacao::setNota(const string& nota) {
    this->nota.setValor(nota);
}

inline string Avaliacao::getNota() const {
    return nota.getValor();
}

inline void Avaliacao::setDescricao(const string& descricao) {
    this->descricao.setValor(descricao);
}

inline string Avaliacao::getDescricao() const {
    return descricao.getValor();
}

inline string Avaliacao::getEmailUsuario() const {
    return email_usuario.getValor();
}

inline string Avaliacao::getCodigoHospedagem() const {
    return codigo_hospedagem.getValor();
}
// #---------------------------------------------------------------------------------------------------#

#endif // ENTIDADES_H_INCLUDED

