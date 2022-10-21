#ifndef MODULOS_H_INCLUDED
#define MODULOS_H_INCLUDED

#include "Dominios.h"
#include "Interfaces.h"
#include "Containers.h"
#include <iostream>
#include <string.h>

using namespace std;

#ifdef __GNUC__
#define CLR_SCR system("clear")
#endif

#ifdef  __MINGW32__
#define CLR_SCR system("cls")
#endif

#ifndef CLR_SCR
#define CLR_SCR cout << "\033[2J\033[1;1H"
#endif


// Modulos de servico
// MSA, que deve se tornar MSU lá no diagrama
class ModuloServUsr : public ISU {
private:
    static ContainerUsuario* container;
public:
    vector<Usuario> todos();
    Usuario pesquisar(string);
    bool adicionar(Usuario);
    bool atualizar(Usuario);
    bool remover(string);

    bool autenticar_usuario(string, string);
};

// MSHU, que deve se tornar MSH lá no diagrama

class ModuloServHosp : public ISH {
private:
    static ContainerHospedagem* container;
    static int codigo_inicial;
public:
    vector<Hospedagem> todos();
    Hospedagem pesquisar(string);
    bool adicionar(Hospedagem);
    bool atualizar(Hospedagem);
    bool remover(string);

    string cria_codigo();
};

// MSA
class ModuloServAval : public ISA {
private:
    static ContainerAvaliacao* container;
public:
    vector<Avaliacao> todos(Hospedagem);
    vector<Avaliacao> todos(Email);

    bool adicionar(Avaliacao);
    bool atualizar(Avaliacao);
    bool remover(string);
    Avaliacao pesquisar(string);
    string cria_codigo();
};


// Modulo de apresentacao
// MCA
class ModuloCntrlAprs {
private:
    IAH* modAprsHosp;
    IACU* modAprsCadUsr;
    ICAU* modAprsAutUsr;
public:
    void executar();
};

// MAH
class ModuloAprsHosp : public IAH {
private:
    static ModuloServHosp* moduloServHosp;
    void todos();
    void mostrar(Hospedagem*);
public:
    void executar();
};

// MACU
class ModuloAprsCadUsr : public IACU {
private:
    ISU* cntrISU;
public:
    void cadastrar_usuario();
};

// MCAU
class ModuloCntrAprsUsr :public ICAU {
private:
    ISU* cntrISU;
    IAUU* aprUsrUsr;
    IAHU* aprHopsUsr;
    IAAU* aprAvalUsr;

public:
    bool executar();
};

// MAUU
class ModuloAprsUsrUsr :public IAUU {
public:
    void descadastrar_usuario(string email);
    void editar_usuario(string email);
    void executar(string email);
};


class ModuloAprsHospUsr :public IAHU {
public:
    void executar(string email);
    void cadastrar_hospedagem(string email);
    void descadastrar_hospedagem(string email);
    void editar_hospedagem(string email);
};

// MAAU

class ModuloAprsAvalUsr :public IAAU {
public:
    void executar(string email);
    void cadastrar_avaliacao(string email);
    void editar_avaliacao(string email);
    void descadastrar_avaliacao(string email);
};


#endif // MODULOS_H_INCLUDED
