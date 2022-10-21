//---------------------------------------------------------------------------

#include "UnidadeTiposBasicos.h"

//---------------------------------------------------------------------------
// Implementações de métodos da classe Matricula.

Matricula::Matricula(string matricula){
        validar(matricula);
        valor = matricula;
}

void Matricula::validar(string matricula){
        if (matricula.size() != 5)
                throw invalid_argument("Matricula formato incorreto.");
        for (unsigned int i = 0; i < matricula.size(); i++) {
            if (!isdigit(matricula.at(i)))
                    throw invalid_argument("Matricula formato incorreto.");
        }
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe Senha.

Senha::Senha(string senha){
        validar(senha);
        valor = senha;
}

void Senha::validar(string senha){
        if (senha.size() != 5)
                throw invalid_argument("Senha formato incorreto.");
        for (unsigned int i = 0; i < senha.size(); i++) {
            if (!isdigit(senha.at(i)))
                    throw invalid_argument("Senha formato incorreto.");
        }
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe Nome.

Nome::Nome(string nome){
        validar(nome);
        valor = nome;
}

void Nome::validar(string nome){
        if (nome.size() == 0 || nome.size() > 20)
                throw invalid_argument("Nome formato incorreto.");
        for (unsigned int i = 0; i < nome.size(); i++) {
            if (!isspace(nome.at(i)) &&
                !isupper(nome.at(i)) &&
                !islower(nome.at(i)))
                    throw invalid_argument("Nome formato incorreto.");
        }
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe Telefone.

Telefone::Telefone(string telefone){
        validar(telefone);
        valor = telefone;
}

void Telefone::validar(string telefone){
        if (telefone.size() != 7)
                throw invalid_argument("Telefone formato incorreto.");
        for (unsigned int i = 0; i < telefone.size(); i++) {
            if (!isdigit(telefone.at(i)))
                    throw invalid_argument("Telefone formato incorreto.");
        }
}

//---------------------------------------------------------------------------
// Implementações de métodos da classe CodigoDisciplina.

CodigoDisciplina::CodigoDisciplina(string codigo){
        validar(codigo);
        valor = codigo;
}

void CodigoDisciplina::validar(string codigo){
        if (codigo.size() != 5)
                throw invalid_argument("Senha formato incorreto.");
        for (unsigned int i = 0; i < codigo.size(); i++) {
            if (!isdigit(codigo.at(i)))
                    throw invalid_argument("Senha formato incorreto.");
        }
}

