#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

/* -----------------------------------------------------------------------
// EstruturaSUCESSO de c�digo para declara��o de classe dom�nio.
// Substituir Dominio por nome da classe.
// Substituir Tipo.

class Dominio {
    private:
        Tipo valor;                      // Atributo para armazenar valor.
        void validar(Tipo);              // M�todo para validar valor.
    public:
        void setValor(Tipo);             // M�todo para atribuir valor.
        Tipo getValor() const;           // M�todo para recuperar valor.
};

inline Tipo Dominio::getValor() const{
    return valor;
}

----------------------------------------------------------------------- */

// -----------------------------------------------------------------------
// Exemplo de declara��o de classe dom�nio e implementa��o de m�todo.

class Codigo {
private:
        static const int LIMITE = 25;       // Declara��o para evitar n�meros m�gicos.
        int valor;
        void validar(int);
public:
        void setValor(int);
        int getValor() const;
};

inline int Codigo::getValor() const{
    return valor;
}

// -----------------------------------------------------------------------
// Exemplo de declara��o de classe dom�nio e implementa��o de m�todo.

class Prioridade {
    private:
        static const int INVALIDO = 0;      // Declara��o para evitar n�meros m�gicos.
        int valor;
        void validar(int);
    public:
        void setValor(int);
        int getValor() const;
};

inline int Prioridade::getValor() const{
    return valor;
}

#endif // DOMINIOS_H_INCLUDED
