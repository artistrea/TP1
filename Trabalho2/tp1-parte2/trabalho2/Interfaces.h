#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "Dominios.h"
#include <stdexcept>

using namespace std;


//==================================================
// Interfaces de Apresentacao

class IAH {
    // Interface apresentacao hospedagem

public:
    virtual void executar() = 0;
    virtual ~IAH() {};
};

class IACU {
    // Interface de cadastro para usuario

public:
    virtual void cadastrar_usuario() = 0;
    virtual ~IACU() {};
};

class ICAU {
    // Interface apresentacao para usuario

public:
    virtual bool executar() = 0;
    virtual ~ICAU() {};
};

class IAUU {
    // Interface de apresentacao para usuario ja cadastrado

public:
    virtual void editar_usuario(string email) = 0;
    virtual void descadastrar_usuario(string email) = 0;
    virtual void executar(string email) = 0;
    virtual ~IAUU() {};
};

class IAHU {
    // Interface de apresentação de hospedagem para usuário já cadastrado

public:
    virtual void executar(string email) = 0;
    virtual void cadastrar_hospedagem(string email) = 0;
    virtual void descadastrar_hospedagem(string email) = 0;
    virtual void editar_hospedagem(string email) = 0;
    virtual ~IAHU() {};

};

class IAAU {
    // Interface de apresentação de avaliação para usuário já cadastrado

public:
    virtual void executar(string email) = 0;
    virtual void cadastrar_avaliacao(string email) = 0;
    virtual void editar_avaliacao(string email) = 0;
    virtual void descadastrar_avaliacao(string email) = 0;
    virtual ~IAAU() {};
};



//==================================================
// Interfaces de Servico

template<class Entidade>
class IS {
public:
    virtual Entidade pesquisar(string) = 0;

    virtual bool atualizar(Entidade) = 0;

    virtual bool remover(string) = 0;

    virtual bool adicionar(Entidade) = 0;
};


class ISH : public IS<Hospedagem> {
    //  Interface de serviço para hospedagem

    static int codigo_inicial;
public:
    virtual vector<Hospedagem> todos() = 0;

    virtual string cria_codigo() = 0; // utility

    // virtual vector<Hospedagem> encontrarPorUsuario(string) = 0;
    // virtual vector<Hospedagem> encontrarPorAvaliacao(string) = 0;

    virtual ~ISH() {};
};


class ISU : public IS<Usuario> {
    // Interface de serviço para usuário
public:
    virtual bool autenticar_usuario(string, string) = 0;
    virtual ~ISU() {};
};

class ISA : public IS<Avaliacao> {
    // Interface de serviço de avaliação

public:
    virtual vector<Avaliacao> todos(Hospedagem) = 0;
    virtual vector<Avaliacao> todos(Email) = 0;
    virtual string cria_codigo() = 0;
    virtual ~ISA() {};
};


#endif // INTERFACES_H_INCLUDED
