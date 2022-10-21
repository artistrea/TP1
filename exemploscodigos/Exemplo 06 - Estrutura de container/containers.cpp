#include "containers.h"

// ----------------------------------------------------------------------
// Implementações de métodos de classe container.

bool ContainerUsuario::incluir(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == usuario.getMatricula().getValor()){
            return false;
        }
    }
    container.push_back(usuario);                               // Incluir objeto.
    return true;
}

bool ContainerUsuario::remover(Matricula matricula){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == matricula.getValor()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::pesquisar(Usuario* usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == usuario->getMatricula().getValor()){
            usuario->setMatricula(elemento->getMatricula());    // Copiar atributos de objeto localizado.
            usuario->setSenha(elemento->getSenha());
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::atualizar(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getMatricula().getValor() == usuario.getMatricula().getValor()){
            elemento->setMatricula(usuario.getMatricula());     // Copiar atributos para objeto localizado.
            elemento->setSenha(usuario.getSenha());
            return true;
        }
    }
    return false;
}


