#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "containers.h"

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços.

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        bool autenticar(CPF, Senha);
};

//--------------------------------------------------------------------------------------------

class CntrServicoPessoal:public IServicoPessoal{
    public:
        bool cadastrarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------

class CntrServicoProdutosFinanceiros:public IServicoProdutosFinanceiros{
    // Métodos públicos presentes na interface realizada.
};


#endif // CONTROLADORASSERVICO_H_INCLUDED
