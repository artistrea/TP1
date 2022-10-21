# Exemplos de classes representando entidades.

# Exemplos visam ilustrar possível estrutura para classes que representam entidades.

# Importar módulos.

import dominios

# ---------------------------------------------------------

class Projeto:

    # Método construtor.

    def __init__(self, codigo, prioridade):
        self.__codigo = codigo
        self.__prioridade = prioridade

    # Métodos para acessar atributos.

    def set_codigo(self, codigo):
        self.__codigo = codigo

    def set_prioridade(self, prioridade):
        self.__prioridade = prioridade

    def get_codigo(self):
        return self.__codigo

    def get_prioridade(self):
        return self.__prioridade

# ---------------------------------------------------------

class Aluno:
    
    # Método construtor.

    def __init__(self, nome, matricula, senha, telefone, orientador):
        self.__nome = nome
        self.__matricula = matricula
        self.__senha = senha
        self.__telefone = telefone
        self.__orientador = orientador

    # Métodos para acessar atributos.

    def set_nome(self, nome):
        self.__nome = nome

    def set_matricula(self, matricula):
        self.__matricula = matricula

    def set_senha(self, senha):
        self.__senha = senha

    def set_telefone(self, telefone):
        self.__telefone = telefone

    def set_orientador(self, orientador):
        self.__orientador = orientador

    def get_nome(self):
        return self.__nome

    def get_matricula(self):
        return self.__matricula

    def get_senha(self):
        return self.__senha

    def get_telefone(self):
        return self.__telefone

    def get_orientador(self):
        return self.__orientador
    
