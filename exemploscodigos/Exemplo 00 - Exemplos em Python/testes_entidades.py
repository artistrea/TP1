# Exemplos de testes de unidade de classes que representam entidades.

# Importar módulos.

import dominios
import entidades

# ---------------------------------------------------------

class TUProjeto:

    # Atributos de classe.

    __VALOR_DEFAULT           = 0
    __VALOR_VALIDO_CODIGO     = 100
    __VALOR_VALIDO_PRIORIDADE = 200

    # Método construtor.

    def __init__(self):
        self.__estado = True
    
    # Método para testar cenário de sucesso.

    def __cenario_sucesso(self):

        unidade_em_teste = entidades.Projeto(dominios.Codigo(TUProjeto.__VALOR_DEFAULT), dominios.Prioridade(TUProjeto.__VALOR_DEFAULT))

        if(unidade_em_teste.get_codigo().get_valor() != TUProjeto.__VALOR_DEFAULT):
            self.__estado = False
            return
        
        if(unidade_em_teste.get_prioridade().get_valor() != TUProjeto.__VALOR_DEFAULT):
            self.__estado = False
            return

        codigo = dominios.Codigo(self.__VALOR_VALIDO_CODIGO)
        unidade_em_teste.set_codigo(codigo)

        if(unidade_em_teste.get_codigo().get_valor() != TUProjeto.__VALOR_VALIDO_CODIGO):
            self.__estado = False
            return
        
        prioridade = dominios.Prioridade(self.__VALOR_VALIDO_PRIORIDADE)
        unidade_em_teste.set_prioridade(prioridade)

        if(unidade_em_teste.get_prioridade().get_valor() != TUProjeto.__VALOR_VALIDO_PRIORIDADE):
            self.__estado = False
            return

    # Método para executar teste.

    def executar(self):
        self.__cenario_sucesso()
        return self.__estado

class TUAluno:
    # Atributos de classe.

    __VALOR_DEFAULT           = 0
    __VALOR_VALIDO_MATRICULA  = 100
    __VALOR_VALIDO_SENHA      = 200

    # Método construtor.

    def __init__(self):
        self.__estado = True
    
    # Método para testar cenário de sucesso.

    def __cenario_sucesso(self):

        unidade_em_teste = entidades.Aluno(dominios.Matricula(TUAluno.__VALOR_DEFAULT), dominios.Senha(TUAluno.__VALOR_DEFAULT))

        if(unidade_em_teste.get_matricula().get_valor() != TUAluno.__VALOR_DEFAULT):
            self.__estado = False
            return
        
        if(unidade_em_teste.get_senha().get_valor() != TUAluno.__VALOR_DEFAULT):
            self.__estado = False
            return

        matricula = dominios.Matricula(TUAluno.__VALOR_VALIDO_MATRICULA)
        unidade_em_teste.set_matricula(matricula)

        if(unidade_em_teste.get_matricula().get_valor() != TUAluno.__VALOR_VALIDO_MATRICULA):
            self.__estado = False
            return
        
        senha = dominios.Senha(TUAluno.__VALOR_VALIDO_SENHA)
        unidade_em_teste.set_senha(senha)

        if(unidade_em_teste.get_senha().get_valor() != TUAluno.__VALOR_VALIDO_SENHA):
            self.__estado = False
            return

    # Método para executar teste.

    def executar(self):
        self.__cenario_sucesso()
        return self.__estado

