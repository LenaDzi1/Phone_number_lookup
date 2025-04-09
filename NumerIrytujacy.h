#ifndef NUMERIR_H
#define NUMERIR_H

#include "NumerTelefonu.h"
#include "lista.h"
#include <string>

class NumerIrytujacy : public NumerTelefonu {
    int typ = 2;
public:
    bool czyMarketing = false;
    void wyswietl();
    std::string eksportuj();
    NumerIrytujacy(std::string nr_tel, std::string nr_kier, std::string nr_opis, bool marketing);
};

#endif