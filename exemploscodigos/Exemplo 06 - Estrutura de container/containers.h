#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

using namespace std;

// ----------------------------------------------------------------------
// Declaração de classe container.

class ContainerUsuario{
private:
    list<Usuario> container;
public:
    bool incluir(Usuario);
    bool remover(Matricula);
    bool pesquisar(Usuario*);
    bool atualizar(Usuario);
};

#endif // CONTROLADORAS_H_INCLUDED
