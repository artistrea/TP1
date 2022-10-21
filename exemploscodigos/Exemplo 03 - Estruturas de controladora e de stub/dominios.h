#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

// ---------------------------------------------------------------------------------
// Declaração de classe domínio e implementação de método.

class Matricula {
private:
    int valor;
    void validar(int);
public:
    const static int MATRICULA_INVALIDA = 12345;
    void setValor(int);
    int getValor() const;
};

inline int Matricula::getValor() const {
    return valor;
}

// ---------------------------------------------------------------------------------
// Declaração de classe domínio e implementação de método.

class Senha {
private:
    int valor;
    void validar(int);
public:
    const static int SENHA_INVALIDA = 12345;
    void setValor(int);
    int getValor() const;
};

inline int Senha::getValor() const {
    return valor;
}

#endif // DOMINIOS_H_INCLUDED
