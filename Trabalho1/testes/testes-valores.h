#include "../Dominios.h"
#include <string>

#ifndef TEST_VALUES_H_
#define TEST_VALUES_H_


using namespace std;

template <class Dom> class ValoresEInfo{
    public:
        static const pair<string, string> VALORES_VALIDOS[];
        static const pair<string, string> VALORES_INVALIDOS[];
        
        static const int N_VALORES_VALIDOS;
        static const int N_VALORES_INVALIDOS;
};


#endif // TEST_VALUES_H_
