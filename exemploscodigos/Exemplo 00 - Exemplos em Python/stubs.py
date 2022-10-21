# Exemplos de stubs.

# Importar módulos.

import interfaces

# ---------------------------------------------------------

class StubServicoAutenticacao(interfaces.IServicoAutenticacao):

    # Atributos de classe.

    __TRIGGER = 100                 # Valor a ser usado como gatilho.

    # Métodos para solicitar serviços.

    def autenticar(self, matricula, senha):
        if(matricula.get_valor() == StubServicoAutenticacao.__TRIGGER):
            return True
        else:
            return False

