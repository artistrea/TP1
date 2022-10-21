#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "Dominios.h"
#include "Entidades.h"

#include <math.h>
#include <string>

#include <unordered_map>
#include <vector>

using namespace std;

// ----------------------------------------------------------------------
// Declaracao de classe container.
template<class Entidade>
class Container {
private:
    unordered_map<string, Entidade> container;
    string getPKValue(Entidade*);
public:
    vector<Entidade>  todos();
    bool           adicionar(Entidade);
    bool           remover(string);
    Entidade          pesquisar(string);
    bool           atualizar(Entidade*);
};


template <class Entidade>
vector<Entidade> Container<Entidade>::todos() {
    vector<Entidade> todos;

    for (const pair<string, Entidade>& PK_Entidade : container) {
        todos.push_back(PK_Entidade.second);
    }

    return todos;
}


template <class Entidade>
inline bool Container<Entidade>::adicionar(Entidade row) {
    return container.insert(make_pair(getPKValue(&row), row)).second;
}

template <class Entidade>
bool Container<Entidade>::remover(string pk) {
    typename unordered_map<string, Entidade>::iterator it = container.find(pk);

    if (it == container.end()) {
        return false;
    }

    container.erase(it);
    return true;
}

template <class Entidade>
inline Entidade Container<Entidade>::pesquisar(string pk) {
    if (container.find(pk) == container.end()) {
        throw invalid_argument("not found");
    }
    return (container.find(pk))->second;
}
// 
template <class Entidade>
bool Container<Entidade>::atualizar(Entidade* row) {
    typename unordered_map<string, Entidade>::iterator it = container.find(getPKValue(row));

    if (it != container.end()) {
        it->second = *row;
        return true;
    }

    return false;
}

template <>
inline string Container<Usuario>::getPKValue(Usuario* usr) {
    return usr->getEmail();
}


class ContainerUsuario : public Container<Usuario> {

};


template <>
inline string Container<Avaliacao>::getPKValue(Avaliacao* av) {
    return av->getCodigo();
}

class ContainerAvaliacao : public Container<Avaliacao> {
private:
    static int inicio_do_proximo_codigo;
};


template <>
inline string Container<Hospedagem>::getPKValue(Hospedagem* hsp) {
    return hsp->getCodigo();
}

class ContainerHospedagem : public Container<Hospedagem> {
private:
    static int inicio_do_proximo_codigo;
};

#endif // CONTROLADORAS_H_INCLUDED
