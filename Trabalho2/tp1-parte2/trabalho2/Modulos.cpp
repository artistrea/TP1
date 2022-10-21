#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"
#include "Modulos.h"
#include <iostream>
#include <string.h>
#include <random>
#include <algorithm>
using namespace std;

// MCA
void ModuloCntrlAprs::executar() {
    // Menu Principal:
    Usuario* cur_usr = 0;
    char display[] = "|=============================================================================================================|";
    char texto1[] = "\t Bem-vindo a hospedagens e anfitrioes!";
    char texto2[] = "\t 1 - Listar as hospedagens disponiveis.";
    char texto3[] = "\t 2 - Para se cadastrar.";
    char texto4[] = "\t 3 - Caso ja seja um usuario dos nossos servicos";
    char texto5[] = "\t 0 - Sair do sistema";

    int opcaoMenu;
    bool apresentar = true;

    ICAU* modAprsAutUsr = new ModuloCntrAprsUsr();
    IACU* modAprsCadUsr = new ModuloAprsCadUsr();
    IAH* modAprsHosp = new ModuloAprsHosp();


    Usuario* usuario_corrente = 0;

    while (apresentar) {

        CLR_SCR;

        // Menu principal
        cout << display << endl;
        cout << endl << endl;
        cout << texto1 << endl;
        cout << endl << endl;
        cout << texto2 << endl; // --> IAH --> MAH --> MSH
        cout << texto3 << endl; // --> ICU --> MACU
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << endl << endl;
        cout << display << endl;

        cout << '\t';
        cin >> opcaoMenu;
        cin.get();
        //======================================

        switch (opcaoMenu) {
        case 1: // listar hospedagens
            modAprsHosp->executar();
            break;
        case 2: modAprsCadUsr->cadastrar_usuario();
            break;
        case 3: modAprsAutUsr->executar();
            break;
        case 0: apresentar = false;
            break;
        }
    }
    return;
}

// MCAU
bool ModuloCntrAprsUsr::executar() {
    // Mensagens a serem apresentadas na tela de autenticacao.
    char display[] = "|=============================================================================================================|";
    char texto1[] = "\t Digite o Email: ";
    char texto2[] = "\t Digite a senha: ";
    char texto3[] = "\t Dado(s) invalido(s).";
    char texto4[] = "\t 0 - Para voltar ao menu inicial.";
    char texto5[] = "\t 1 - Para tentar novamente.";

    // Campos de entrada.
    int opcaoErro;
    string email;
    string senha;

    bool apresentar = true;

    ISU* cntrISU = new ModuloServUsr();

    while (true) {
        CLR_SCR;

        // Criação do menu | Coleta de dados do usuario
        cout << display << endl;
        cout << endl;
        cout << texto1;
        cin >> email;
        cout << texto2;
        cin >> senha;
        //============================================

        if (!cntrISU->autenticar_usuario(email, senha)) {

            // Informações caso ocorra erro de auth
            cout << endl;
            cout << texto3 << endl;
            cout << texto4 << endl;
            cout << texto5 << endl;
            cout << '\t'; cin >> opcaoErro;
            //=======================================

            if (opcaoErro == 1) {
                continue;
            }
            else {
                return false;
            }
        }

        // Mensagens a serem apresentadas na tela de selecaoo de servico.
        char texto6[] = "\t Com quais servicos podemos ajuda-lo hoje? ";
        char texto7[] = "\t 1 - Selecionar servicos de usuario.";
        char texto8[] = "\t 2 - Selecionar servicos de hospedagens";
        char texto9[] = "\t 3 - Selecionar servicos de avaliacao";
        char texto10[] = "\t 4 - Encerrar sessao.";

        IAUU* moduloAprsUsrUsr = new ModuloAprsUsrUsr();
        IAHU* moduloAprsHospUsr = new ModuloAprsHospUsr();
        IAAU* moduloAprsAvalUsr = new ModuloAprsAvalUsr();

        while (true) {
            CLR_SCR;

            // Menu com opcoes para usuario autenticado
            cout << display << endl;
            cout << endl << endl;
            cout << texto6 << endl;
            cout << texto7 << endl;
            cout << texto8 << endl;
            cout << texto9 << endl;
            cout << texto10 << endl;
            cout << endl << endl;
            cout << display << endl;

            cout << '\t';
            int opcaoMenu;
            cin >> opcaoMenu;
            cin.get();

            switch (opcaoMenu) {
                
            case 1:
                moduloAprsUsrUsr->executar(email);
                return true;
            case 2:
                moduloAprsHospUsr->executar(email);
                break;
            case 3:
                moduloAprsAvalUsr->executar(email);
                break;
            case 4:
                return true;
            }
        }
    }


}

