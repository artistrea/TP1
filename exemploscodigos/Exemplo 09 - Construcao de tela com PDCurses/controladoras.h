#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;


// Declaração de classe controladora de interação para o serviço de autenticação.

class CntrIUAutenticacao:public IUAutenticacao {
private:
    ILNAutenticacao *cntrLNAutenticacao;            // Referência para servidor.

public:
    bool autenticar();
    void setCntrLNAutenticacao(ILNAutenticacao*);
};


void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}

#endif // CONTROLADORAS_H_INCLUDED
