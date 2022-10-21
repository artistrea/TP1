//---------------------------------------------------------------------------

#ifndef UnidadeTiposBasicosH
#define UnidadeTiposBasicosH
//---------------------------------------------------------------------------

#include <string>
#include <stdexcept>

using namespace std;

//---------------------------------------------------------------------------
// Declaração da classe TipoBasico.

class TipoBasico {
       virtual void validar(string) = 0;
protected:
       string valor;
public:
       TipoBasico(){}
       void setValor(const string&);
       string getValor() const;
};

//---------------------------------------------------------------------------
// Declaração da classe Matricula.

class Matricula:public TipoBasico {
private:
        void validar(string);
public:
        Matricula(){}
        Matricula(string);
};

//---------------------------------------------------------------------------
// Declaração da classe Senha.

class Senha:public TipoBasico {
private:
        void validar(string);
public:
        Senha () {}
        Senha(string);
};

//---------------------------------------------------------------------------
// Declaração da classe Nome.

class Nome:public TipoBasico {
private:
        void validar(string);
public:
        Nome() {}
        Nome(string);
};

//---------------------------------------------------------------------------
// Declaração da classe Telefone.

class Telefone:public TipoBasico {
private:
        void validar(string);
public:
        Telefone() {}
        Telefone(string);
};

//---------------------------------------------------------------------------
//Classe Declaração da classe CodigoDisciplina.

class CodigoDisciplina:public TipoBasico {
private:
        void validar(string);
public:
        CodigoDisciplina () {}
        CodigoDisciplina(string);
};

//---------------------------------------------------------------------------
// Implementações de métodos.

inline void TipoBasico::setValor(const string& valor) {
        validar(valor);
        this->valor = valor;
}

inline string TipoBasico::getValor() const {
       return valor;
}

#endif
