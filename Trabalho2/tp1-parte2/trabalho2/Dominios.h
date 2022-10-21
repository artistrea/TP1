#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <ctype.h>
#include <string>
#include <regex>
#include <unordered_set>


using namespace std;


/// \brief Dom�nio pai.
/// Base para os outros dom�nios.
class Dominio {
        // Matr�cula: 211038208

protected:
        string valor;
        /// M�todo que verifica se a string introduzida est� conforme as especifica��es para cada dom�nio
        virtual void validar(string) = 0;
public:
        /// @param valor uma string qualquer
        ///
        /// inicializa o Dominio com o valor passado
        Dominio(const string&);
        virtual ~Dominio() {};

        /// @param valor uma string qualquer
        ///
        /// Chama uma fun��o de valida��o e, caso a entrada seja v�lida, o valor � armazenado
        void setValor(const string&);

        /// @return valor
        string getValor() const;
};

inline string Dominio::getValor() const {
        // Matr�cula: 211038208

        return valor;
}


/// \brief Dom�nio Nome
///
/// Possui uma fun��o validar. Se o nome (tipo string) passado para a fun��o for v�lido, o nome � armazenado. Caso contr�rio, ocorre o lan�amento de uma exce��o.
///
/// **Regras para o nome ser aceito**:
/// 1. At� 30 caracteres
/// 2. Formato: Prenome Sobrenome
/// 3. N�o pode ter dois ou mais espa�os em branco
/// 4. N�o pode terminar ou come�ar com espa�o em branco
/// 5. Caracteres podem ser letras do alfabeto sem acento, ou espa�o em branco
/// 6. As letras iniciais do prenome e sobrenome devem ser mai�sculas
///
/// **Exemplos de nomes v�lidos**:
/// - Cassio Vinicius
/// - Joaquim Silva
/// - Dom Quixote
/// - Princesa Jujuba

class Nome : public Dominio {
        // Matricula: 211036141

protected:
        /// @throw invalid_argument se n�o for valido
        void validar(string);
public:
        /// Constr�i o Dom�nio Nome, validando o dado inserido
        Nome(const string&);
};


/// \brief Dom�nio Nota
///
/// Possui uma fun��o validar. Se a nota (tipo string) passada para a fun��o for v�lida, a nota �
/// armazenada. Caso contr�rio, ocorre o lan�amento de uma exce��o.
///
/// **Regras para a nota ser aceita**:
/// 1. A nota deve ser um n�mero entre 0 e 10
class Nota : public Dominio {
        // Matricula: 211036141

protected:
        static const regex PADRAO_ACEITO;  ///< Regex com o padr�o usado para verificar validade da nota
        /// @throw invalid_argument se n�o for valido
        void validar(string valor);
public:
        /// Constr�i o Dom�nio Nota e valida o dado inserido
        Nota(const string&);
};

/// \brief Dom�nio Idioma
///
/// � importante salientar que n�o s�o aceitos acentos. Logo, caso esteja presente algum acento
/// no valor passado, ser� lan�ada uma exce��o!
///
/// Possui uma fun��o validar. Se o idioma (tipo string) passado para a fun��o for v�lido,
/// o idioma � armazenado. Caso contr�rio, ocorre o lan�amento de uma exce��o.
class Idioma : public Dominio {
        // Matricula: 211036141

protected:
        /// @throw invalid_argument se n�o for valido
        void validar(string);
public:
        /// Constr�i o Dom�nio Idioma e valida o dado inserido
        Idioma(const string&);
        /// **Os idiomas presentes no array de POSSIVEIS_VALORES s�o aceitos pela fun��o validar**
        static const unordered_set<string> POSSIVEIS_VALORES;

};

/// \brief Dom�nio Data
///
/// Possui uma fun��o validar. Se a data (tipo string) passada para a fun��o for v�lida,
/// a data � armazenada. Caso contr�rio, ocorre o lan�amento de uma exce��o.
///
/// O formato da data considerado v�lido: **dia/Mes**
///
/// **Formato dos dias**:
/// N�meros entre 01 - 31. N�mero menor que 10 deve ser acompanhado por um zero.
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
/// A fun��o validar n�o leva em considera��o anos bissextos
///
/// **Observa��es**:
/// - O m�s de Fev vai at� o dia 29
/// - Os meses: Abr, Jun, Set, Nov v�o at� o dia 30
/// - Os meses: Jan, Mar, Mai, Jul, Ago, Out, Dez v�o at� o dia 31

class Data : public Dominio {
        // Matricula: 211036141

protected:
        static const regex PADRAO_ACEITO;
        /// @throw invalid_argument se n�o for valido
        void validar(string);
public:
        /// Constr�i o Dom�nio Data e valida o dado inserido
        Data(const string&);
};


