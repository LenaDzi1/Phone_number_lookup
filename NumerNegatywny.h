#ifndef NUMERNEG_H
#define NUMERNEG_H
#include "NumerTelefonu.h"
#include "lista.h"
#include <string>

class NumerNegatywny : public NumerTelefonu {
    int typ = 1;
public:
    bool czyOszust = false;
    void wyswietl();
    std::string eksportuj();
    NumerNegatywny(std::string nr_tel, std::string nr_kier, std::string nr_opis, bool oszust);
};

#endif