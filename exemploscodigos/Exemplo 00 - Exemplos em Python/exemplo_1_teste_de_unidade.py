# Exemplo de execução de testes de unidade.

# Exemplo visa ilustrar possível abordagem para solicitar execuções dos testes de unidade.

# Importar módulos.

import testes_dominios
import testes_entidades

# ---------------------------------------------------------

teste = testes_dominios.TUCodigo()

resultado = teste.executar()

if (resultado == True):
    print('TUCodigo executado com sucesso.')
else:
    print('TUCodigo executado com falha.')

# ---------------------------------------------------------

teste = testes_dominios.TUPrioridade()

resultado = teste.executar()

if (resultado == True):
    print('TUPrioridade executado com sucesso.')
else:
    print('TUPrioridade executado com falha.')

# ---------------------------------------------------------

teste = testes_entidades.TUProjeto()

resultado = teste.executar()

if (resultado == True):
    print('TUProjeto executado com sucesso.')
else:
    print('TUProjeto executado com falha.')

