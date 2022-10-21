# Exemplos de controladoras de apresentação.

# Controladoras integrantes de módulos da camada de apresentação.

# Importar módulos.

import curses
import dominios
import entidades
import interfaces

# ---------------------------------------------------------

class CntrApresentacaoControle(interfaces.IApresentacaoControle):

    # Método construtor.

    def __init__(self, cntr):
        self.__cntr = cntr                              # Identificador do prestador de serviço.
        self.__matricula = dominios.Matricula()
        
    # Métodos para solicitar serviços.

    def executar(self):
        
        tela = curses.initscr()                         # Inicializar curses.

        while(True):

            tela.clear()                                # Limpar tela.

            # Apresentar opções para seleção.

            tela.addstr(0, 0,'Relação de opções de serviço:')
            tela.addstr(1, 0,'1 - Autenticar')
            tela.addstr(2, 0,'2 - Cadastrar usuário')
            tela.addstr(3, 0,'3 - Serviços financeiros')
            tela.addstr(4, 0,'4 - Retornar')
            tela.addstr(5, 0,'Selecione a opção de serviço: ')

            selecao = tela.getch() - 48                 # # Ler opção selecionada e converter código ASCII.

            if (selecao == 1):                          # Solicitar serviço de autenticação.
                
                resultado = self.__cntr.autenticar(self.__matricula)
                
                if (resultado):

                    while(True):

                        tela.clear()                    # Limpar tela.

                        # Apresentar opções para seleção.
    
                        tela.addstr(0, 0,'Relação de opções de serviço:')
                        tela.addstr(1, 0,'1 - Serviços de usuário')
                        tela.addstr(2, 0,'2 - Serviços financeiros')
                        tela.addstr(3, 0,'3 - Retornar')
                        tela.addstr(4, 0,'Selecione a opção de serviço: ')

                        selecao = tela.getch() - 48     # Ler opção selecionada e converter código ASCII.

                        if (selecao == 1):              # Solicitar serviços de usuário.
                            
                            pass                        # Falta inserir código necessário.
                    
                        if (selecao == 2):              # Solicitar serviços financeiros.
                            
                            pass                        # Falta inserir código necessário.

                        if (selecao == 3):              # Retornar.
                            
                            break                       # Falta inserir código necessário.
                    
            if (selecao == 2):                          # Solicitar serviço de cadastramento de usuário.
                
                pass                                    # Falta inserir código necessário.

            if (selecao == 3):                          # Solicitar serviços financeiros.
                
                pass                                    # Falta inserir código necessário.

            if (selecao == 4):                          # Retornar.
                break
                
        curses.endwin()                                 # Encerrar curses.
            
# ---------------------------------------------------------

class CntrApresentacaoAutenticacao(interfaces.IApresentacaoAutenticacao):

    # Método construtor.
    
    def __init__(self, cntr):
        self.__cntr = cntr                              # Identificador do prestador de serviço.

    # Métodos para solicitar serviços.

    def autenticar(self, matricula):

        senha = dominios.Senha()
        
        tela = curses.initscr()                         # Inicializar curses.
        
        while(True):

            tela.clear()                                # Limpar tela.

            try:
                tela.addstr(0, 0,'Digite matricula :')  # Solicitar e ler matrícula.
                valor = tela.getstr()
                matricula.set_valor(int(valor))     
                tela.addstr(1, 0,'Digite a senha   :')  # Solicitar e ler senha.
                valor = tela.getstr()
                senha.set_valor(int(valor))            
                break
            except:
                tela.addstr(2, 0,'Valor informado com formato incorreto')
                tela.refresh()

        curses.endwin()                                 # Encerrar curses.
        
        return self.__cntr.autenticar(matricula, senha) # Solicitar serviço e retornar resultado.
