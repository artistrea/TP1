// Exemplo de elementos da sintaxe da linguagem e de documentação usando Doxygen.

// Incluir cabeçalhos.

#include <iostream>

#include "Dominios.h"

using namespace std;

int main()
{
    // ------------------------------------------------------------------------
    // Criar objetos e interagir com objetos.

    CodigoCliente a, b(2), c(10);

    cout << "Valor = " << a.getValor() << endl;
    cout << "Valor = " << b.getValor() << endl;
    cout << "Valor = " << c.getValor() << endl;

    if(a.setValor(3))
        cout << "Valor = " << a.getValor() << endl;
    else
        cout << "Valor invalido" << endl;

    if(a.setValor(30))
        cout << "Valor = " << a.getValor() << endl;
    else
        cout << "Valor invalido" << endl;

    // ------------------------------------------------------------------------
    // Criar ponteiros e objetos, interagir com objetos e destruir objetos.

    CodigoCliente *ptra, *ptrb, *ptrc;

    ptra = new CodigoCliente();
    ptrb = new CodigoCliente(2);
    ptrc = new CodigoCliente(10);

    cout << "Valor = " << ptra->getValor() << endl;
    cout << "Valor = " << ptrb->getValor() << endl;
    cout << "Valor = " << ptrc->getValor() << endl;

    if(ptra->setValor(3))
        cout << "Valor = " << ptra->getValor() << endl;
    else
        cout << "Valor invalido" << endl;

    if(ptra->setValor(30))
        cout << "Valor = " << ptra->getValor() << endl;
    else
        cout << "Valor invalido" << endl;

    delete ptra;
    delete ptrb;
    delete ptrc;

    // ------------------------------------------------------------------------
    // Exemplos de códigos com lançamentos e tratamentos de exceções.

    // CodigoProduto x;                                     // Tentativa de criar objeto sem que exista construtor default.
                                                            // Linha comentada por resultar em erro de compilação.

    // CodigoProduto z(200);                                // Tentativa de criar objeto com valor inválido.
                                                            // Linha comentada por resultar em lançamento de exceção.

    CodigoProduto y(50);                                    // Criar objeto com valor válido.

    cout << "Valor = " << y.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        y.setValor(75);                                     // Armazenar valor válido não resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << y.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        y.setValor(200);                                    // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << y.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        y.setValor(200);                                    // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
    }
    catch(...){                                             // Capturar exceção de qualquer classe.
        cout << "Excecao : " << endl;
    }

    cout << "Valor = " << y.getValor() << endl;             // Apresentar valor atual de atributo.

    // ------------------------------------------------------------------------
    // Exemplo de aninhamento blocos de código try-catch.

    try{

        try {
            y.setValor(200);                                // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
        }
        catch(...){                                         // Capturar exceção de qualquer classe.
            cout << "Tratamento parcial." << endl;
            throw;                                          // Relançamento de exceção.
        }
    }
    catch (invalid_argument &exp){                          // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    // ------------------------------------------------------------------------
    // Exemplo de uso de método estático.

    cout << "Quantidade de produtos = " << CodigoProduto::getQuantidade() << endl;

    CodigoProduto z(75);                                    // Criar novo objeto da classe CodigoProduto.

    cout << "Quantidade de produtos = " << CodigoProduto::getQuantidade() << endl;

    // ------------------------------------------------------------------------
    // Exemplo de uso de matriz de objetos.

    CodigoCliente matrizCodigoCliente[2];                                           // Criar matriz de objetos sem inicialização.

    cout << "Primeiro elemento da matriz de codigos de clientes: " << matrizCodigoCliente[0].getValor() << endl;
    cout << "Segundo  elemento da matriz de codigos de clientes: " << matrizCodigoCliente[1].getValor() << endl;

    CodigoProduto matrizCodigoProduto[2] = {CodigoProduto(80), CodigoProduto(90)};  // Criar matriz de objetos com inicialização.

    cout << "Primeiro elemento da matriz de codigos de produtos: " << matrizCodigoProduto[0].getValor() << endl;
    cout << "Segundo  elemento da matriz de codigos de produtos: " << matrizCodigoProduto[1].getValor() << endl;

    // ------------------------------------------------------------------------
    // Exemplo de uso de herança.

    CodigoServico w;

    try{
        w.setValor(60);                                     // Armazenamenar valor válido não resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    cout << "Valor = " << w.getValor() << endl;             // Apresentar valor atual de atributo.

    try{
        w.setValor(120);                                    // Tentativa de armazenar valor inválido resulta em lançamento de exceção.
    }
    catch(invalid_argument &exp){                           // Capturar exceção da classe invalid_argument, referência para objeto para evitar cópia.
        cout << "Excecao : " << exp.what() << endl;
    }

    // ------------------------------------------------------------------------
    // Exemplo de uso de herança.

    ContaConvencional contaA;                                               // Instanciar classe que herda de Conta.
    ContaEspecial contaB;                                                   // Instanciar classe que herda de Conta.

    contaA.depositar(100);                                                  // Invocar método herdado.
    contaB.depositar(200);                                                  // Invocar método herdado.

    cout << "Saldo conta convencional = " << contaA.getSaldo() << endl;     // Invocar método herdado.
    cout << "Saldo conta especial     = " << contaB.getSaldo() << endl;     // Invocar método herdado.


    if(contaA.sacar(10))                                                    // Invocar método não herdado.
        cout << "Saldo conta convencional = " << contaA.getSaldo() << endl; // Invocar método herdado.
    else
        cout << "Saque da conta convencional foi recusado" << endl;

    if(contaB.sacar(20))                                                    // Invocar método não herdado.
        cout << "Saldo conta especial = " << contaB.getSaldo() << endl;     // Invocar método herdado.
    else
        cout << "Saque da conta especial foi recusado" << endl;

    if(contaA.sacar(100))                                                   // Invocar método não herdado.
        cout << "Saldo conta convencional = " << contaB.getSaldo() << endl; // Invocar método herdado.
    else
        cout << "Saque da conta convencional foi recusado" << endl;

    if(contaB.sacar(200))                                                   // Invocar método não herdado.
        cout << "Saldo conta especial = " << contaB.getSaldo() << endl;     // Invocar método herdado.
    else
        cout << "Saque da conta especial foi recusado" << endl;

    if(contaB.sacar(1000))                                                  // Invocar método não herdado.
        cout << "Saldo conta especial = " << contaB.getSaldo() << endl;     // Invocar método herdado.
    else
        cout << "Saque da conta especial foi recusado" << endl;

    // ------------------------------------------------------------------------
    // Exemplo de uso de construtores em herança.

    Engenheiro engenheiroA, engenheiroB;                                    // Instanciar classe que herda de PessoaFisica.
                                                                            // Executar construtores default.

    cout << "Registro  = " << engenheiroA.getRegistro()  << endl;
    cout << "Matricula = " << engenheiroA.getMatricula() << endl;

    cout << "Registro  = " << engenheiroB.getRegistro()  << endl;
    cout << "Matricula = " << engenheiroB.getMatricula() << endl;


    Engenheiro engenheiroC(50,500), engenheiroD(60,600);                    // Instanciar classe que herda de PessoaFisica.
                                                                            // Executar construtores que aguardam valores.
    cout << "Registro  = " << engenheiroC.getRegistro()  << endl;
    cout << "Matricula = " << engenheiroC.getMatricula() << endl;

    cout << "Registro  = " << engenheiroD.getRegistro()  << endl;
    cout << "Matricula = " << engenheiroD.getMatricula() << endl;

    // ------------------------------------------------------------------------
    // Exemplo de uso de construtores em herança múltipla.

    Petroleo petroleoA("Bacia de Campos", 100, 1000);                       // Instanciar classe que herda de Liquido e BemProducao.
    Petroleo petroleoB("Bacia de Santos", 200, 2000);                       // Executar construtores que aguardam valores.

    cout << "Petroleo A = " << petroleoA.getOrigem() << " - " << petroleoA.getDensidade() << " - " << petroleoA.getValor() << endl;
    cout << "Petroleo B = " << petroleoB.getOrigem() << " - " << petroleoB.getDensidade() << " - " << petroleoB.getValor() << endl;

    // ------------------------------------------------------------------------
    // Exemplo de uso de sobrecarga.

    Cliente clienteA;

    clienteA.setContato(1234);                                              // Invocar métodos com mesmo nome mas distintos parâmetros.
    clienteA.setContato("nome@empresa");

    int telefone;
    string email;

    clienteA.getContato(&telefone, &email);                                 // Acessar valores de atributos.

    cout << "Numero de telefone = " << telefone << endl;
    cout << "Endereco de email  = " << email << endl;


    //---------------------------------------------------------------------
    // Exemplo de uso de sobrescrita (overriding).

    ContaCorrente contaC;
    ContaCorrenteEspecial contaD;

    contaC.depositar(100);                                                  // Invocar métodos com mesmas assinaturas mas de diferentes classes.
    contaD.depositar(200);

    cout << "Saldo conta corrente = " << contaC.getSaldo() << endl;
    cout << "Saldo conta corrente especial = " << contaD.getSaldo() << endl;


    if(contaC.sacar(10))
        cout << "Saldo conta corrente = " << contaC.getSaldo() << endl;
    else
        cout << "Saque da conta corrente foi recusado" << endl;

    if(contaD.sacar(20))
        cout << "Saldo conta corrente especial = " << contaD.getSaldo() << endl;
    else
        cout << "Saque da conta corrente especial foi recusado" << endl;

    if(contaC.sacar(1000))
        cout << "Saldo conta corrente = " << contaC.getSaldo() << endl;
    else
        cout << "Saque da conta corrente foi recusado" << endl;

    if(contaD.sacar(1000))
        cout << "Saldo conta corrente especial = " << contaD.getSaldo() << endl;
    else
        cout << "Saque da conta corrente especial foi recusado" << endl;

    //---------------------------------------------------------------------
    // Exemplo de uso de método virtual.

    ContaCliente contaE;
    ContaClienteEspecial contaF;

    ControladoraTransacao cntrA;

    contaE.depositar(100);
    contaF.depositar(200);

    cout << "Saldo conta cliente = " << contaE.getSaldo() << endl;
    cout << "Saldo conta cliente especial = " << contaF.getSaldo() << endl;

    if(cntrA.transferir(&contaE, &contaF, 50)){
        cout << "Saldo conta de origem  = " << contaE.getSaldo() << endl;
        cout << "Saldo conta de destino = " << contaF.getSaldo() << endl;
    }
    else
        cout << "Erro na transferencia" << endl;

    if(cntrA.transferir(&contaF, &contaE, 20)){
        cout << "Saldo conta de origem  = " << contaE.getSaldo() << endl;
        cout << "Saldo conta de destino = " << contaF.getSaldo() << endl;
    }
    else
        cout << "Erro na transferencia" << endl;

    if(cntrA.transferir(&contaE, &contaF, 1000)){
        cout << "Saldo conta de origem  = " << contaE.getSaldo() << endl;
        cout << "Saldo conta de destino = " << contaF.getSaldo() << endl;
    }
    else
        cout << "Erro na transferencia" << endl;

    if(cntrA.transferir(&contaF, &contaE, 1000)){
        cout << "Saldo conta de origem  = " << contaF.getSaldo() << endl;
        cout << "Saldo conta de destino = " << contaE.getSaldo() << endl;
    }
    else
        cout << "Erro na transferencia" << endl;

    return 0;
}
