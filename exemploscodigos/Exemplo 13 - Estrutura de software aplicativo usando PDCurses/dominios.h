#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include<stdexcept>

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações de classes domínio e implementações de métodos.

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

//--------------------------------------------------------------------------------------------

class CPF:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Senha:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Codigo:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Numero:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Nome:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Endereco:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class CEP:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Agencia:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

//--------------------------------------------------------------------------------------------

class Banco:public Dominio {
    private:
        static const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

#endif // DOMINIOS_H_INCLUDED
