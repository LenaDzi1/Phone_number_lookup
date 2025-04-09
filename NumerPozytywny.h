#ifndef NUMERPOZ_H
#define NUMERPOZ_H
#include "NumerTelefonu.h"
#include "lista.h"
#include <string>

class NumerPozytywny : public NumerTelefonu {
    int typ = 4;
public:
    void wyswietl();
    std::string eksportuj();
    NumerPozytywny(std::string nr_tel, std::string nr_kier, std::string nr_opis);
};


#endif