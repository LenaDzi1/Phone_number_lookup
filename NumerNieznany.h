#ifndef NUMERNIE_H
#define NUMERNIE_H
#include "NumerTelefonu.h"
#include "lista.h"
#include <string>

class NumerNieznany : public NumerTelefonu {
    int typ = 3;
public:
    void wyswietl();
    std::string eksportuj();
    NumerNieznany(std::string nr_tel, std::string nr_kier, std::string nr_opis);
};

#endif