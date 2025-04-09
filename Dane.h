#ifndef DANE_H
#define DANE_H

#include "lista.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include "NumerTelefonu.h"

class Dane {
public:
    Dane* nastepny;
    std::string tresc;

    Dane(std::string tresc);
};

#endif
