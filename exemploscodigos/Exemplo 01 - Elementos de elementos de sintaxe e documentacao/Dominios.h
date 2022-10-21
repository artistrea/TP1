// Exemplo de documentação de classe usando ferramenta Doxygen.

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

///
/// Padr&atilde;o para representa&ccedil;&atilde;o de cliente.
///
/// Regras de formato:
///
/// - C&oacute;digo &eacute; v&aacute;lido caso <u>menor</u> ou igual a 5.
///

class CodigoCliente {
    private:
            static const int LIMITE  = 5;           // Constante.
            static const int DEFAULT = 0;           // Constante.
            int valor;
            bool validar(int);
    public:

///
/// Inicializa o objeto com o c&oacute;digo 0.
///

            CodigoCliente();

///
/// Inicializa o objeto com o c&oacute;digo informado caso o mesmo seja seja v&aacute;lido.
///
/// Inicializa o objeto com o c&oacute;digo 0 caso o c&oacute;digo informado seja inv&aacute;lido.
///
/// @param valor C&oacute;digo.
///

            CodigoCliente(int);

///
/// Armazena c&oacute;digo.
///
/// @param valor C&oacute;digo.
///
/// @return
///
/// - Retorna true  caso c&oacute;digo tenha sido armazenado.
/// - Retorna false caso c&oacute;digo n&atilde;o tenha sido armazenado por ser inv&aacute;lido.
///

            bool setValor(int);

///
/// Retorna c&oacute;digo.
///
/// @return C&oacute;digo.
///

            int getValor();
};

inline int CodigoCliente::getValor(){               // Metodo inline.
    return valor;
}

///
/// Padr&atilde;o para representa&ccedil;&atilde;o de produto.
///
/// Regras de formato:
///
/// - C&oacute;digo &eacute; v&aacute;lido caso menor ou igual a 100.
///

class CodigoProduto {
    private:
            static const int LIMITE  = 100;         // Constante.
            static int quantidade;                  // Atributo de classe.
            int valor;
            void validar(int);
    public:

///
/// Inicializa o objeto com o c&oacute;digo informado caso o mesmo seja v&aacute;lido.
///
/// Lan&ccedil;a exce&ccedil;&atilde;o caso o c&oacute&digo informado seja inv&aacute;lido.
///
/// @param valor C&oacute;digo.
///
/// @throw invalid_argument
///

            CodigoProduto(int);

///
/// Armazena o c&oacute;digo informado caso o mesmo seja v&aacute;lido.
///
/// Lan&ccedil;a exce&ccedil;&atilde;o caso o c&oacute;digo informado seja inv&aacute;lido.
///
/// @param valor C&oacute;digo.
///
/// @throw invalid_argument
///

            void setValor(int);

///
/// Retorna c&oacute;digo.
///
/// @return C&oacute;digo.
///

            int getValor() const;

            static int getQuantidade();

///<
///< Retorna quantidade de c&oacute;digos.
///<
///< @return Quantidade de c&oacute;digos.
///<

};

inline int CodigoProduto::getValor() const{         // Metodo inline e const.
    return valor;
}

inline int CodigoProduto::getQuantidade(){          // Metodo inline e const.
    return quantidade;
}

//-----------------------------------------------------------------------
// Exemplo de heranca simples (hierarquia com dois níveis hierárquicos).

class Codigo {
    protected:
            int valor;
    public:
            int getValor();
};

inline int Codigo::getValor(){
    return valor;
}

class CodigoServico:public Codigo {
    private:
            static const int LIMITE  = 100;
            static const int DEFAULT = 0;
            void validar(int);
    public:
            void setValor(int);
};

//-----------------------------------------------------------------------
// Exemplo de heranca simples (hierarquia com dois níveis hierárquicos).

class Conta{
    private:
            static const float SALDO_INICIAL;
    protected:
            float saldo;
    public:
            Conta();
            void  depositar(float);
            float getSaldo();
};

inline void Conta::depositar(float valor){
    saldo += valor;
}

inline float Conta::getSaldo(){
    return saldo;
}

