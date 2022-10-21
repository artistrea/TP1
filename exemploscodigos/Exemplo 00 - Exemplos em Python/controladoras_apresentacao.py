# Exemplos de controladoras de apresentação.

# Controladoras integrantes de módulos da camada de apresentação.

# Importar módulos.

import dominios
import entidades
import interfaces

# ---------------------------------------------------------

class CntrApresentacaoControle(interfaces.IApresentacaoControle):

    # Método construtor.

    def __init__(self, cntr):
        self.__cntr = cntr                                              # Identificador do prestador de serviço.
        self.__matricula = dominios.Matricula()
        
    # Métodos para solicitar serviços.

    def executar(self):

        while(True):

            # Apresentar opções para seleção.

            print('Relação de opções de serviço:')
            print('1 - Autenticar')
            print('2 - Cadastrar usuário')
            print('3 - Serviços financeiros')
            print('4 - Retornar')

            # Ler opção selecionada.
    
            selecao = int(input('Selecione a opção de serviço: '))

            if (selecao == 1):                                          # Solicitar serviço de autenticação.
                    
                resultado = self.__cntr.autenticar(self.__matricula)    
                    
                if (resultado):

                    while(True):

                        # Apresentar opções para seleção.

                        print('Relação de opções de serviço:')
                        print('1 - Serviços de usuário')
                        print('2 - Serviços financeiros')
                        print('3 - Retornar')

                        # Ler opção selecionada.
    
                        selecao = int(input('Selecione a opção de serviço: '))

                        if (selecao == 1):                              # Solicitar serviços de usuário.
                            
                            pass                                        # Falta inserir código necessário.
                    
                        if (selecao == 2):                              # Solicitar serviços financeiros.
                            
                            pass                                        # Falta inserir código necessário.

                        if (selecao == 3):                              # Retornar.
                            
                            break                                       # Falta inserir código necessário.
                    
            if (selecao == 2):                                          # Solicitar serviço de cadastramento de usuário.
                
                pass                                                    # Falta inserir código necessário

            if (selecao == 3):                                          # Solicitar serviços financeiros.
                
                pass                                                    # Falta inserir código necessário

            if (selecao == 4):                                          # Retornar.
                break
           
# ---------------------------------------------------------

class CntrApresentacaoAutenticacao(interfaces.IApresentacaoAutenticacao):

    # Método construtor.
    
    def __init__(self, cntr):
        self.__cntr = cntr                                              # Identificador do prestador de serviço.

    # Métodos para solicitar serviços.

    def autenticar(self, matricula):

        senha = dominios.Senha()
        
        while(True):   
            try:
                matricula.set_valor(int(input('Digite matricula :')))   # Solicitar e ler matrícula.
                senha.set_valor(int(input('Digite senha     :')))       # Solicitar e ler senha.
                break
            except:
                print('Valor informado com formato incorreto')

        return self.__cntr.autenticar(matricula, senha)                 # Solicitar serviço e retornar resultado.