// MACU
void ModuloAprsCadUsr::cadastrar_usuario() {

    // Mensagens a serem apresentadas na tela de cadastramento.
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Tela de Cadastro: ";
    char texto1[] = "\t Digite seu Nome: ";
    char texto2[] = "\t Digite seu Email: ";
    char texto3[] = "\t Digite sua Senha: ";

    char texto4[] = "\t Dados em formato incorreto.";
    char texto5[] = "\t 0 - Para voltar ao menu inicial.";
    char texto6[] = "\t 1 - Para tentar novamente.";

    // Dados de entrada
    int opcaoErro;
    string nomeString; char emailChar[80], senhaChar[80];
    Usuario* usuario = 0;

    //Servico
    ISU* cntrISU = new ModuloServUsr();

    while (true) {
        CLR_SCR;

        // Tela de cadastramento
        cout << display << endl;
        cout << texto0 << endl;
        cout << endl;
        cout << texto1;
        getline(cin, nomeString);
        cout << texto2;
        cin >> emailChar;
        cout << texto3;
        cin >> senhaChar;
        cin.ignore(10000, '\n');
        cout << endl;

        try {
            // Validar os dados de cadastro e inicializa Usuario
            usuario = new Usuario(nomeString, emailChar, senhaChar, "Portugues", "01/Jan", "Escreva aqui sobre voce.");
            break;
        }
        catch (invalid_argument& e) {
            delete usuario;

            // Informações caso ocorra erro
            cout << endl;
            cerr << '\t' << e.what() << endl;
            cout << texto4 << endl;
            cout << texto5 << endl;
            cout << texto6 << endl;
            cout << '\t';
            cin >> opcaoErro; cin.get(); // limpando buffer
            //=======================================
            if (opcaoErro == 0) {
                return;
            }
        }
    }

    if (cntrISU->adicionar(*usuario)) {
        cout << "\t Cadastrado com sucesso. Digite algo para voltar ao menu principal." << endl;
        cout << '\t'; cin.get();
    }
    return;
}

// MAUU
void ModuloAprsUsrUsr::executar(string email) {
    // tela de apresentacao de usuario para usuario ja cadastrado
    CLR_SCR;
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Esta e sua tela de usuario!";
    char texto1[] = "\t 1- Para Editar suas informacoes";
    char texto2[] = "\t 2- Para Descadastrar minha conta";

    IAUU* cntrlModAprUsrUsr = new ModuloAprsUsrUsr();

    cout << display << endl;
    cout << endl << endl;

    cout << texto0 << endl << endl;
    cout << texto1 << endl;
    cout << texto2 << endl;
    cout << endl << endl;
    cout << display << endl;

    int opcao;
    cout << '\t'; cin >> opcao; cin.get();

    switch (opcao)
    {
    case 1:
        cntrlModAprUsrUsr->editar_usuario(email);
        break;
    case 2:
        cntrlModAprUsrUsr->descadastrar_usuario(email);
        break;
    default:
        return;
    }
    return;
}


