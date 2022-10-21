#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "Interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------------------
// Declaração de classe stub.

class StubLNAutenticacao:public ILNAutenticacao{
public:

    // Definições de valores a serem usados como gatilhos para notificações de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

    // Declaração de método previsto na interface.

    bool autenticar(const Matricula&, const Senha&) ;
};

#endif // STUBS_H_INCLUDED
