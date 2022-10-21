# Exemplos de classes representando domínios.

# Exemplos visam ilustrar possível estrutura para classes que representam domínios.

# Métodos para validação implementados de modo simplificado ou faltando implementação.

# ---------------------------------------------------------

class Codigo:
    
    # Atributos de classe.
    
    __VALOR_LIMITE  = 100

    # Método construtor.

    def __init__(self, valor = 0):
        self.__validar(valor)
        self.__valor = valor

    # Método para validar formato.

    def __validar(self, valor):                         # Implementação simplificada a título de exemplo.
        if (valor > Codigo.__VALOR_LIMITE):             
            raise Exception('Argumento invalido.')      # Lançar exceção em caso de valor inválido.

    # Métodos para acessar atributos.

    def set_valor(self, valor):
        self.__validar(valor)
        self.__valor = valor
    
    def get_valor(self):
        return self.__valor
        
# ---------------------------------------------------------

class Prioridade:
    
    # Atributos de classe

    __VALOR_LIMITE = 200

    # Método construtor.

    def __init__(self, valor = 0):
        self.__validar(valor)
        self.__valor = valor

    # Método para validar formato.

    def __validar(self, valor):                         # Implementação simplificada a título de exemplo.
        if (valor > Prioridade.__VALOR_LIMITE):         
            raise Exception('Argumento invalido.')      # Lançar exceção em caso de valor inválido.

    # Métodos para acessar atributos.
        
    def set_valor(self, valor):
        self.__validar(valor)
        self.__valor = valor
    
    def get_valor(self):
        return self.__valor

# ---------------------------------------------------------

class Nome:
    
    # Método construtor.
    
    def __init__(self, valor = ''):
        self.__validar(valor)
        self.__valor = valor

    # Método para validar formato.

    def __validar(self, valor):
        pass                                            # Falta implementar código do método.

    # Métodos para acessar atributos.
        
    def set_valor(self, valor):
        self.__validar(valor)
        self.__valor = valor
    
    def get_valor(self):
        return self.__valor
    
# ---------------------------------------------------------

class Matricula:
    
    # Método construtor.

    def __init__(self, valor = 0):
        self.__validar(valor)
        self.__valor = valor

    # Método para validar formato.

    def __validar(self, valor):
        pass                                            # Falta implementar código do método.

    # Métodos para acessar atributos.
        
    def set_valor(self, valor):
        self.__validar(valor)
        self.__valor = valor
    
    def get_valor(self):
        return self.__valor

# ---------------------------------------------------------

class Senha:
    
    # Método construtor.

    def __init__(self, valor = 0):
        self.__validar(valor)
        self.__valor = valor

    # Método para validar formato.

    def __validar(self, valor):
        pass                                            # Falta implementar código do método.

    # Métodos para acessar atributos.
        
    def set_valor(self, valor):
        self.__validar(valor)
        self.__valor = valor
    
    def get_valor(self):
        return self.__valor

# ---------------------------------------------------------

class Telefone:
    
    # Método construtor.

    def __init__(self, valor = 0):
        self.__validar(valor)
        self.__valor = valor

    # Método para validar formato.

    def __validar(self, valor):
        pass                                            # Falta implementar código do método.

    # Métodos para acessar atributos.
        
    def set_valor(self, valor):
        self.__validar(valor)
        self.__valor = valor
    
    def get_valor(self):
        return self.__valor


