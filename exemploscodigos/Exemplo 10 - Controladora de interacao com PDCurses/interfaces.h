#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"

// Forward declarations.

class IServicoAutenticacao;

//------------------------------------------------------------------------
// Declarações de interfaces.

class IApresentacaoAutenticacao {
public:
    virtual bool autenticar(CPF*) = 0;
    virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
    virtual ~IApresentacaoAutenticacao(){}
};

class IServicoAutenticacao {
public:
    virtual bool autenticar(CPF, Senha) = 0;
    virtual ~IServicoAutenticacao(){}
};

#endif // INTERFACES_H_INCLUDED