/// \brief Dom�nio Codigo
///
/// C�digo indentificador.
///
/// **Regras para o codigo ser aceito**:
/// 1. est� de acordo com o algoritmo de Luhn
/// 2. tem 11 d�gitos.

class Codigo : public Dominio {
        // Matricula: 211026495
protected:
        /// Tamanho permitido para c�digo.
        static const int TAMANHO_CODIGO = 11;
        /// Verifica se o c�digo inserido � valido
        ///
        /// @throw invalid_argument c�digo n�o � valido, por �ltimo d�gito ou tamanho
        void validar(string);
public:
        /// Constr�i o Dom�nio C�digo e valida o dado inserido
        Codigo(const string&);
};

/// \brief Dom�nio Cidade
///
/// **Regra para a cidade ser aceita**:
/// Estar presente em POSSIVEIS_VALORES
class Cidade : public Dominio {
        // Matr�cula: 211038208

protected:
        /// @throw invalid_argument se n�o for valido
        void validar(string);
public:

        static const unordered_set<string> POSSIVEIS_VALORES; /**< �nicas cidades aceitas para valida��o da string inserida */
        /// Constr�i o Dom�nio Cidade e valida o dado inserido
        Cidade(const string&);

};


/// \brief Dom�nio Email
///
/// **Regra para a descri��o ser aceita**:
/// 1. Nome de parte-local � composto por at� 64 caracteres.
/// 2. Caractere pode ser letra (A-Z ou a-z).
/// 3. Caractere pode ser d�gito (0-9).
/// 4. Caractere pode ser h�fen (-), sublinhado ( _ ) ou ponto (.) desde que seguido por letra ou d�gito.
/// 5. Caractere ponto (.) n�o pode ser o primeiro caractere no nome.
/// 6. Nome de dom�nio � composto por lista de termos separados por pontos.
/// 7. Ponto (.) n�o pode ser o primeiro caractere do nome de dom�no e n�o pode ocorrer em sequ�ncia.
/// 8. Cada termo � composto por at� 63 carateres.
/// 9. Caractere no termo pode ser letra (A-Z ou a-z).
/// 10. Caractere no termo pode ser d�gito (0-9).
/// 11. Caractere no termo pode ser h�fen (-) desde que n�o seja o primeiro ou o �ltimo caractere.

class Email : public Dominio {
        // Matr�cula: 211038208

protected:
        /// Constante regex que garante que a string inserida seja um email v�lido
        static const regex PADRAO_ACEITO;
        /// @throw invalid_argument se n�o for valido
        void validar(string);
public:
        /// Constr�i o Dom�nio Email e valida o dado inserido
        Email(const string&);


};

/// \brief Senha do usu�rio
///
/// **Regra para a senha ser aceita**:
/// Senha deve ter 5 caracteres, dentre eles, deve ter, no m�nimo:
/// 1. Um caracter especial [!#$%&]
/// 2. Um numero [0-9]
/// 3. Uma letra [a-zA-Z]

class Senha : public Dominio {
        // Matr�cula: 211038208

protected:
        /// Constante regex que garante que a string inserida seja uma senha v�lida
        static const regex PADRAO_ACEITO;
        /// @throw invalid_argument se n�o for valido
        void validar(string);
public:
        /// Constr�i o Dom�nio Senha e valida o dado inserido
        Senha(const string&);
};

/// \brief Dom�nio Descricao de usu�rio, hospedagem ou avalia��o
///
/// **Regra para a descri��o ser aceita**:
/// 1. Tem de 0 a 40 caracteres
/// 2. N�o h� espa�os em branco seguidos
/// 3. N�o h� caracteres de pontua��o (. , ; : ? ! -) em sequ�ncia
class Descricao : public Dominio {
        // Matricula: 211026495
protected:
        /// Constante regex que garante que a string inserida n�o possui pontua��o em sequ�ncia
        static const regex PADRAO_NAO_ACEITO;
        static const int MAXIMO_CARACTERES;
        /// @throw invalid_argument se n�o for valido
        void validar(string);

        /// @throw invalid_argument quando a descri��o possui mais de 40 caracteres ou pontua��o em sequ�ncia
public:
        /// Constr�i o Dom�nio Descricao e valida o dado inserido
        Descricao(const string&);
};

/// \brief Dominio Pais escolhido para hospedagem.
///
/// **Regra para o pa�s ser aceito**:
/// Estar entre os pa�ses em POSSIVEIS_VALORES
class Pais : public Dominio {
        // Matricula: 211026495

protected:
        /// Objeto com �nicos poss�veis pa�ses que s�o aceitos na classe
        static const unordered_set<string> POSSIVEIS_VALORES;

        /// @throw invalid_argument pa�s n�o est� entre os aceitos
        void validar(string);

public:
        /// Constr�i o Dom�nio Pais e valida o dado inserido
        Pais(const string&);
};

#endif // DOMINIOS_H_INCLUDED

