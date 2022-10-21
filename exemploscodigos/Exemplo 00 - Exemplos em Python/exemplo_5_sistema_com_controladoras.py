# Sistema financeiro.

# Exemplo visa ilustrar possível abordagem para execução do sistema.

# Importar módulos.

import dominios
import controladoras_apresentacao
import controladoras_servico

# ---------------------------------------------------------

def main():

    # Instanciar e interligar controladoras.
    
    cntrA = controladoras_servico.CntrServicoAutenticacao()
    cntrB = controladoras_apresentacao.CntrApresentacaoAutenticacao(cntrA)
    cntrC = controladoras_apresentacao.CntrApresentacaoControle(cntrB)

    # Executar serviço.

    cntrC.executar()

if __name__ == "__main__":
    main()
