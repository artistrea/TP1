# Sistema financeiro.

# Programa usa stub para prover serviço de autenticação.

# Importar módulos.

import dominios
import controladoras_apresentacao
import stubs

# ---------------------------------------------------------

def main():

    # Instanciar e interligar controladoras a stubs.
    
    cntrA = stubs.StubServicoAutenticacao()
    cntrB = controladoras_apresentacao.CntrApresentacaoAutenticacao(cntrA)
    cntrC = controladoras_apresentacao.CntrApresentacaoControle(cntrB)

    # Executar serviço.

    cntrC.executar()

if __name__ == "__main__":
    main()