class ContaConvencional:public Conta {
    public:
            bool sacar(float);
};

class ContaEspecial:public Conta {
    private:
            static const float LIMITE;
    public:
            bool sacar(float);
};

//-----------------------------------------------------------------------
// Exemplos de métodos construtores em hierarquia com herança simples.

class PessoaFisica {
    private:
            static const int DEFAULT = 100;
            int matricula;
    public:
            PessoaFisica();
            PessoaFisica(int);
            int getMatricula();
};

class Engenheiro:public PessoaFisica {
    private:
            static const int DEFAULT = 1000;
            int registro;
    public:
            Engenheiro();
            Engenheiro(int, int);
            int getRegistro();
};

inline PessoaFisica::PessoaFisica(){
    this->matricula = DEFAULT;
}

inline PessoaFisica::PessoaFisica(int matricula){
    this->matricula = matricula;
}

inline int PessoaFisica::getMatricula(){
    return matricula;
}

inline Engenheiro::Engenheiro(){
    registro = DEFAULT;
}

inline Engenheiro::Engenheiro(int registro, int matricula):PessoaFisica(matricula){
    this->registro = registro;
}

inline int Engenheiro::getRegistro(){
    return registro;
}

//-----------------------------------------------------------------------
// Exemplo de herança múltipla em hierarquia com métodos construtores.

class Liquido {
    private:
            float densidade;
    public:
            Liquido(float);
            float getDensidade();
};

class BemProducao {
    private:
            float valor;
    public:
            BemProducao(float);
            float getValor();
};

class Petroleo:public Liquido, public BemProducao {
    private:
            string origem;
    public:
            Petroleo(string, float, float);
            string getOrigem();

};

inline float Liquido::getDensidade(){
    return densidade;
}

inline float BemProducao::getValor(){
    return valor;
}

inline string Petroleo::getOrigem(){
    return origem;
}

inline Liquido::Liquido(float densidade){
    this->densidade = densidade;
}

inline BemProducao::BemProducao(float valor){
    this->valor = valor;
}

inline Petroleo::Petroleo(string origem, float densidade, float valor):Liquido(densidade), BemProducao(valor){
    this->origem = origem;
}

//-----------------------------------------------------------------------
// Exemplo de hieraquia de classes com sobrecarga (method overloading).

class Cliente {
    private:
            int telefone;
            string email;
    public:
            void setContato(int);
            void setContato(string);
            void getContato(int*, string*);
};

inline void Cliente::setContato(int telefone){
    this->telefone = telefone;
}

inline void Cliente::setContato(string email){
    this->email = email;
}

inline void Cliente::getContato(int *telefone, string* email){
    *telefone = this->telefone;
    *email = this->email;
    return;
}

//-----------------------------------------------------------------------
// Exemplo de hieraquia de classes com sobrescrita (method overriding).

class ContaCorrente {
protected:
        float saldo;
public:
        ContaCorrente();
        void depositar(float);
        bool sacar(float);
        float getSaldo();
};

class ContaCorrenteEspecial:public ContaCorrente {
private:
        static const float LIMITE;
public:
        bool sacar(float);
};

inline ContaCorrente::ContaCorrente(){
    saldo = 0;
}

inline void ContaCorrente::depositar(float valor){
    this->saldo += valor;
}

inline float ContaCorrente::getSaldo(){
    return saldo;
}

//-----------------------------------------------------------------------
// Exemplo de classe com método virtual.

class ContaCliente {
    protected:
            float saldo;
    public:
            ContaCliente();
            virtual void depositar(float);
            virtual bool sacar(float);
            virtual float getSaldo();
};

class ContaClienteEspecial:public ContaCliente {
    private:
            static const float LIMITE;
    public:
            bool sacar(float);
};

class ControladoraTransacao {
    public:
        bool transferir(ContaCliente*, ContaCliente*, float);
};

inline ContaCliente::ContaCliente(){
    saldo = 0;
}

inline void ContaCliente::depositar(float valor){
    this->saldo += valor;
}

inline float ContaCliente::getSaldo(){
    return saldo;
}

#endif // DOMINIOS_H_INCLUDED