void ModuloAprsUsrUsr::editar_usuario(string email) {
    char display[] = "|=============================================================================================================|";
    char texto1[] = "\t Insira o novo nome: ";
    char texto2[] = "\t Insira a nova senha: ";
    char texto3[] = "\t Insira o novo idioma: ";
    char texto4[] = "\t Insira a nova data de aniversario: ";
    char texto5[] = "\t Insira o nova descricao: ";
    char texto6[] = "\t Edicao realizada com sucesso ";
    char texto7[] = "\t Digite algo para voltar ao menu inicial. ";

    Usuario* usr;

    string nome, senha, idioma, data, descricao;
    bool apresentar = true, opcao = false;

    ISH* cntrlServ = new ModuloServHosp();

    while (apresentar) {

        CLR_SCR;

        cout << display << endl;
        cout << endl << endl;

        cout << texto1;
        getline(cin, nome);

        cout << texto2;
        getline(cin, senha);

        cout << texto3;
        getline(cin, idioma);

        cout << texto4;
        getline(cin, data);

        cout << texto5;
        getline(cin, descricao);

        try {
            usr = new Usuario(nome, email, senha, idioma, data, descricao);
            cout << endl;
            cout << endl;
            cout << texto6 << endl << endl;
            cout << texto7 << endl;
            cout << '\t'; cin >> opcao; cin.get();
            return;
        }
        catch (invalid_argument& e) {
            cout << endl;
            cout << '\t' << ' ' << e.what() << endl << endl;
            cout << "\t Digite 1 para tentar novamente e 0 para sair: "; cin >> opcao; cin.get();
            cout << endl;

            if (opcao != apresentar) {
                apresentar = false;
                return;
            }
        }
    }
}

void ModuloAprsUsrUsr::descadastrar_usuario(string email) {
    CLR_SCR;

    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Digite 1 para descadastrar ou 0 para retornar: ";
    char texto1[] = "\t Usuario descadastrado. Digite algo";

    int opcao;
    ISU* cntrISU = new ModuloServUsr();
    cout << display << endl;
    cout << texto0; cin >> opcao; cin.get();

    if (opcao == 0) return;

    cntrISU->remover(email);

    cout << texto1;
    cin >> opcao;

    return;
}


// MAAU
void ModuloAprsAvalUsr::executar(string email) {
    // tela de apresentacao de hospedagem para usuario ja cadastrado
    CLR_SCR;
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Esta e sua tela de avaliacoes!";
    char texto1[] = "\t 1- Para Cadastrar uma avaliacao";
    char texto2[] = "\t 2- Para Editar avaliacao sobre alguma hospedagem";
    char texto3[] = "\t 3- Para Descadastrar uma avaliacao";


    cout << display << endl;
    cout << endl << endl;
    cout << texto0 << endl << endl;
    cout << texto1 << endl;
    cout << texto2 << endl;
    cout << texto3 << endl;
    cout << endl << endl;
    cout << display << endl;

    int opcao;

    cout << '\t'; cin >> opcao;
    cin.get();

    IAAU* modAprsAvalUsr = new ModuloAprsAvalUsr();


    switch (opcao)
    {
    case 1: modAprsAvalUsr->cadastrar_avaliacao(email);
        break;
    case 2: modAprsAvalUsr->editar_avaliacao(email);
        break;
    case 3: modAprsAvalUsr->descadastrar_avaliacao(email);
        break;
    default:
        break;
    }
    return;
}

void ModuloAprsAvalUsr::cadastrar_avaliacao(string email) {
    // tela de coleta de dados da avaliacao
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Qual a nota voce da pra essa hospedagem [0-10]: ";
    char texto1[] = "\t O que voce diz sobre essa hospedagem: ";
    char texto2[] = "\t 0 - Para voltar ao menu inicial.";
    char texto3[] = "\t 1 - Para tentar novamente.";
    char texto4[] = "\t Qual o codigo da hospedagem? ";
    char texto5[] = "\t Lista das hospedagens:";


    string descricaoString, nota, codigo_da_hospedagem;

    ISA* cntrlServAval = new ModuloServAval();
    ISH* moduloServHosp = new ModuloServHosp();

    Avaliacao* avaliacao = 0;

    while (true) {

        CLR_SCR;

        cout << display << endl;
        cout << texto5 << endl << endl;

        for (const Hospedagem& hospedagem : moduloServHosp->todos()) {
            cout << '[' << hospedagem.getPais() << " - " << hospedagem.getCidade();
            cout << "] " << hospedagem.getCodigo() << endl;
            cout << '\t' << "nota: " << hospedagem.getNota() << endl;
            cout << '\t' << hospedagem.getDescricao() << endl;
        }

        cout << endl;
        cout << endl;

        cout << display << endl;
        cout << endl;
        cout << texto4;
        cin >> codigo_da_hospedagem;
        cout << endl;
        cout << texto0;
        cin >> nota;
        cout << endl;
        cout << texto1;
        cin.get();
        getline(cin, descricaoString);

        try {
            Hospedagem hospedagem = moduloServHosp->pesquisar(codigo_da_hospedagem);
            avaliacao = new Avaliacao(cntrlServAval->cria_codigo(), nota, descricaoString, hospedagem, email);
            break;
        }
        catch (invalid_argument& e) {
            cout << endl;
            cerr << '\t' << e.what() << endl;
            cout << texto2 << endl;
            cout << texto3 << endl;

            string continuar;

            cout << '\t' << ' '; cin >> continuar;
            if (continuar == "0") {
                return;
            }
        }
    }

    string opcao;
    // chama o servico para cadastrar
    if (cntrlServAval->adicionar(*avaliacao)) {
        cout << endl;
        cout << "\t Cadastrou avaliacao!" << endl << endl;
        cout << "\t Digite algo para voltar ao menu principal. "; cin >> opcao; cin.get();
    }
}

