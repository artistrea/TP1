# Exemplos de comandos para acesso a banco de dados SQLite.

# Importar módulos.

import sqlite3
import dominios

# --------------------------------------------------------------

# Estrututura da tabela.
#
# Alunos(nome, matricula, senha, telefone, matriculaorientador)

# --------------------------------------------------------------

class ComandoSQL:

    # Atributos de classe.

    _BANCO_DADOS = "testedb"                # Atributo protegido (protected).

    _comando = ""                           # Atributo protegido (protected).

    _resultado = []                         # Atributo protegido (protected).

    # Método para solicitar serviço.
    
    def executar(self):       
        try:
            conexao = sqlite3.connect(ComandoSQL._BANCO_DADOS)
            cursor = conexao.cursor()
            cursor.execute(ComandoSQL._comando)
            ComandoSQL._resultado = cursor.fetchone()
            conexao.commit()
            conexao.close()
            return True
        except:
            return False

# --------------------------------------------------------------

class ComandoIncluirAluno(ComandoSQL):

    # Método construtor.

    def __init__(self, aluno):
        ComandoSQL._comando = 'INSERT INTO alunos (nome, matricula, senha, telefone, matriculaorientador) VALUES (' + "'" \
                            + str(aluno.get_nome().get_valor())+ "'" + ', ' + "'" \
                            + str(aluno.get_matricula().get_valor()) + "'" + ', ' + "'" \
                            + str(aluno.get_senha().get_valor()) + "'" + ', ' + "'" \
                            + str(aluno.get_telefone().get_valor()) + "'" + ', ' + "'" \
                            + str(aluno.get_orientador().get_valor()) + "'" + ')'
        
# --------------------------------------------------------------

class ComandoRemoverAluno(ComandoSQL):

    # Método construtor.

    def __init__(self, matricula):
        ComandoSQL._comando = 'DELETE FROM alunos WHERE matricula = ' + "'" + str(matricula.get_valor()) + "'"
        
# --------------------------------------------------------------

class ComandoEditarAluno(ComandoSQL):

    # Método construtor.

    def __init__(self, aluno):
        ComandoSQL._comando = 'UPDATE alunos SET nome = ' + "'" \
                            + str(aluno.get_nome().get_valor()) + "'" \
                            + ', senha = ' + "'" + str(aluno.get_senha().get_valor()) + "'" \
                            + ', telefone = ' + "'" + str(aluno.get_telefone().get_valor()) + "'" \
                            + ', matriculaorientador = ' + "'" + str(aluno.get_orientador().get_valor()) + "'" \
                            + ' WHERE matricula = ' + "'" + str(aluno.get_matricula().get_valor()) + "'"

# --------------------------------------------------------------
        
class ComandoRecuperarAluno(ComandoSQL):

    # Método construtor.

    def __init__(self, matricula):
        ComandoSQL._comando = "SELECT * FROM alunos WHERE matricula = " + str(matricula.get_valor())

    # Método para solicitar serviço.

    def recuperar(self, aluno):        
        if (ComandoSQL._resultado != None):    
            aluno.set_nome(dominios.Nome(str(ComandoSQL._resultado[0])))                    # Converte para tipo adequado e armazena em atributo.
            aluno.set_matricula(dominios.Matricula(int(ComandoSQL._resultado[1])))          # Converte para tipo adequado e armazena em atributo.
            aluno.set_senha(dominios.Senha(int(ComandoSQL._resultado[2])))                  # Converte para tipo adequado e armazena em atributo.
            aluno.set_telefone(dominios.Telefone(int(ComandoSQL._resultado[3])))            # Converte para tipo adequado e armazena em atributo.
            aluno.set_orientador(dominios.Matricula(int(ComandoSQL._resultado[4])))         # Converte para tipo adequado e armazena em atributo.
            return True
        return False

# --------------------------------------------------------------
