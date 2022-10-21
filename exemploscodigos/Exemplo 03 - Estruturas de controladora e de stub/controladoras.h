#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------
// Declaração de classe controladora e implementação de método.

class CntrIUAutenticacao:public IUAutenticacao {
private:
    ILNAutenticacao *cntrLNAutenticacao;        // Referência para servidor.
public:
    bool autenticar(Matricula*);
    void setCntrLNAutenticacao(ILNAutenticacao*);
};

void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}

#endif // CONTROLADORAS_H_INCLUDED