void ModuloAprsAvalUsr::editar_avaliacao(string email) {
    CLR_SCR;
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Lista das suas avaliacoes:";
    char texto1[] = "\t Qual avaliacao voce quer editar? ";
    char texto2[] = "\t Digite a nova nota: ";
    char texto3[] = "\t Digite a nova descricao: ";

    int opcao;
    string codigoAvaliacao, descricaoString, nota;
    ISA* cntrlServAval = new ModuloServAval();

    cout << display << endl;
    cout << endl;

    // listar avaliacoes do usuarios
    cout << texto0;
    cout << endl;

    for (const Avaliacao& avaliacao : cntrlServAval->todos(Email(email))) {
        cout << "\t" << avaliacao.getCodigo() << endl;
        cout << "\t\t Nota: \t" << avaliacao.getNota() << endl;
        cout << "\t\t Comentario: \t" << avaliacao.getDescricao() << endl << endl;
    }
    cout << endl;
    cout << texto1; cin >> codigoAvaliacao;


    try {
        Avaliacao avl = cntrlServAval->pesquisar(codigoAvaliacao);
        cout << texto2; cin >> nota;
        avl.setNota(nota);
        cout << texto3; 
        cin.get(); getline(cin, descricaoString);
        avl.setDescricao(descricaoString);
        // solicitar servico para editar avaliacao
        cntrlServAval->atualizar(avl);
        return;
    }
    catch (invalid_argument& er) {
        cout << er.what();
    }
    return;
}

void ModuloAprsAvalUsr::descadastrar_avaliacao(string email) {
    CLR_SCR;

    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Lista das suas avaliacoes:";
    char texto1[] = "\t Qual avaliacao voce quer remover? ";
    char texto2[] = "\t 0 - Para voltar ao menu principal.";

    string opcaoAvaliacao;
    ISA* cntrlServAval = new ModuloServAval();

    while (true) {
        CLR_SCR;

        cout << display;
        cout << endl;
        cout << texto0;
        cout << endl;
        cout << endl;

        for (const Avaliacao& avaliacao : cntrlServAval->todos(Email(email))) {
            cout << "\t" << avaliacao.getCodigo() << endl;
            cout << "\t\t Nota: \t" << avaliacao.getNota() << endl;
            cout << "\t\t Comentario: \t" << avaliacao.getDescricao() << endl << endl;
        }

        cout << endl;

        // Lista as avaliacoes do usuario

        // cout << endl;
        cout << texto1 << endl;
        cout << texto2 << endl;

        cout << '\t'; cin >> opcaoAvaliacao;

        if (opcaoAvaliacao == "0") {
            return;
        }

        // chama servico para remover avaliacao
        cntrlServAval->remover(opcaoAvaliacao);
    }
}

