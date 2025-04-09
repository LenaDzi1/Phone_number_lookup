#include "lista.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include "NumerTelefonu.h"
#include "kraj.h"
#include <iostream>

NumerTelefonu::NumerTelefonu(std::string nr_tel, std::string nr_kier, std::string nr_opis) {
    numer_telefonu = nr_tel;
    numer_kierunkowy = nr_kier;
    opis = nr_opis;
    nastepny = 0;
}

