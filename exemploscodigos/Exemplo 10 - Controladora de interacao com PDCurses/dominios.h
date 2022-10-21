#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include<stdexcept>

using namespace std;

//------------------------------------------------------------------------
// Declaração de classe domínio e implementações de métodos.

class Dominio {
    private:
        string valor;
    protected:
        virtual void validar(string) = 0;
    public:
        void setValor(string);
        string getValor() const;
};

inline void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

inline string Dominio::getValor() const {
    return valor;
}

//------------------------------------------------------------------------
// Declaração de classe domínio.

class CPF:public Dominio {
    private:
        const long unsigned int TAMANHO_MAXIMO = 10;
    protected:
        void validar(string);
};

//------------------------------------------------------------------------
// Declaração de classe domínio.

class Senha:public Dominio {
    private:
        const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

#endif // DOMINIOS_H_INCLUDED
