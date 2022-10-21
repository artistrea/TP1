#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras de serviço.

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        virtual bool autenticar(CPF, Senha);
};

//--------------------------------------------------------------------------------------------

class CntrServicoPessoal:public IServicoPessoal{
};

//--------------------------------------------------------------------------------------------

class CntrServicoProdutosFinanceiros:public IServicoProdutosFinanceiros{
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
