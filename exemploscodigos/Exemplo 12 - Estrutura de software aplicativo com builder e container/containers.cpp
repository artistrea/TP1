#include "containers.h"

ContainerUsuario* ContainerUsuario::instancia = nullptr;

//------------------------------------------------------------------------------------
// Implementações de métodos de classe container.

ContainerUsuario* ContainerUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}

bool ContainerUsuario::incluir(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCPF().getValor() == usuario.getCPF().getValor()){
            return false;
        }
    }
    container.push_back(usuario);                               // Incluir objeto.
    return true;
}


bool ContainerUsuario::remover(CPF cpf){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCPF().getValor() == cpf.getValor()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerUsuario::pesquisar(Usuario* usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCPF().getValor() == usuario->getCPF().getValor()){
            usuario->setNome(elemento->getNome());              // Copiar dados do objeto localizado.
            usuario->setEndereco(elemento->getEndereco());
            usuario->setCEP(elemento->getCEP());
            usuario->setSenha(elemento->getSenha());

            return true;
        }
    }
    return false;
}

bool ContainerUsuario::atualizar(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCPF().getValor() == usuario.getCPF().getValor()){
            elemento->setNome(usuario.getNome());
            elemento->setEndereco(usuario.getEndereco());
            elemento->setCEP(usuario.getCEP());
            elemento->setSenha(usuario.getSenha());
            return true;
        }
    }
    return false;
}
