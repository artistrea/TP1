#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;


// Declara��o de classe controladora de intera��o para o servi�o de autentica��o.

class CntrIUAutenticacao:public IUAutenticacao {
private:
    ILNAutenticacao *cntrLNAutenticacao;            // Refer�ncia para servidor.

public:
    bool autenticar();
    void setCntrLNAutenticacao(ILNAutenticacao*);
};


void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}

#endif // CONTROLADORAS_H_INCLUDED