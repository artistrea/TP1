#include "catch.hpp"
#include "../Entidades.h"
#include <iostream>
#include "testes-valores.h"


TEST_CASE("usuario tem construtor, set e get funcionando", "[entidades][usuario]") {
    Usuario* usuario = 0;

    string  nome      = ValoresEInfo< Nome >::VALORES_VALIDOS[0].first;
    string  email     = ValoresEInfo< Email >::VALORES_VALIDOS[0].first;
    string  senha     = ValoresEInfo< Senha >::VALORES_VALIDOS[0].first;
    string  idioma    = ValoresEInfo< Idioma >::VALORES_VALIDOS[0].first;
    string  aniversario      = ValoresEInfo< Data >::VALORES_VALIDOS[0].first;
    string  descricao = ValoresEInfo< Descricao >::VALORES_VALIDOS[0].first;

    string  nome2     = ValoresEInfo< Nome >::VALORES_VALIDOS[1].first;
    string  email2    = ValoresEInfo< Email >::VALORES_VALIDOS[1].first;
    string  senha2    = ValoresEInfo< Senha >::VALORES_VALIDOS[1].first;
    string  idioma2   = ValoresEInfo< Idioma >::VALORES_VALIDOS[1].first;
    string  aniversario2     = ValoresEInfo< Data >::VALORES_VALIDOS[1].first;
    string  descricao2= ValoresEInfo< Descricao >::VALORES_VALIDOS[1].first;

    string  nome_invalido      = ValoresEInfo< Nome >::VALORES_INVALIDOS[0].first;
    string  email_invalido     = ValoresEInfo< Email >::VALORES_INVALIDOS[0].first;
    string  senha_invalido     = ValoresEInfo< Senha >::VALORES_INVALIDOS[0].first;
    string  idioma_invalido    = ValoresEInfo< Idioma >::VALORES_INVALIDOS[0].first;
    string  aniversario_invalido      = ValoresEInfo< Data >::VALORES_INVALIDOS[0].first;
    string  descricao_invalido = ValoresEInfo< Descricao >::VALORES_INVALIDOS[0].first;


    SECTION("construtor funciona", "[construtor]") {
        REQUIRE_NOTHROW( usuario = new Usuario(nome, email, senha, idioma, aniversario, descricao) );


        SECTION("validar ainda funciona") {
            REQUIRE_THROWS_AS( usuario = new Usuario(nome_invalido, email, senha, idioma, aniversario, descricao), invalid_argument );
            REQUIRE_THROWS_AS( usuario = new Usuario(nome, email_invalido, senha, idioma, aniversario, descricao), invalid_argument );
            REQUIRE_THROWS_AS( usuario = new Usuario(nome, email, senha_invalido, idioma, aniversario, descricao), invalid_argument );
            REQUIRE_THROWS_AS( usuario = new Usuario(nome, email, senha, idioma_invalido, aniversario, descricao), invalid_argument );
            REQUIRE_THROWS_AS( usuario = new Usuario(nome, email, senha, idioma, aniversario_invalido, descricao), invalid_argument );
            REQUIRE_THROWS_AS( usuario = new Usuario(nome, email, senha, idioma, aniversario, descricao_invalido), invalid_argument );
        }
        
        CHECK(usuario->getNome()        == nome         );
        CHECK(usuario->getEmail()       == email        );
        CHECK(usuario->getSenha()       == senha        );
        CHECK(usuario->getIdioma()      == idioma       );
        CHECK(usuario->getAniversario() == aniversario  );
        CHECK(usuario->getDescricao()   == descricao    );

        delete usuario;
    }


    usuario = new Usuario(nome, email, senha, idioma, aniversario, descricao);
    SECTION("metodo set funciona", "[set]") {
        CHECK_NOTHROW(usuario->setNome       (    nome2       ));
        CHECK_NOTHROW(usuario->setEmail      (    email2      ));
        CHECK_NOTHROW(usuario->setSenha      (    senha2      ));
        CHECK_NOTHROW(usuario->setIdioma     (    idioma2     ));
        CHECK_NOTHROW(usuario->setAniversario(    aniversario2));
        CHECK_NOTHROW(usuario->setDescricao  (    descricao2  ));

        SECTION("validar ainda funciona") {
            REQUIRE_THROWS_AS(usuario->setNome       (  nome_invalido       ), invalid_argument);
            REQUIRE_THROWS_AS(usuario->setEmail      (  email_invalido      ), invalid_argument);
            REQUIRE_THROWS_AS(usuario->setSenha      (  senha_invalido      ), invalid_argument);
            REQUIRE_THROWS_AS(usuario->setIdioma     (  idioma_invalido     ), invalid_argument);
            REQUIRE_THROWS_AS(usuario->setAniversario(  aniversario_invalido), invalid_argument);
            REQUIRE_THROWS_AS(usuario->setDescricao  (  descricao_invalido  ), invalid_argument);
        }


        CHECK(usuario->getNome()        == nome2        );
        CHECK(usuario->getEmail()       == email2       );
        CHECK(usuario->getSenha()       == senha2       );
        CHECK(usuario->getIdioma()      == idioma2      );
        CHECK(usuario->getAniversario() == aniversario2 );
        CHECK(usuario->getDescricao()   == descricao2   );
    }

    delete usuario;
}


