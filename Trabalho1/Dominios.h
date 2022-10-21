#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <ctype.h>
#include <string>
#include <regex>
#include <unordered_set>


using namespace std;


/// \brief Domínio pai.
/// Base para os outros domínios.
class Dominio {
    // Matrícula: 211038208

    protected:
        string valor;
/// Método que verifica se a string introduzida está conforme as especificações para cada domínio
        virtual void validar(string) = 0;
    public:
/// @param valor uma string qualquer
///
/// inicializa o Dominio com o valor passado
        Dominio(const string&);
        virtual ~Dominio(){};

/// @param valor uma string qualquer
///
/// Chama uma função de validação e, caso a entrada seja válida, o valor é armazenado
        void setValor(const string&);

/// @return valor
        string getValor() const;
};

inline string Dominio::getValor() const {
    // Matrícula: 211038208

    return valor;
}


/// \brief Domínio Nome 
///
/// Possui uma função validar. Se o nome (tipo string) passado para a função for válido, o nome é armazenado. Caso contrário, ocorre o lançamento de uma exceção.
///
/// **Regras para o nome ser aceito**:
/// 1. Até 30 caracteres
/// 2. Formato: Prenome Sobrenome
/// 3. Não pode ter dois ou mais espaços em branco
/// 4. Não pode terminar ou começar com espaço em branco
/// 5. Caracteres podem ser letras do alfabeto sem acento, ou espaço em branco
/// 6. As letras iniciais do prenome e sobrenome devem ser maiúsculas
///
/// **Exemplos de nomes válidos**:
/// - Cassio Vinicius
/// - Joaquim Silva
/// - Dom Quixote
/// - Princesa Jujuba

class Nome : public Dominio {
    // Matricula: 211036141

    protected:
/// @throw invalid_argument se não for valido
        void validar(string);
    public:
/// Constrói o Domínio Nome, validando o dado inserido
        Nome(const string&);
};


/// \brief Domínio Nota 
///
/// Possui uma função validar. Se a nota (tipo string) passada para a função for válida, a nota é 
/// armazenada. Caso contrário, ocorre o lançamento de uma exceção.
///
/// **Regras para a nota ser aceita**:
/// 1. A nota deve ser um número entre 0 e 10
class Nota : public Dominio {
    // Matricula: 211036141

    protected:
        static const regex PADRAO_ACEITO;  ///< Regex com o padrão usado para verificar validade da nota
/// @throw invalid_argument se não for valido
        void validar(string valor);
    public:
/// Constrói o Domínio Nota e valida o dado inserido
        Nota(const string&);
};

/// \brief Domínio Idioma
///
/// É importante salientar que não são aceitos acentos. Logo, caso esteja presente algum acento 
/// no valor passado, será lançada uma exceção!
///
/// Possui uma função validar. Se o idioma (tipo string) passado para a função for válido, 
/// o idioma é armazenado. Caso contrário, ocorre o lançamento de uma exceção.
class Idioma : public Dominio {
    // Matricula: 211036141

    protected:
/// @throw invalid_argument se não for valido
        void validar(string);
    public:
/// Constrói o Domínio Idioma e valida o dado inserido
        Idioma(const string&);
/// **Os idiomas presentes no array de POSSIVEIS_VALORES são aceitos pela função validar**
        static const unordered_set<string> POSSIVEIS_VALORES;

};

/// \brief Domínio Data
///
/// Possui uma função validar. Se a data (tipo string) passada para a função for válida, 
/// a data é armazenada. Caso contrário, ocorre o lançamento de uma exceção.
///
/// O formato da data considerado válido: **dia/Mes**
///
/// **Formato dos dias**:
/// Números entre 01 - 31. Número menor que 10 deve ser acompanhado por um zero.
///
/// **Formato dos meses**:
/// - Jan
/// - Fev
/// - Mar
/// - Abr
/// - Mai
/// - Jun
/// - Jul
/// - Aag
/// - Set
/// - Out
/// - Nov
/// - Dez
///
/// A função validar não leva em consideração anos bissextos
///
/// **Observações**:
/// - O mês de Fev vai até o dia 29
/// - Os meses: Abr, Jun, Set, Nov vão até o dia 30
/// - Os meses: Jan, Mar, Mai, Jul, Ago, Out, Dez vão até o dia 31

class Data : public Dominio {
    // Matricula: 211036141

    protected:
        static const regex PADRAO_ACEITO;
/// @throw invalid_argument se não for valido
        void validar(string);
    public:
/// Constrói o Domínio Data e valida o dado inserido
        Data(const string&);
};


