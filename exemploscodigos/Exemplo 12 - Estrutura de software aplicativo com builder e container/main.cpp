#include <string.h>
#include <stdexcept>
#include <iostream>

#include "builders.h"
#include "controladorasapresentacao.h"

using namespace std;

int main()
{
    // Instanciar Builder.

    BuilderSistema *builder;
    builder = new BuilderSistema();

    // Construir (build) sistema.

    CntrApresentacaoControle *cntrApresentacaoControle;
    cntrApresentacaoControle = builder->construir();

    // Solicitar serviço de apresentacao.

    cntrApresentacaoControle->executar();

    // Destruir builder.

    delete builder;

    return 0;
}

