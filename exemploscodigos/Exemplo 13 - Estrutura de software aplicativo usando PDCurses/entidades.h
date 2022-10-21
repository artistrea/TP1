#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"


//--------------------------------------------------------------------------------------------
// Declarações de classes entidade e implementações de métodos

class Usuario {
private:
    Nome nome;
    Endereco endereco;
    CEP cep;
    CPF cpf;
    Senha senha;
public:
    void setNome(Nome);
    Nome getNome();
    void setEndereco(Endereco);
    Endereco getEndereco();
    void setCEP(CEP);
    CEP getCEP();
    void setCPF(CPF);
    CPF getCPF();
    void setSenha(Senha);
    Senha getSenha();
};

inline void Usuario::setNome(Nome nome){
    this->nome = nome;
}

inline Nome Usuario::getNome(){
    return nome;
}

inline void Usuario::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

inline Endereco Usuario::getEndereco(){
    return endereco;
}

inline void Usuario::setCEP(CEP cep){
    this->cep = cep;
}

inline CEP Usuario::getCEP(){
    return cep;
}

inline void Usuario::setCPF(CPF cpf){
    this->cpf = cpf;
}

inline CPF Usuario::getCPF(){
    return cpf;
}

inline void Usuario::setSenha(Senha senha){
    this->senha = senha;
}

inline Senha Usuario::getSenha(){
    return senha;
}

//--------------------------------------------------------------------------------------------

class Conta {
    private:
        Numero numero;
        Agencia agencia;
        Banco banco;
        CPF cpf;

    public:
        void setNumero(Numero);
        Numero getNumero();
        void setAgencia(Agencia);
        Agencia getAgencia();
        void setBanco(Banco);
        Banco getBanco();
        void setCPF(CPF);
        CPF getCPF();
};

inline void Conta::setNumero(Numero numero){
    this->numero = numero;
}

inline Numero Conta::getNumero(){
    return numero;
}

inline void Conta::setAgencia(Agencia agencia){
    this->agencia = agencia;
}

inline Agencia Conta::getAgencia(){
    return agencia;
}

inline void Conta::setBanco(Banco banco){
    this->banco = banco;
}

inline Banco Conta::getBanco(){
    return banco;
}

inline void Conta::setCPF(CPF cpf){
    this->cpf = cpf;
}

inline CPF Conta::getCPF(){
    return cpf;
}

//--------------------------------------------------------------------------------------------

class Aplicacao {
    private:
        Codigo codigo;
    public:
        void setCodigo(Codigo);
        Codigo getCodigo();
};

inline void Aplicacao::setCodigo(Codigo codigo){
    this->codigo = codigo;
}

inline Codigo Aplicacao::getCodigo(){
    return codigo;
}

//--------------------------------------------------------------------------------------------

class Produto {
    private:
        Codigo codigo;
    public:
        void setCodigo(Codigo);
        Codigo getCodigo();
};

inline void Produto::setCodigo(Codigo codigo){
    this->codigo = codigo;
}

inline Codigo Produto::getCodigo(){
    return codigo;
}

#endif // ENTIDADES_H_INCLUDED
