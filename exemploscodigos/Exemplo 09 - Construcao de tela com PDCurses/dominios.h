#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

//-----------------------------------------------------------------------------------
// Declaração de classe Matricula.

class Matricula {
private:
    int valor;
    const static int MATRICULA_INVALIDA = 12345;
    void validar(int);
public:
    void setValor(int);
    int getValor() const;
};

inline int Matricula::getValor() const {
    return valor;
}

//-----------------------------------------------------------------------------------
// Declaração da classe Senha.

class Senha {
private:
    int valor;
    const static int SENHA_INVALIDA = 12345;
    void validar(int);
public:
    void setValor(int);
    int getValor() const;
};

inline int Senha::getValor() const {
    return valor;
}


#endif // DOMINIOS_H_INCLUDED
