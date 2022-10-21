#include "Dominios.h"

const unordered_set<string> Idioma::POSSIVEIS_VALORES = {
    "Arabe", "Bengali", "Chines", "Espanhol", "Frances", "Hindi",
    "Indonesio", "Ingles", "Mandarim", "Portugues", "Russo"
};


const unordered_set<string> Cidade::POSSIVEIS_VALORES = {
    "Antalya", "Bangkok", "Delhi", "Dubai", "Hong Kong", "Londres", "Macau",
    "Mumbai", "Paris", "Rio de Janeiro", "Sao Paulo", "Seul", "Istambul",
    "Kuala Lumpur", "Nova Iorque", "Osaka", "Phuket", "Shenzhen", "Toquio"
};

const unordered_set<string> Pais::POSSIVEIS_VALORES = {
    "Estados Unidos", "Brasil", "China", "Coreia do Sul", "Emirados", "Franca",
    "India", "Japao", "Malasia", "Reino Unido", "Tailandia", "Turquia"
};


const regex Data::PADRAO_ACEITO = regex(
    "^((?:0[1-9]|[12][0-9]|3[01])[\\/](Jan|Mar|Mai|Jul|Ago|Out|Dez))|(?:0[1-9]|[12][0-9]|3[0])[\\/](Abr|Jun|Set|Nov)|(?:0[1-9]|[12][0-9]|2[01])[\\/](Fev)$"
);


const regex Nota::PADRAO_ACEITO = regex("^([0-9]|10)$");


const regex Email::PADRAO_ACEITO = regex(
    "^(?!^[.]|.*[-_.]{2}.*[@]|.*[._@][@-]|.*[-][.@]|.*[-.]$)[a-zA-Z0-9-_.]{1,64}[@]([a-zA-Z0-9-]{1,63}[.]?)+$"
);


const regex Senha::PADRAO_ACEITO = regex(
    "^(?=.*[A-Za-z])(?=.*[0-9])(?=.*[!#$%&])[a-zA-Z0-9!#$%&]{5}$"
);


const regex Descricao::PADRAO_NAO_ACEITO("[.,;:!?-]{2}|[ ]{2}");

const int Descricao::MAXIMO_CARACTERES = 40;