/// \brief Domínio Codigo
///
/// Código indentificador.
/// 
/// **Regras para o codigo ser aceito**:
/// 1. está de acordo com o algoritmo de Luhn
/// 2. tem 11 dígitos.

class Codigo : public Dominio {
    // Matricula: 211026495
    protected:
/// Tamanho permitido para código.  
        static const int TAMANHO_CODIGO = 11;
/// Verifica se o código inserido é valido
/// 
/// @throw invalid_argument código não é valido, por último dígito ou tamanho
        void validar(string);
    public:
/// Constrói o Domínio Código e valida o dado inserido
        Codigo(const string&);
};

/// \brief Domínio Cidade
/// 
/// **Regra para a cidade ser aceita**:
/// Estar presente em POSSIVEIS_VALORES
class Cidade : public Dominio {
    // Matrícula: 211038208

    protected:
/// @throw invalid_argument se não for valido
        void validar(string);
    public:
        
        static const unordered_set<string> POSSIVEIS_VALORES; /**< Únicas cidades aceitas para validação da string inserida */
/// Constrói o Domínio Cidade e valida o dado inserido
        Cidade(const string&);

};


/// \brief Domínio Email
///
/// **Regra para a descrição ser aceita**:
/// 1. Nome de parte-local é composto por até 64 caracteres.
/// 2. Caractere pode ser letra (A-Z ou a-z).
/// 3. Caractere pode ser dígito (0-9).
/// 4. Caractere pode ser hífen (-), sublinhado ( _ ) ou ponto (.) desde que seguido por letra ou dígito.
/// 5. Caractere ponto (.) não pode ser o primeiro caractere no nome.
/// 6. Nome de domínio é composto por lista de termos separados por pontos.
/// 7. Ponto (.) não pode ser o primeiro caractere do nome de domíno e não pode ocorrer em sequência.
/// 8. Cada termo é composto por até 63 carateres.
/// 9. Caractere no termo pode ser letra (A-Z ou a-z).
/// 10. Caractere no termo pode ser dígito (0-9).
/// 11. Caractere no termo pode ser hífen (-) desde que não seja o primeiro ou o último caractere.

class Email : public Dominio {
    // Matrícula: 211038208
    
    protected:
    /// Constante regex que garante que a string inserida seja um email válido
        static const regex PADRAO_ACEITO;
/// @throw invalid_argument se não for valido
        void validar(string);
    public:
/// Constrói o Domínio Email e valida o dado inserido
        Email(const string&);


};

/// \brief Senha do usuário
/// 
/// **Regra para a senha ser aceita**:
/// Senha deve ter 5 caracteres, dentre eles, deve ter, no mínimo:
/// 1. Um caracter especial [!#$%&]
/// 2. Um numero [0-9]
/// 3. Uma letra [a-zA-Z]

class Senha : public Dominio {
    // Matrícula: 211038208

    protected:
    /// Constante regex que garante que a string inserida seja uma senha válida
        static const regex PADRAO_ACEITO;
/// @throw invalid_argument se não for valido
        void validar(string);
    public:
/// Constrói o Domínio Senha e valida o dado inserido
        Senha(const string&);
};

/// \brief Domínio Descricao de usuário, hospedagem ou avaliação
///
/// **Regra para a descrição ser aceita**:
/// 1. Tem de 0 a 40 caracteres
/// 2. Não há espaços em branco seguidos
/// 3. Não há caracteres de pontuação (. , ; : ? ! -) em sequência
class Descricao : public Dominio {
        // Matricula: 211026495
    protected:
/// Constante regex que garante que a string inserida não possui pontuação em sequência
        static const regex PADRAO_NAO_ACEITO;
        static const int MAXIMO_CARACTERES;
/// @throw invalid_argument se não for valido
        void validar(string);

/// @throw invalid_argument quando a descrição possui mais de 40 caracteres ou pontuação em sequência
    public:
/// Constrói o Domínio Descricao e valida o dado inserido
        Descricao(const string&);
};

/// \brief Dominio Pais escolhido para hospedagem.
///
/// **Regra para o país ser aceito**:
/// Estar entre os países em POSSIVEIS_VALORES
class Pais : public Dominio {
    // Matricula: 211026495

    protected:
/// Objeto com únicos possíveis países que são aceitos na classe
        static const unordered_set<string> POSSIVEIS_VALORES;

/// @throw invalid_argument país não está entre os aceitos
        void validar(string);

    public:
/// Constrói o Domínio Pais e valida o dado inserido
        Pais(const string&);
};

#endif // DOMINIOS_H_INCLUDED
