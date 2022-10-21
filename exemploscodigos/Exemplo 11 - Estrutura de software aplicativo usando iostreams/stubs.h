#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações de classes stub.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(CPF, Senha);
};

//--------------------------------------------------------------------------------------------

class StubServicoPessoal:public IServicoPessoal {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarUsuario(Usuario);
};

//--------------------------------------------------------------------------------------------

class StubServicoProdutosFinanceiros:public IServicoProdutosFinanceiros {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarConta(Conta);
        bool consultarConta(Conta*);
        bool cadastrarProdutoInvestimento(Produto);
        bool descadastrarProdutoInvestimento(Codigo);
        bool realizarAplicacao(Aplicacao);
        bool recuperarAplicacao(Aplicacao*);                        // Adaptar assinatura.
};

#endif // STUBS_H_INCLUDED
