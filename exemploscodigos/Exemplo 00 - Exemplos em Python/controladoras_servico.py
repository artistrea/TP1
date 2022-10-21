# Exemplos de controladoras de serviço.

# Controladoras integrantes de módulos da camada de serviço.

# Importar módulos.

import interfaces
import dominios
import entidades
import persistencia

# ---------------------------------------------------------

class CntrServicoAutenticacao(interfaces.IServicoAutenticacao):

    # Métodos para solicitar serviços.
    
    def autenticar(self, matricula, senha):

        # Instanciar classe para amazenar conteúdo recuperado do banco de dados.

        aluno = entidades.Aluno(dominios.Nome(), dominios.Matricula(), dominios.Senha(), dominios.Telefone(), dominios.Matricula())

        # Instanciar comando para recuperar dados de aluno.

        comando = persistencia.ComandoRecuperarAluno(matricula)

        # Executar comando e comparar senha recuperada com senha informada.     
    
        if(comando.executar()):
            if(comando.recuperar(aluno)):              
                if(int(aluno.get_senha().get_valor()) == senha.get_valor()):
                    return True
        return False

# ---------------------------------------------------------
