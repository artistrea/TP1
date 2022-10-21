#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

// Incluir cabeçalhos.

#include "dominios.h"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.

class ILNAutenticacao;
class ILNGerente;

// Declaração de interface da camada de apresentação.

class IUAutenticacao {
public:
    virtual bool autenticar() = 0;                                  // Método por meio do qual é solicitado serviço.
    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;      // Método para ligar (link) controladora na camada de serviço.
    virtual ~IUAutenticacao(){}                                     // Método destrutor virtual.
};

// Declaração de interface da camada de serviço.

class ILNAutenticacao {
public:
    virtual bool autenticar(const Matricula&, const Senha&) = 0;    // Método por meio do qual é solicitado serviço.
    virtual ~ILNAutenticacao(){}                                    // Método destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
