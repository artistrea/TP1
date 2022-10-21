// Exemplo de uso de respositório construído com SQLite.

#include <cstdlib>
#include <iostream>

#include "UnidadeControladoras.h"

/* --------------------------------------------------------------

Exemplos de usuários e senhas cadastradas em teste.db.

Matrícula : 12345
Senha     : 54321

Matrícula : 13579
Senha     : 12345

-------------------------------------------------------------- */

using namespace std;

int main(int argc, char *argv[])
{
    // Instanciar e executar autenticação.

    CntrAutenticacao cntrA;
    cntrA.executar();

    // Instanciar e executar navegação.

    CntrNavegacao cntrB;
    cntrB.executar();

    system("PAUSE");

    return EXIT_SUCCESS;
}
