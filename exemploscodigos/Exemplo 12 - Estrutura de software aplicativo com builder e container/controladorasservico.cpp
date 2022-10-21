#include "controladorasservico.h"

//--------------------------------------------------------------------------------------------
// Implementações de métodos de classes controladoras da camada de serviço.

bool CntrServicoAutenticacao::autenticar(CPF cpf, Senha senha){

    // ---------------------------------------------------------------------------------------
    // Instanciar container de usuários.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Recuperar e comparar senha de usuário.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Retornar resultado.
    // ---------------------------------------------------------------------------------------

    return true;
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::cadastrarUsuario(Usuario usuario){

    // Instancia container de usuários.

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usuário e retornar resultado da solicitação de serviço.

    return container->incluir(usuario);
}

//--------------------------------------------------------------------------------------------



