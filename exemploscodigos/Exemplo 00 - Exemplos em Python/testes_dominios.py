# Exemplos de testes de unidade de classes que representam domínios.

# Importar módulo.

import dominios

# ---------------------------------------------------------

class TUCodigo:

    # Atributos de classe

    __VALOR_VALIDO   = 100
    __VALOR_INVALIDO = 101 

    # Método construtor.

    def __init__(self):
        self.__estado = True

    # Métodos para testar cenários de sucesso.

    def __cenario_sucesso_construtor(self):
        try:
            unidade_em_teste = dominios.Codigo(TUCodigo.__VALOR_VALIDO)
            if(unidade_em_teste.get_valor() != TUCodigo.__VALOR_VALIDO):
                self.__estado = False
        except:
            self.__estado = False
        return
    
    def __cenario_sucesso_acesso(self):
        try:
            unidade_em_teste = dominios.Codigo()
            unidade_em_teste.set_valor(TUCodigo.__VALOR_VALIDO)
            if(unidade_em_teste.get_valor() != TUCodigo.__VALOR_VALIDO):
                self.__estado = False
        except:
            self.__estado = False
        return

    # Métodos para testar cenários de falha.

    def __cenario_falha_construtor(self):
        try:
            unidade_em_teste = dominios.Codigo(TUCodigo.__VALOR_INVALIDO)
            self.__estado = False
            return
        except:
            return

    def __cenario_falha_acesso(self):
        try:
            unidade_em_teste = dominios.Codigo()
            unidade_em_teste.set_valor(TUCodigo.__VALOR_INVALIDO)
            self.__estado = False
        except:
            if(unidade_em_teste.get_valor() == TUCodigo.__VALOR_INVALIDO):
                self.__estado = False
        return

    # Método para executar teste.

    def executar(self):
        self.__cenario_sucesso_construtor()
        self.__cenario_sucesso_acesso()
        self.__cenario_falha_construtor()
        self.__cenario_falha_acesso()
        return self.__estado

# ---------------------------------------------------------

class TUPrioridade:

    # Atributos de classe

    __VALOR_VALIDO   = 200
    __VALOR_INVALIDO = 201

    # Método construtor.

    def __init__(self):
        self.__estado = True

    # Métodos para testar cenários de sucesso.

    def __cenario_sucesso_construtor(self):
        try:
            unidade_em_teste = dominios.Prioridade(TUPrioridade.__VALOR_VALIDO)
            if(unidade_em_teste.get_valor() != TUPrioridade.__VALOR_VALIDO):
                self.__estado = False
        except:
            self.__estado = False
        return
    
    def __cenario_sucesso_acesso(self):
        try:
            unidade_em_teste = dominios.Prioridade()
            unidade_em_teste.set_valor(TUPrioridade.__VALOR_VALIDO)
            if(unidade_em_teste.get_valor() != TUPrioridade.__VALOR_VALIDO):
                self.__estado = False
        except:
            self.__estado = False
        return

    # Métodos para testar cenários de falha.

    def __cenario_falha_construtor(self):
        try:
            unidade_em_teste = dominios.Prioridade(TUPrioridade.__VALOR_INVALIDO)
            self.__estado = False
            return
        except:
            return

    def __cenario_falha_acesso(self):
        try:
            unidade_em_teste = dominios.Prioridade()
            unidade_em_teste.set_valor(TUPrioridade.__VALOR_INVALIDO)
            self.__estado = False
        except:
            if(unidade_em_teste.get_valor() == TUPrioridade.__VALOR_INVALIDO):
                self.__estado = False
        return

    # Método para executar teste.

    def executar(self):
        self.__cenario_sucesso_construtor()
        self.__cenario_sucesso_acesso()
        self.__cenario_falha_construtor()
        self.__cenario_falha_acesso()
        return self.__estado
