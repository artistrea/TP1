//---------------------------------------------------------------------------

#ifndef UnidadeEntidadesH
#define UnidadeEntidadesH
//---------------------------------------------------------------------------

#include "UnidadeTiposBasicos.h"

//---------------------------------------------------------------------------
// Declaração da classe Usuario.

class Usuario {
private:
        Nome nome;
        Matricula matricula;
        Senha senha;
        Telefone telefone;
public:
        Usuario(){}
        Usuario(Nome, Matricula, Senha, Telefone);
        Nome getNome() const;
        void setNome(const Nome&);
        Matricula getMatricula() const;
        void setMatricula(const Matricula&);
        Senha getSenha() const;
        void setSenha(const Senha&);
        Telefone getTelefone() const;
        void setTelefone(const Telefone&);
};

//---------------------------------------------------------------------------
// Declaração da classe Aluno.

class Aluno:public Usuario {
private:
        Matricula matriculaOrientador;
public:
        Aluno(){}
        Aluno(Nome, Matricula, Senha, Telefone, Matricula);
        Matricula getMatriculaOrientador() const;
        void setMatriculaOrientador(const Matricula&);
};

//---------------------------------------------------------------------------
// Declaração da classe Disciplina.

class Disciplina {
private:
        Nome nome;
        CodigoDisciplina codigo;
public:
        Disciplina(){}
        Disciplina(Nome, CodigoDisciplina);
        Nome getNome() const;
        void setNome(const Nome&);
        CodigoDisciplina getCodigo() const;
        void setCodigoDisciplina(const CodigoDisciplina&);
};

//---------------------------------------------------------------------------
//Implementações de métodos.

inline Nome Usuario::getNome() const {
        return nome;
}

inline Matricula Usuario::getMatricula() const {
        return matricula;
}

inline Senha Usuario::getSenha() const {
        return senha;
}

inline Telefone Usuario::getTelefone() const {
        return telefone;
}

//---------------------------------------------------------------------------

inline Matricula Aluno::getMatriculaOrientador() const {
        return matriculaOrientador;
}

inline Nome Disciplina::getNome() const {
        return nome;
}

inline CodigoDisciplina Disciplina::getCodigo() const {
        return codigo;
}

//---------------------------------------------------------------------------

inline Usuario::Usuario(Nome nome, Matricula matricula,
                Senha senha, Telefone telefone): nome(nome),
                matricula(matricula), senha(senha), telefone(telefone) {
}

inline void Usuario::setNome(const Nome& nome) {
        this->nome = nome;
}

inline void Usuario::setMatricula(const Matricula& matricula) {
        this->matricula = matricula;
}

inline void Usuario::setSenha(const Senha& senha) {
        this->senha = senha;
}

inline void Usuario::setTelefone(const Telefone& telefone){
        this->telefone = telefone;
}

//---------------------------------------------------------------------------

inline Aluno::Aluno(Nome nome, Matricula matricula, Senha senha,
                Telefone telefone, Matricula matriculaOrientador):
        Usuario(nome, matricula, senha, telefone),
                matriculaOrientador(matriculaOrientador) {

}

inline void Aluno::setMatriculaOrientador(const Matricula& matriculaOrientador) {
        this->matriculaOrientador = matriculaOrientador;
}

//---------------------------------------------------------------------------

inline Disciplina::Disciplina(Nome nome, CodigoDisciplina codigo):
        nome(nome), codigo(codigo) {
}

inline void Disciplina::setNome(const Nome& nome) {
        this->nome = nome;
}

inline void Disciplina::setCodigoDisciplina(const CodigoDisciplina& codigo) {
        this->codigo = codigo;
}

#endif
