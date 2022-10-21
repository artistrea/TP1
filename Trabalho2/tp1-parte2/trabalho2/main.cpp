#include <string.h>
#include <stdexcept>
#include <iostream>

#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "Containers.h"
#include "Modulos.h"

using namespace std;

int main() {

    ModuloCntrlAprs* modCntrlAprs = new ModuloCntrlAprs();
    modCntrlAprs->executar();

    return 0;
}