TEST_CASE ("hospedagem tem construtor, set e get funcionando", "[entidades][hospedagem]") {
    Hospedagem* hospedagem = 0;

    string  codigo    = ValoresEInfo< Codigo >::VALORES_VALIDOS[0].first;
    string  cidade    = ValoresEInfo< Cidade >::VALORES_VALIDOS[0].first;
    string  pais      = ValoresEInfo< Pais >::VALORES_VALIDOS[0].first;
    string  nota      = ValoresEInfo< Nota >::VALORES_VALIDOS[0].first;
    string  descricao = ValoresEInfo< Descricao >::VALORES_VALIDOS[0].first;


    string  codigo2    = ValoresEInfo< Codigo >::VALORES_VALIDOS[1].first;
    string  cidade2    = ValoresEInfo< Cidade >::VALORES_VALIDOS[1].first;
    string  pais2      = ValoresEInfo< Pais >::VALORES_VALIDOS[1].first;
    string  nota2      = ValoresEInfo< Nota >::VALORES_VALIDOS[1].first;
    string  descricao2 = ValoresEInfo< Descricao >::VALORES_VALIDOS[1].first;

    string  codigo_invalido    = ValoresEInfo< Codigo >::VALORES_INVALIDOS[0].first;
    string  cidade_invalido    = ValoresEInfo< Cidade >::VALORES_INVALIDOS[0].first;
    string  pais_invalido      = ValoresEInfo< Pais >::VALORES_INVALIDOS[0].first;
    string  nota_invalido      = ValoresEInfo< Nota >::VALORES_INVALIDOS[0].first;
    string  descricao_invalido = ValoresEInfo< Descricao >::VALORES_INVALIDOS[0].first;

    SECTION("construtor funciona", "[construtor]") {
        REQUIRE_NOTHROW( hospedagem = new Hospedagem(codigo, cidade, pais, nota, descricao) );

        SECTION("validar ainda funciona") {
            REQUIRE_THROWS_AS( hospedagem = new Hospedagem(codigo_invalido, cidade, pais, nota, descricao), invalid_argument );
            REQUIRE_THROWS_AS( hospedagem = new Hospedagem(codigo, cidade_invalido, pais, nota, descricao), invalid_argument );
            REQUIRE_THROWS_AS( hospedagem = new Hospedagem(codigo, cidade, pais_invalido, nota, descricao), invalid_argument );
            REQUIRE_THROWS_AS( hospedagem = new Hospedagem(codigo, cidade, pais, nota_invalido, descricao), invalid_argument );
            REQUIRE_THROWS_AS( hospedagem = new Hospedagem(codigo, cidade, pais, nota, descricao_invalido), invalid_argument );
        }

        CHECK(hospedagem->getCodigo()    == codigo   );
        CHECK(hospedagem->getCidade()    == cidade   );
        CHECK(hospedagem->getPais()      == pais     );
        CHECK(hospedagem->getNota()      == nota     );
        CHECK(hospedagem->getDescricao() == descricao);
        
        delete hospedagem;
    }

    hospedagem = new Hospedagem(codigo, cidade, pais, nota, descricao);
    SECTION("metodo set funciona", "[set]") {
        REQUIRE_NOTHROW(hospedagem->setCodigo   (   codigo2     ));
        REQUIRE_NOTHROW(hospedagem->setCidade   (   cidade2     ));
        REQUIRE_NOTHROW(hospedagem->setPais     (   pais2       ));
        REQUIRE_NOTHROW(hospedagem->setNota     (   nota2       ));
        REQUIRE_NOTHROW(hospedagem->setDescricao(   descricao2  ));

        SECTION("validar ainda funciona") {
            REQUIRE_THROWS_AS(hospedagem->setCodigo   (   codigo_invalido     ), invalid_argument);
            REQUIRE_THROWS_AS(hospedagem->setCidade   (   cidade_invalido     ), invalid_argument);
            REQUIRE_THROWS_AS(hospedagem->setPais     (   pais_invalido       ), invalid_argument);
            REQUIRE_THROWS_AS(hospedagem->setNota     (   nota_invalido       ), invalid_argument);
            REQUIRE_THROWS_AS(hospedagem->setDescricao(   descricao_invalido  ), invalid_argument);
        }

        CHECK(hospedagem->getCodigo()    == codigo2   );
        CHECK(hospedagem->getCidade()    == cidade2   );
        CHECK(hospedagem->getPais()      == pais2     );
        CHECK(hospedagem->getNota()      == nota2     );
        CHECK(hospedagem->getDescricao() == descricao2);
    }

    delete hospedagem;
}


