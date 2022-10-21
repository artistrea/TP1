#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

using namespace std;

//----------------------------------------------------------------------------------------
// Declaração de classe container.
//
// Declaração adota padrão de projeto Singleton.

class ContainerUsuario{
    private:
        list<Usuario> container;                        // Lista de usuários.
        static ContainerUsuario *instancia;             // Ponteiro para instância da classe.
        ContainerUsuario(){};                           // Construtor.
    public:
        static  ContainerUsuario* getInstancia();       // Método para instanciar classe.
        bool incluir(Usuario);                          // Métodos responsáveis por prestar serviços.
        bool remover(CPF);
        bool pesquisar(Usuario*);
        bool atualizar(Usuario);
};

#endif // CONTROLADORAS_H_INCLUDED
