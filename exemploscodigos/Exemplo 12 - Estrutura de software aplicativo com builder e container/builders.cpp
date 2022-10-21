#include "builders.h"

CntrApresentacaoControle* BuilderSistema::construir(){

    // Instanciar controladoras da camada de apresentação.

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();
    cntrApresentacaoProdutosFinanceiros = new CntrApresentacaoProdutosFinanceiros();

    // Instanciar controladoras da camada de serviço.

    cntrServicoPessoal = new CntrServicoPessoal();

    // --------------------------------------------------------------------------------------------
    // Substituir instancia de stub de CntrServicoAutenticacao por instância da controladora.
    // --------------------------------------------------------------------------------------------

    cntrServicoAutenticacao = new StubServicoAutenticacao();

    // ---------------------------------------------------------------------------------------------
    // Substituir instancia de stub de CntrServicoProdutosFinanceiros por instância da controladora.
    // ---------------------------------------------------------------------------------------------

    cntrServicoProdutosFinanceiros = new StubServicoProdutosFinanceiros();

    // Interligar as controladoras.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);
    cntrApresentacaoControle->setCntrApresentacaoProdutosFinanceiros(cntrApresentacaoProdutosFinanceiros);
    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(cntrServicoAutenticacao);
    cntrApresentacaoPessoal->setCntrServicoPessoal(cntrServicoPessoal);
    cntrApresentacaoPessoal->setCntrServicoProdutosFinanceiros(cntrServicoProdutosFinanceiros);
    cntrApresentacaoProdutosFinanceiros->setCntrServicoProdutosFinanceiros(cntrServicoProdutosFinanceiros);

    // Retornar referência para instância de CntrApresentacaoControle.

    return cntrApresentacaoControle;
}

BuilderSistema::~BuilderSistema(){
        delete cntrApresentacaoControle;
        delete cntrApresentacaoAutenticacao;
        delete cntrApresentacaoPessoal;
        delete cntrApresentacaoProdutosFinanceiros;
        delete cntrServicoAutenticacao;
        delete cntrServicoPessoal;
        delete cntrServicoProdutosFinanceiros;
}
