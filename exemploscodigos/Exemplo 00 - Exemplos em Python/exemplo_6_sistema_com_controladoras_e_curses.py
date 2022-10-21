# Sistema financeiro.

# Exemplo visa ilustrar possível abordagem para execução do sistema.

# Executar esse programa a partir de terminal pois o mesmo usa curses.

# Importar módulos.

import dominios
import controladoras_apresentacao_curses
import controladoras_servico

# ---------------------------------------------------------

def main():

    # Instanciar e interligar controladoras.
    
    cntrA = controladoras_servico.CntrServicoAutenticacao()
    cntrB = controladoras_apresentacao_curses.CntrApresentacaoAutenticacao(cntrA)
    cntrC = controladoras_apresentacao_curses.CntrApresentacaoControle(cntrB)

    # Executar serviço.

    cntrC.executar()

if __name__ == "__main__":
    main()
