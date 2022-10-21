# Exemplos de interfaces.

# Importar módulos.

from abc import ABC, abstractmethod

import dominios
import entidades

# Interfaces da camada de apresentacao.

# ---------------------------------------------------------

class IApresentacaoControle(ABC):

    # Método construtor.

    @abstractmethod
    def __init__(self, cntr):
        pass

    # Métodos para solicitar serviços.

    @abstractmethod   
    def executar(self):
        pass

# ---------------------------------------------------------

class IApresentacaoAutenticacao(ABC):

    # Método construtor.

    @abstractmethod
    def __init__(self, cntr):
        pass

    # Métodos para solicitar serviços.

    @abstractmethod   
    def autenticar(self, matricula):
        pass

# Interfaces da camada de serviço.

# -------------------------------------------------------

class IServicoAutenticacao(ABC):

    # Métodos para solicitar serviços.

    @abstractmethod 

    def autenticar(self, matricula, senha):
        pass
