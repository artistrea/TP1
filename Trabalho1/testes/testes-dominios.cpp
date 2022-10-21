#include "../Dominios.h"
#include <unordered_map>
#include "testes-valores.h"
#include "catch.hpp"

using namespace std;


TEMPLATE_TEST_CASE( "dominios tem construtor, set e get funcionando", "[dominios]",
            Nome , Nota, Data, Codigo, Cidade, Email, Senha, Descricao, Pais, Idioma
            // Acessiveis no teste por TestType
    ) {
    
 
    SECTION("método set", "[set]"){
        TestType dominio{
            ValoresEInfo<TestType>::VALORES_VALIDOS[0].first
        };
 
        SECTION("valores validos", "[validos]"){
 
            for(int i = 0; i < ValoresEInfo<TestType>::N_VALORES_VALIDOS; i++){
                const pair<string, string> &valor_e_info = ValoresEInfo<TestType>::VALORES_VALIDOS[i];
                const string &valor = valor_e_info.first, &info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
                    CHECK_NOTHROW(dominio.setValor(valor));
 
                    CHECK((dominio.getValor() == valor));
                }
            }
 
        }
 
        SECTION("valores invalidos", "[invalidos]"){
            for(int i = 0; i < ValoresEInfo<TestType>::N_VALORES_INVALIDOS; i++){
                const pair<string, string> &valor_e_info = ValoresEInfo<TestType>::VALORES_INVALIDOS[i];
                const string &valor = valor_e_info.first, &info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
                    CHECK_THROWS_AS(dominio.setValor(valor), invalid_argument);
                    CHECK((dominio.getValor() != valor));
                }
            }
        }
    }
 
 
    SECTION("construtor", "[construtor]"){
        TestType* dominioptr;
 
        SECTION("valores validos", "[validos]"){
 
            for(int i = 0; i < ValoresEInfo<TestType>::N_VALORES_VALIDOS; i++){
                const pair<string, string> &valor_e_info = ValoresEInfo<TestType>::VALORES_VALIDOS[i];
                const string &valor = valor_e_info.first, &info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
 
                    dominioptr = 0;
 
                    CHECK_NOTHROW(dominioptr = new TestType(valor));
                    if(dominioptr != 0)
                        CHECK((dominioptr->getValor() == valor));
 
                    delete dominioptr;
                }
            }
        }
 
        SECTION("valores invalidos", "[invalidos]"){
 
            for(int i = 0; i < ValoresEInfo<TestType>::N_VALORES_INVALIDOS; i++){
                const pair<string, string> &valor_e_info = ValoresEInfo<TestType>::VALORES_INVALIDOS[i];
                const string& valor = valor_e_info.first, info = valor_e_info.second;
 
                SECTION(valor + '\n' + info){
                    dominioptr = 0;
 
                    CHECK_THROWS_AS((dominioptr = new TestType(valor)), invalid_argument);
 
                    delete dominioptr;
                }
            }
        }
    }
}