// MAHU
void ModuloAprsHospUsr::executar(string email) {
    // tela de apresentacao de hospedagem para usuario ja cadastrado
    CLR_SCR;
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Esta e sua tela de hospedagem!";
    char texto1[] = "\t 1- Para Cadastrar uma hospedagem";
    char texto2[] = "\t 2- Para Editar informacoes sobre hospedagem";
    char texto3[] = "\t 3- Para Descadastrar uma hospedagem";

    cout << display << endl;
    cout << endl << endl;
    cout << texto0 << endl << endl;
    cout << texto1 << endl;
    cout << texto2 << endl;
    cout << texto3 << endl;
    cout << endl << endl;
    cout << display << endl;

    int opcao;

    cout << '\t'; cin >> opcao;
    cin.get();

    switch (opcao)
    {
    case 1:
        this->cadastrar_hospedagem(email);
        return;
    case 2:
        this->editar_hospedagem(email);
        return;
    case 3:
        this->descadastrar_hospedagem(email);
        return;
    default:
        return;
    }
    return;
}


void ModuloAprsHospUsr::cadastrar_hospedagem(string email) {
    CLR_SCR;
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Insira a cidade da sua hospedagem: ";
    char texto1[] = "\t Insira o pais da sua hospedagem: ";
    char texto2[] = "\t Insira a descricao da sua hospedagem: ";
    char texto3[] = "\t Cadastro realizado com sucesso, digite algo para voltar ao menu inicial.";

    Hospedagem* hosp;

    string cidade, pais, descricao, opcao;

    ISH* cntrlServ = new ModuloServHosp();
    cout << display << endl;
    cout << texto0;

    getline(cin, cidade);

    cout << texto1;
    getline(cin, pais);

    cout << texto2;
    getline(cin, descricao);

    cout << endl;

    try {
        hosp = new Hospedagem(cntrlServ->cria_codigo(), cidade, pais, "5", descricao, email);
        cntrlServ->adicionar(*hosp);
        cout << texto3 << endl;
        cout << '\t'; cin >> opcao; cin.get();
        return;
    }
    catch (invalid_argument& e) {
        cout << "\t " << e.what() << endl;
    }
}

void ModuloAprsHospUsr::descadastrar_hospedagem(string email) {
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Digite seu codigo de hospedagem ";
    char texto1[] = "\t Hospedagem excluida";
    char texto2[] = "\t Dados invalidos/Hospedagem nao existe";
    char texto3[] = "\t Digite para continuar";
    ISH* cntrlHospServ = new ModuloServHosp();
    string codigo;

    cout << display << endl;
    for (const Hospedagem& hospedagem : cntrlHospServ->todos()) {
        cout << '[' << hospedagem.getPais() << " - " << hospedagem.getCidade();
        cout << "] " << hospedagem.getCodigo() << endl;
        cout << '\t' << "Nota: " << hospedagem.getNota() << endl;
        cout << '\t' << "Descricao: " << hospedagem.getDescricao() << endl << endl;
    }
    
    cout << texto0;
    cin >> codigo;
    try {
        string nome = (cntrlHospServ->pesquisar(codigo)).getEmailAnfitriao();
        if (nome == email) cntrlHospServ->remover(codigo);
        cout << texto1 << endl;

    }catch (invalid_argument &e) {
        cout << e.what() << endl;
        cout << texto2 << endl;
    }
    cout << texto3 << endl;
    cin >> codigo;
    return;
}


void ModuloAprsHospUsr::editar_hospedagem(string email) {
    CLR_SCR;
    char display[] = "|=============================================================================================================|";
    char texto0[] = "\t Insira o codigo da sua hospedagem: ";
    char texto1[] = "\t Insira a nova cidade da sua hospedagem: ";
    char texto2[] = "\t Insira o novo pais da sua hospedagem: ";
    char texto3[] = "\t Insira a nova descricao da sua hospedagem: ";
    char texto4[] = "\t Edicao realizada com sucesso, digite algo para voltar ao menu inicial.";
    char texto5[] = "\t Digite algo para voltar ao menu inicial.";
    char texto6[] = "\t Lista das suas hospedagens.";

    Hospedagem* hosp;
    string codigo, cidade, pais, descricao, opcao;

    ISH* cntrlServ = new ModuloServHosp();

    while (true) {

        cout << display << endl;
        cout << endl << endl;

        cout << texto6 << endl << endl; 
        for (const Hospedagem& hospedagem : cntrlServ->todos()) {
            cout << '[' << hospedagem.getPais() << " - " << hospedagem.getCidade();
            cout << "] " << hospedagem.getCodigo() << endl;
            cout << '\t' << "Nota: " << hospedagem.getNota() << endl;
            cout << '\t' << "Descricao: " << hospedagem.getDescricao() << endl << endl;
        }
        cout << endl;
        cout << texto0;

        cin >> codigo;

        cout << texto1;cin.ignore(10000, '\n');
        getline(cin, cidade);

        cout << texto2;
        getline(cin, pais);

        cout << texto3;
        getline(cin, descricao);

        try {
            hosp = new Hospedagem(codigo, cidade, pais, "5", descricao, email);
            break;
        }
        catch (invalid_argument& e) {
            cout << '\t' << e.what() << endl;
            cout << endl << "\t Digite 1 para tentar novamente e 0 para voltar ao menu principal: " << endl;
            cout << '\t'; cin >> opcao; cin.get();

            if (opcao == "0") {
                return;
            }
        }
    }

    cntrlServ->atualizar(*hosp);

    cout << endl << texto4 << endl; cout << '\t'; cin >> pais;
    return;
}

