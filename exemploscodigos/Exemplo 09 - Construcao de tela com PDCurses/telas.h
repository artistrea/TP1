#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "dominios.h"
#include <string.h>
#include <stdlib.h>
#include "curses.h"

class TelaAutenticacao {
public:
    void apresentar(Matricula*, Senha*);       // Método por meio do qual é solicitada a apresentação da tela.
};

class TelaMensagem {
public:
    void apresentar(string);                    // Método por meio do qual é solicitada a apresentação da tela.
};


#endif // COMANDOS_H_INCLUDED

