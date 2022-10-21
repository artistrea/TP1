#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

#include <string>

using namespace std;

// -----------------------------------------------------
// Declaração de classe entidade.

class Usuario {
private:
    Matricula matricula;
    Senha senha;
public:
    void setMatricula(const Matricula&);
    Matricula getMatricula() const;
    void setSenha(const Senha&);
    Senha getSenha() const;
};

// Implementações de métodos.

inline void Usuario::setMatricula(const Matricula &matricula){
    this->matricula = matricula;
}

inline Matricula Usuario::getMatricula() const {
    return matricula;
}

inline void Usuario::setSenha(const Senha &senha){
    this->senha = senha;
}

inline Senha Usuario::getSenha()const {
    return senha;
}

#endif // ENTIDADES_H_INCLUDED