ModuloServHosp* ModuloAprsHosp::moduloServHosp = new ModuloServHosp();

// MAH
void ModuloAprsHosp::executar() {
    char display[] = "|=============================================================================================================|";
    char texto1[] = "\t Lista das hospedagens cadastradas:";
    char texto2[] = "\t Digite o codigo da hospedagem que deseja saber mais sobre";
    char texto3[] = "\t Digite 1 para ver outra hospedagem, e 0 para voltar ao menu anterior:";


    CLR_SCR;

    bool apresentar = true;

    while (apresentar) {
        cout << display << endl;
        cout << endl;
        cout << texto1 << endl;

        this->todos();

        char codigo[13];

        cout << endl << texto2 << endl;

        cin >> codigo;
        try {
            Hospedagem hospedagem_escolhida = moduloServHosp->pesquisar(codigo);
            this->mostrar(&hospedagem_escolhida);
        }
        catch (invalid_argument& er) {
            cout << "\t "  << er.what() << endl;
        }

        cout << endl;
        cout << texto3;
        string opcao;
        cout << '\t'; cin >> opcao; cin.get();
        if (opcao == "0") return;
    }

}

void ModuloAprsHosp::todos() {
    vector<Hospedagem> hospedagens = moduloServHosp->todos();

    for (const Hospedagem& hospedagem : hospedagens) {
        cout << '[' << hospedagem.getPais() << " - " << hospedagem.getCidade();
        cout << "] " << hospedagem.getCodigo() << endl;
        cout << '\t' << "Nota: " << hospedagem.getNota() << endl;
        cout << '\t' << "Descricao: " << hospedagem.getDescricao() << endl << endl;
    }
}

void ModuloAprsHosp::mostrar(Hospedagem* hospedagem) {
    cout << "\t Codigo: \t" << hospedagem->getCodigo() << endl;
    cout << "\t Anfitriao: \t" << hospedagem->getEmailAnfitriao() << endl;
    cout << "\t Nota: \t" << hospedagem->getNota() << endl;
    cout << "\t Pais: \t" << hospedagem->getPais() << endl;
    cout << "\t Cidade: \t" << hospedagem->getCidade() << endl;
    cout << "\t Descricao: \t" << hospedagem->getDescricao() << endl << endl;

    cout << "\t Avaliacoes da hospedagem:" << endl << endl;

    ModuloServAval moduloServAval;

    vector<Avaliacao> avaliacoes = moduloServAval.todos(*hospedagem);

    int i = 1;
    for (const Avaliacao& avaliacao : avaliacoes) {
        i++;
        cout << "\t Por \t" << avaliacao.getEmailUsuario() << endl;
        cout << "\t\t Nota: \t" << avaliacao.getNota() << endl;
        cout << "\t\t Comentario: \t" << avaliacao.getDescricao() << endl << endl;
    }
}

// Modulos de servico
//
// MSU

ContainerUsuario* ModuloServUsr::container = new ContainerUsuario();

bool ModuloServUsr::adicionar(Usuario usr) {
    return container->adicionar(usr);
}