TEST_CASE ("avaliacao tem construtor, set e get funcionando", "[entidades][avaliacao]") {
    Avaliacao* avaliacao = 0;

    string  codigo       =  ValoresEInfo< Codigo >::VALORES_VALIDOS[0].first;
    string  nota         =  ValoresEInfo< Nota >::VALORES_VALIDOS[0].first;
    string  descricao    =  ValoresEInfo< Descricao >::VALORES_VALIDOS[0].first;


    string  codigo2      =  ValoresEInfo< Codigo >::VALORES_VALIDOS[1].first;
    string  nota2        =  ValoresEInfo< Nota >::VALORES_VALIDOS[1].first;
    string  descricao2   =  ValoresEInfo< Descricao >::VALORES_VALIDOS[1].first;


    string  codigo_invalido       =  ValoresEInfo< Codigo >::VALORES_INVALIDOS[0].first;
    string  nota_invalido         =  ValoresEInfo< Nota >::VALORES_INVALIDOS[0].first;
    string  descricao_invalido    =  ValoresEInfo< Descricao >::VALORES_INVALIDOS[0].first;

    SECTION("construtor funciona", "[construtor]") {
        REQUIRE_NOTHROW( avaliacao = new Avaliacao(codigo, nota, descricao) );


        SECTION("validar ainda funciona") {
            REQUIRE_THROWS_AS( avaliacao = new Avaliacao(codigo_invalido, nota, descricao), invalid_argument);
            REQUIRE_THROWS_AS( avaliacao = new Avaliacao(codigo, nota_invalido, descricao), invalid_argument);
            REQUIRE_THROWS_AS( avaliacao = new Avaliacao(codigo, nota, descricao_invalido), invalid_argument);
        }

        
        CHECK(avaliacao->getCodigo()    == codigo   );
        CHECK(avaliacao->getNota()      == nota     );
        CHECK(avaliacao->getDescricao() == descricao);
        
        delete avaliacao;
    }

    avaliacao = new Avaliacao(codigo, nota, descricao);
    SECTION("metodo set funciona", "[set]") {
        REQUIRE_NOTHROW(avaliacao->setCodigo   (   codigo2     ));
        REQUIRE_NOTHROW(avaliacao->setNota     (   nota2       ));
        REQUIRE_NOTHROW(avaliacao->setDescricao(   descricao2  ));

        SECTION("validar ainda funciona") {
            REQUIRE_THROWS_AS( avaliacao = new Avaliacao(codigo_invalido, nota, descricao), invalid_argument);
            REQUIRE_THROWS_AS( avaliacao = new Avaliacao(codigo, nota_invalido, descricao), invalid_argument);
            REQUIRE_THROWS_AS( avaliacao = new Avaliacao(codigo, nota, descricao_invalido), invalid_argument);
        }

        CHECK(avaliacao->getCodigo()    == codigo2   );
        CHECK(avaliacao->getNota()      == nota2     );
        CHECK(avaliacao->getDescricao() == descricao2);
    }


    delete avaliacao;
}