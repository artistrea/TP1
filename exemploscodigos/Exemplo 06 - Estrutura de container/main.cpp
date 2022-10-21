// Exemplo de classes containers.

#include <iostream>
#include <string>
#include <list>

#include "dominios.h"
#include "entidades.h"
#include "containers.h"

using namespace std;

int main() {

    // Criar objetos a serem armazenados em container.

    Usuario usuario_1, usuario_2, usuario_3, usuario_4;
    Matricula matricula_1, matricula_2, matricula_3, matricula_4;
    Senha senha_1, senha_2, senha_3, senha_4, senha_5;

    matricula_1.setValor(10);
    matricula_2.setValor(20);
    matricula_3.setValor(30);
    matricula_4.setValor(40);

    senha_1.setValor(500);
    senha_2.setValor(600);
    senha_3.setValor(700);
    senha_4.setValor(800);
    senha_5.setValor(1000);

    usuario_1.setMatricula(matricula_1);
    usuario_1.setSenha(senha_1);
    usuario_2.setMatricula(matricula_2);
    usuario_2.setSenha(senha_2);
    usuario_3.setMatricula(matricula_3);
    usuario_3.setSenha(senha_3);
    usuario_4.setMatricula(matricula_4);
    usuario_4.setSenha(senha_4);

    bool resultado;

    // Criar container.

    ContainerUsuario container;

    // Exemplos de sucesso em inclusões.

    resultado = container.incluir(usuario_1);

    if(!resultado){
        cout << "Erro na inclusao" << endl;
    }
    else {
        cout << "Sucesso na inclusao" << endl;
    }

    resultado = container.incluir(usuario_2);

    if(!resultado){
        cout << "Erro na inclusao" << endl;
    }
    else {
        cout << "Sucesso na inclusao" << endl;
    }

    resultado = container.incluir(usuario_3);

    if(!resultado){
        cout << "Erro na inclusao" << endl;
    }
    else {
        cout << "Sucesso na inclusao" << endl;
    }

    // Erro por tentativa de incluir elemento presente no container.

    resultado = container.incluir(usuario_1);

    if(!resultado){
        cout << "Erro na inclusao" << endl;
    }
    else {
        cout << "Sucesso na inclusao" << endl;
    }

    // Exemplo de sucesso em remoção.

    resultado = container.remover(matricula_2);

    if(!resultado){
        cout << "Erro na remocao" << endl;
    }
    else {
        cout << "Sucesso na remocao" << endl;
    }

    // Erro por tentativa de remover do container um elemento anteriormente removido.

    resultado = container.remover(matricula_2);

    if(!resultado){
        cout << "Erro na remocao" << endl;
    }
    else {
        cout << "Sucesso na inclusao" << endl;
    }

    // Erro por tentativa de remover do container um elemento não incluído.

    resultado = container.remover(matricula_4);

    if(!resultado){
        cout << "Erro na remocao" << endl;
    }
    else {
        cout << "Sucesso na inclusao" << endl;
    }

    // Erros na procura de elementos ausentes do container.

    Usuario usuario;

    usuario.setMatricula(matricula_2);

    resultado = container.pesquisar(&usuario);

    if(!resultado){
        cout << "Usuario nao encontrado" << endl;
    }
    else{
        cout << "Usuario encontrado" << endl;
        cout << "Matricula = " << usuario.getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario.getSenha().getValor() << endl;
    }

    usuario.setMatricula(matricula_4);

    resultado = container.pesquisar(&usuario);

    if(!resultado){
        cout << "Usuario nao encontrado" << endl;
    }
    else{
        cout << "Usuario encontrado" << endl;
        cout << "Matricula = " << usuario.getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario.getSenha().getValor() << endl;
    }

    // Exemplos de sucesso na procura de elementos no container.

    usuario.setMatricula(matricula_1);

    resultado = container.pesquisar(&usuario);

    if(!resultado){
        cout << "Usuario nao encontrado" << endl;
    }
    else{
        cout << "Usuario encontrado" << endl;
        cout << "Matricula = " << usuario.getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario.getSenha().getValor() << endl;
    }

    usuario.setMatricula(matricula_3);

    resultado = container.pesquisar(&usuario);

    if(!resultado){
        cout << "Usuario nao encontrado" << endl;
    }
    else{
        cout << "Usuario encontrado" << endl;
        cout << "Matricula = " << usuario.getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario.getSenha().getValor() << endl;
    }

    // Erro por tentativa de atualização de objeto inexistente.

    usuario.setMatricula(matricula_2);
    usuario.setSenha(senha_5);

    resultado = container.atualizar(usuario);

    if(!resultado){
        cout << "Erro na atualizacao" << endl;
    }
    else{
        cout << "Sucesso na atualizacao" << endl;
    }

    // Sucesso na atualização de objeto.

    usuario.setMatricula(matricula_1);
    usuario.setSenha(senha_5);

    resultado = container.atualizar(usuario);

    if(!resultado){
        cout << "Erro na atualizacao" << endl;
    }
    else{
        cout << "Sucesso na atualizacao" << endl;
    }

    // Demonstra atualização realizada

    usuario.setMatricula(matricula_1);
    usuario.setSenha(senha_1);

    resultado = container.pesquisar(&usuario);

    if(!resultado){
        cout << "Usuario nao encontrado" << endl;
    }
    else{
        cout << "Usuario encontrado" << endl;
        cout << "Matricula = " << usuario.getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario.getSenha().getValor() << endl;
    }

    return 0;
}
