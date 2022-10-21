#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

//---------------------------------------------------------------------------------
// Classe com informação acerca de resultado de comando de acesso ao banco de dados.


//---------------------------------------------------------------------------------
// Classe base da hierarquia de comandos de acesso ao banco de dados.

class ComandoBancoDados {

public:

    // Método para execução do comando.

    virtual void executar() throw(runtime_error) = 0;

    virtual ~ComandoBancoDados(){}
};

//---------------------------------------------------------------------------------
// Comandos para acesso a gerente.

class ComandoIncluirGerente:public ComandoBancoDados {

private:

    Gerente gerente;

public:

    void executar() throw(runtime_error){}
};

class ComandoRemoverGerente:public ComandoBancoDados {

private:

    Matricula matricula;

public:

    void executar() throw(runtime_error){}
};

class ComandoRecuperarGerente:public ComandoBancoDados {

private:

    Matricula matricula;

public:

    void executar() throw(runtime_error){}
};

class ComandoEditarGerente:public ComandoBancoDados {

private:

    Gerente gerente;

public:

    void executar() throw(runtime_error){}
};



#endif // COMANDOS_H_INCLUDED
