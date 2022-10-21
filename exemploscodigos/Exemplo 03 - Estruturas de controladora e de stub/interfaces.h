#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"

#include <stdexcept>

using namespace std;

// Declaração adiantada (forward declaration)

class ILNAutenticacao;

// -------------------------------------------------------------------------------------------
// Declaração de interface para serviço de autenticação provido pela camada de apresentação.

class IUAutenticacao {
public:

    virtual bool autenticar(Matricula*) = 0;                        // Método por meio do qual é solicitado serviço.
    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;      // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.
    virtual ~IUAutenticacao(){}                                     // Método destrutor virtual.
};

// -------------------------------------------------------------------------------------------
// Declaração de interface para serviço de autenticação provido pela camada de serviço.

class ILNAutenticacao {
public:
    virtual bool autenticar(const Matricula&, const Senha&) = 0;    // Método por meio do qual é solicitado serviço.
    virtual ~ILNAutenticacao(){}                                    // Método destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
