#include <iostream>

#include "Dominios.h"
#include "Entidades.h"

using namespace std;

int main()
{
     //------------------possivel teste pra hospedagem---------------------//
    // Hospedagem *hospedagem;
    // hospedagem->setCodigo(Codigo("12345678903"));
    // hospedagem->setCidade(Cidade("Rio de Janeiro"));
    // hospedagem->setDescricao(Descricao("oi,meu nome eh ronaldo"));
    // hospedagem->setNota(Nota("10"));
    // hospedagem->setPais(Pais("Brasil"));
    // hospedagem->getCidade();
    // hospedagem->getCodigo();
    // hospedagem->getDescricao();
    // hospedagem->getNota();
    // hospedagem->getPais();
    // string codigo, string cidade, string pais, string nota, string descricao
    Hospedagem hospedagem("12345678903", "Rio de Janeiro", "Brasil", "10", "oi,meu nome eh ronaldo");

    Usuario usuario("Cassio Vini", "cassiocvtb@gmail", "aZ#90", "Ingles", "10/Fev", "Sou lindo!");

    cout << usuario.getEmail() << endl;

    return 0;
};

    //---------------------possivel teste pra avaliacao-------------------//
    // Avaliacao *avaliacao;
    // avaliacao->setCodigo(Codigo("12345678903"));
    // avaliacao->setDescricao(Descricao("achei meio chato,me deu vontade de morrer"));
    // avaliacao->setNota(Nota("5"));
    // avaliacao->getCodigo();
    // avaliacao->getDescricao();
    // avaliacao->getNota();
    //-------------------------------------------------------------------//

