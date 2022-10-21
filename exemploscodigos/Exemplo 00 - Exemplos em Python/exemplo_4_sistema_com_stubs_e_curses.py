# Sistema financeiro.

# Exemplo visa ilustrar possível abordagem para execução do sistema.

# Programa usa stub para prover serviço de autenticação.

# Executar esse programa a partir de terminal pois o mesmo usa curses.

# Importar módulos.

import dominios
import controladoras_apresentacao_curses
import stubs

# ---------------------------------------------------------

def main():

    # Instanciar e interligar controladoras a stubs.
    
    cntrA = stubs.StubServicoAutenticacao()
    cntrB = controladoras_apresentacao_curses.CntrApresentacaoAutenticacao(cntrA)
    cntrC = controladoras_apresentacao_curses.CntrApresentacaoControle(cntrB)

    # Executar serviço.

    cntrC.executar()

if __name__ == "__main__":
    main()
