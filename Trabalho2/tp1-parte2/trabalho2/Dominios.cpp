#include "Dominios.h"
#include <iostream>

using namespace std;


void Dominio::setValor(const string& valor) {
    // Matr�cula: 211038208

    validar(valor);
    this->valor = valor;
}

Dominio::Dominio(const string& valor) {
    this->valor = valor;
}


Nome::Nome(const string& valor) : Dominio(valor) { validar(valor); };

Nota::Nota(const string& valor) : Dominio(valor) { validar(valor); };

Idioma::Idioma(const string& valor) : Dominio(valor) { validar(valor); };

Data::Data(const string& valor) : Dominio(valor) { validar(valor); };

Codigo::Codigo(const string& valor) : Dominio(valor) { validar(valor); };

Cidade::Cidade(const string& valor) : Dominio(valor) { validar(valor); };

Email::Email(const string& valor) : Dominio(valor) { validar(valor); };

Senha::Senha(const string& valor) : Dominio(valor) { validar(valor); };

Descricao::Descricao(const string& valor) : Dominio(valor) { validar(valor); };

Pais::Pais(const string& valor) : Dominio(valor) { validar(valor); };

void Nome::validar(string nome) {
    // Matricula: 211036141

    int numEspacoBranco = 0;
    int numLetrasMaisculas = 0;
    int nomeTamanho = nome.length();
    bool espacoBranco = false;
    bool primeiraLetraNome = isupper(nome[0]);

    if (!primeiraLetraNome || nomeTamanho > 30) {
        throw invalid_argument("Formato inadequado para nome.");
    }
    else if (nome[nomeTamanho - 1] == ' ') {
        throw invalid_argument("Formato inadequado para nome.");
    }

    for (int i = 0; i < nomeTamanho; ++i) {
        if (!isalpha(nome[i]) && (nome[i] != ' ')) {
            throw invalid_argument("Formato inadequado para nome.");
        }
        else if (nome[i] == ' ' && espacoBranco) {
            throw invalid_argument("Formato inadequado para nome.");
        }
        else if (espacoBranco && islower(nome[i])) {
            throw invalid_argument("Formato inadequado para nome.");
        }
        else if (isupper(nome[i])) {
            numLetrasMaisculas += 1;
            espacoBranco = false;
        }
        else if (nome[i] == ' ') {
            numEspacoBranco += 1;
            espacoBranco = true;
        }
        else {
            espacoBranco = false;
        }
    }

    if (numLetrasMaisculas != 2 || numEspacoBranco != 1) {
        throw invalid_argument("Formato inadequado para nome.");
    }
}


void Nota::validar(string valor) {
    // Matricula: 211036141

    if (!regex_match(valor, PADRAO_ACEITO)) {
        throw invalid_argument("A nota deve ser um valor valido.");
    }
}


void Idioma::validar(string valor) {
    // Matricula: 211036141

    if (POSSIVEIS_VALORES.find(valor) == POSSIVEIS_VALORES.end()) {
        throw invalid_argument("Idioma indisponivel");
    }
}


void Data::validar(string valor) {
    // Matricula: 211036141

    if ((!regex_match(valor, PADRAO_ACEITO))) {
        throw invalid_argument("Data invalida");
    }
}


void Codigo::validar(string valor) {
    // Matricula: 211026495

    if (!(valor.size() == TAMANHO_CODIGO)) {
        throw invalid_argument("Tamanho do codigo invalido.");
    }

    int soma = 0;
    bool ehpar = false;

    for (int i = TAMANHO_CODIGO - 1; i >= 0; i--) {
        int d = valor[i] - '0';

        if (ehpar) {
            d = d * 2;
        }
        soma += d / 10;
        soma += d % 10;
        ehpar = !ehpar;
    }
    if (soma % 10 != 0) {
        throw invalid_argument("Ultimo digito incorreto.");
    }
}


void Cidade::validar(string valor) {
    // Matr�cula: 211038208

    if (POSSIVEIS_VALORES.find(valor) == POSSIVEIS_VALORES.end()) {
        throw invalid_argument("Cidade Invalida");
    }
}


void Email::validar(string valor) {
    // Matr�cula: 211038208

    if (!regex_match(valor, PADRAO_ACEITO)) {
        throw invalid_argument("Email invalido");
    }
}


void Senha::validar(string valor) {
    // Matr�cula: 211038208

    if (!regex_match(valor, PADRAO_ACEITO)) {
        throw invalid_argument("Senha invalida");
    }
}

void Descricao::validar(string valor) {
    // Matricula: 211026495

    if ((int)valor.size() > MAXIMO_CARACTERES) {
        throw invalid_argument("Descricao deve possuir de 0 a 40 caracteres.");
    }
    if (regex_search(valor, PADRAO_NAO_ACEITO)) {
        throw invalid_argument("Descricao invalida.");
    }
}

void Pais::validar(string valor) {
    // Matr�cula: 211026495

    if (POSSIVEIS_VALORES.find(valor) == POSSIVEIS_VALORES.end()) {
        throw invalid_argument("Pais Invalido");
    }
}
