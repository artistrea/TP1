// Exemplo de uso de template list e de template vector.

#include <stdexcept>
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "dominios.h"
#include "entidades.h"

using namespace std;

int main()
{
    int chave;

    // Criar objetos a serem armazenados.

    Usuario usuario_1, usuario_2, usuario_3, usuario_4;
    Matricula matricula_1, matricula_2, matricula_3, matricula_4;
    Senha senha_1, senha_2, senha_3, senha_4;

    matricula_1.setValor(10);
    senha_1.setValor(500);
    matricula_2.setValor(20);
    senha_2.setValor(600);
    matricula_3.setValor(30);
    senha_3.setValor(700);
    matricula_4.setValor(40);
    senha_4.setValor(800);

    usuario_1.setMatricula(matricula_1);
    usuario_1.setSenha(senha_1);
    usuario_2.setMatricula(matricula_2);
    usuario_2.setSenha(senha_2);
    usuario_3.setMatricula(matricula_3);
    usuario_3.setSenha(senha_3);
    usuario_4.setMatricula(matricula_4);
    usuario_4.setSenha(senha_4);

    // Instanciar list.

    list<Usuario> lista_usuarios;

    // Inserir elementos em container.

    lista_usuarios.push_back(usuario_1);
    lista_usuarios.push_back(usuario_2);
    lista_usuarios.push_back(usuario_3);
    lista_usuarios.push_back(usuario_4);

    // Percorrer lista.

    cout << "Percorrer lista" << endl << endl;

    for(list<Usuario>::iterator usuario = lista_usuarios.begin(); usuario != lista_usuarios.end(); usuario++){
        cout << "Matricula = " << usuario->getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario->getSenha().getValor() << endl << endl;
    }

    // Procurar elemento.

    chave = 30;

    for(list<Usuario>::iterator usuario = lista_usuarios.begin(); usuario != lista_usuarios.end(); usuario++){

        if (usuario->getMatricula().getValor() == chave){
            cout << "Localizado = " << usuario->getMatricula().getValor() << endl << endl;
            break;
        }
    }

    // Procurar e remover elemento.

    chave = 20;

    for(list<Usuario>::iterator usuario = lista_usuarios.begin(); usuario != lista_usuarios.end(); usuario++){

        if (usuario->getMatricula().getValor() == chave){
            cout << "Remover = " << usuario->getMatricula().getValor() << endl << endl;
            lista_usuarios.erase(usuario);
            break;
        }
    }

    // Percorrer lista.

    cout << "Percorrer lista" << endl << endl;

    for(list<Usuario>::iterator usuario = lista_usuarios.begin(); usuario != lista_usuarios.end(); usuario++){
        cout << "Matricula = " << usuario->getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario->getSenha().getValor() << endl << endl;
    }

    // Instanciar vector.

    vector<Usuario> vetor_usuarios;

    // Inserir elementos em container.

    vetor_usuarios.push_back(usuario_1);
    vetor_usuarios.push_back(usuario_2);
    vetor_usuarios.push_back(usuario_3);
    vetor_usuarios.push_back(usuario_4);

    // Percorrer vetor.

    cout << "Percorrer vetor" << endl << endl;

    for(vector<Usuario>::iterator usuario = vetor_usuarios.begin(); usuario != vetor_usuarios.end(); usuario++){
        cout << "Matricula = " << usuario->getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario->getSenha().getValor() << endl << endl;
    }

    // Procurar elemento.

    chave = 30;

    for(vector<Usuario>::iterator usuario = vetor_usuarios.begin(); usuario != vetor_usuarios.end(); usuario++){

        if (usuario->getMatricula().getValor() == chave){
            cout << "Localizado = " << usuario->getMatricula().getValor() << endl << endl;
            break;
        }
    }

    // Procurar e remover elemento.

    chave = 20;

    for(vector<Usuario>::iterator usuario = vetor_usuarios.begin(); usuario != vetor_usuarios.end(); usuario++){

        if (usuario->getMatricula().getValor() == chave){
            cout << "Remover = " << usuario->getMatricula().getValor() << endl << endl;
            vetor_usuarios.erase(usuario);
            break;
        }
    }

    // Percorrer vetor.

    cout << "Percorrer vetor" << endl << endl;

    for(vector<Usuario>::iterator usuario = vetor_usuarios.begin(); usuario != vetor_usuarios.end(); usuario++){
        cout << "Matricula = " << usuario->getMatricula().getValor() << endl;
        cout << "Senha     = " << usuario->getSenha().getValor() << endl << endl;
    }

    return 0;
}
