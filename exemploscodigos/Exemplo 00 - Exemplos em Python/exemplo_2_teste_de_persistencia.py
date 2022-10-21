# Exemplo de teste de comandos para acesso a banco de dados.

# Importar módulos.

import sqlite3
import dominios
import entidades
import persistencia

def main():

    # --------------------------------------------------------------
    # Teste do comando para recuperação de objeto no banco de dados.
    
    matricula = dominios.Matricula(12345)

    # Instanciar comando.
    
    comando = persistencia.ComandoRecuperarAluno(matricula)

    # Instanciar classe para amazenar conteúdo recuperado do banco de dados.
    
    aluno = entidades.Aluno(dominios.Nome(), dominios.Matricula(), dominios.Senha(), dominios.Telefone(), dominios.Matricula())

    # Executar comando e informar resultado da execução do comando.

    if(comando.executar()):
        if(comando.recuperar(aluno)):          
            print ('Aluno recuperado:')
            print ('Nome                    = ', aluno.get_nome().get_valor())
            print ('Matr                    = ', aluno.get_matricula().get_valor())
            print ('Senha                   = ', aluno.get_senha().get_valor())
            print ('Telefone                = ', aluno.get_telefone().get_valor())
            print ('Matrícula do orientador = ', aluno.get_orientador().get_valor())
        else:
            print('Aluno não recuperado')
    else:
            print('Falha na execução do comando de recuperação')

    # --------------------------------------------------------------
    # Teste do comando para edição de objeto no banco de dados.

    aluno.set_nome(dominios.Nome('Fernando'))

    # Instanciar comando.

    comando = persistencia.ComandoEditarAluno(aluno)

    # Executar comando e informar resultado da execução do comando.

    if(comando.executar()):
        print('Edição executada com sucesso')
    else:
        print('Falha na execução do comando de edição')

    # --------------------------------------------------------------
    # Teste do comando para remoção de objeto no banco de dados.

    # Instanciar comando.

    comando = persistencia.ComandoRemoverAluno(dominios.Matricula(12345))

    # Executar comando e informar resultado da execução do comando.

    if(comando.executar()):
        print('Remoção executada com sucesso')
    else:
        print('Falha na execução do comando de remoção')

    # --------------------------------------------------------------
    # Teste do comando para inclusão de objeto no banco de dados.

    aluno = entidades.Aluno(dominios.Nome('Jose'), dominios.Matricula(12345), dominios.Senha(54321), dominios.Telefone(111111), dominios.Matricula(22222))

    # Instanciar comando.
    
    comando = persistencia.ComandoIncluirAluno(aluno)

    # Executar comando e informar resultado da execução do comando.

    if(comando.executar()):
        print('Inclusão executada com sucesso')
    else:
        print('Falha na execução do comando de inclusão')

    # --------------------------------------------------------------
    # Apresentar conteúdo do banco de dados.

    conn = sqlite3.connect('testedb')\
    
    print ("Estado atual do banco de dados:")

    cursor = conn.execute("SELECT nome, matricula, senha, telefone, matriculaorientador from alunos")
    
    for row in cursor:
       print ("Nome                    = ", row[0])
       print ("Matr                    = ", row[1])
       print ("Senha                   = ", row[2])
       print ("Telefone                = ", row[3])
       print ("Matricula do orientador = ", row[4], "\n")

    conn.close()
    
if __name__ == "__main__":
    main()
