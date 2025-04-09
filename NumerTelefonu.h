#ifndef NUMERTEL_H
#define NUMERTEL_H
#include "lista.h"
#include <string>

class NumerTelefonu {
public:
    std::string numer_telefonu;
    std::string numer_kierunkowy;
    std::string opis;
    int typ;

    NumerTelefonu* nastepny;

    //Konstruktor
    NumerTelefonu(std::string nr_tel, std::string nr_kier, std::string nr_opis);

    //Destruktor
    virtual ~NumerTelefonu() = default;

    virtual void wyswietl() = 0;
    virtual std::string eksportuj() = 0;

};

#endif