bool ModuloServUsr::autenticar_usuario(string email, string senha) {
    try {
        if (container->pesquisar(email).getSenha() != senha) {
            return false;
        }
    }
    catch (invalid_argument& er) {
        return false;
    }

    return true;
}
vector<Usuario> ModuloServUsr::todos() {
    return container->todos();
}

Usuario ModuloServUsr::pesquisar(string email) {
    return container->pesquisar(email);
}


bool ModuloServUsr::atualizar(Usuario usr) {
    return container->atualizar(&usr);
}

bool ModuloServUsr::remover(string email) {
    return container->remover(email);
}


//==============================================================================
// MSH
ContainerHospedagem* ModuloServHosp::container = new ContainerHospedagem();

bool ModuloServHosp::adicionar(Hospedagem hosp) {
    return container->adicionar(hosp);
}


bool ModuloServHosp::remover(string codigo) {
    return container->remover(codigo);
}

Hospedagem ModuloServHosp::pesquisar(string codigo) {
    return container->pesquisar(codigo);
}

bool ModuloServHosp::atualizar(Hospedagem hsp) {
    return container->atualizar(&hsp);
}

string ModuloServHosp::cria_codigo() {
    int v3 = rand() % 100000000 + 1000000000;
    string valor = to_string(v3) + "0";

    int soma = 0;
    bool ehpar = false;

    for (int i = 11 - 1; i >= 0; i--) {
        int d = valor[i] - '0';

        if (ehpar) {
            d = d * 2;
        }
        soma += d / 10;
        soma += d % 10;
        ehpar = !ehpar;
    }
    (soma % 10 == 0) ? valor[10] = 0 + '0' : valor[10] = (10 - (soma % 10)) + '0';
    return valor;
}

vector<Hospedagem> ModuloServHosp::todos() {
    return container->todos();
}


// =============================================================================
// MSA

ContainerAvaliacao* ModuloServAval::container = new ContainerAvaliacao();

bool ModuloServAval::adicionar(Avaliacao avaliacao) {
    ISH *cntrlHosp = new ModuloServHosp();
    // retorna hospedagem cuja avaliacao foi feita
    Hospedagem hosp_changed = cntrlHosp->pesquisar(avaliacao.getCodigoHospedagem());
    // troca a nota
    hosp_changed.setNota(avaliacao.getNota());
    // troca a hospedagem
    cntrlHosp->atualizar(hosp_changed);
    // adiciona a avaliacao
    return container->adicionar(avaliacao);
}

bool ModuloServAval::atualizar(Avaliacao avaliacao) {
    return container->atualizar(&avaliacao);
}

bool ModuloServAval::remover(string codigo) {
    return container->remover(codigo);
}

Avaliacao ModuloServAval::pesquisar(string codigo) {
    return container->pesquisar(codigo);
}

string ModuloServAval::cria_codigo() {
    int v3 = rand() % 100000000 + 1000000000;
    string valor = to_string(v3) + "0";

    int soma = 0;
    bool ehpar = false;

    for (int i = 11 - 1; i >= 0; i--) {
        int d = valor[i] - '0';

        if (ehpar) {
            d = d * 2;
        }
        soma += d / 10;
        soma += d % 10;
        ehpar = !ehpar;
    }
    (soma % 10 == 0) ? valor[10] = 0 + '0' : valor[10] = (10 - (soma % 10)) + '0';
    return valor;
}


// Filtra por hospedagem
vector<Avaliacao> ModuloServAval::todos(Hospedagem hospedagem) {
    vector<Avaliacao> todos = container->todos(), v;

    copy_if(todos.begin(), todos.end(), back_inserter(v),
        [&hospedagem = hospedagem](Avaliacao av) {
            return av.getCodigoHospedagem() == hospedagem.getCodigo();
        }
    );

    return v;
}

// Filtra por usuário
vector<Avaliacao> ModuloServAval::todos(Email email_do_usuario) {
    vector<Avaliacao> todos = container->todos(), v;

    copy_if(todos.begin(), todos.end(), back_inserter(v),
        [&email_do_usuario = email_do_usuario](Avaliacao av) {
            return av.getEmailUsuario() == email_do_usuario.getValor();
        }
    );

    return v;
}
