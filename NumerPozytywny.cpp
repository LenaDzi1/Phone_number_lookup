#include "lista.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include "NumerTelefonu.h"
#include "kraj.h"
#include <iostream>


NumerPozytywny::NumerPozytywny(std::string nr_tel, std::string nr_kier, std::string nr_opis) : NumerTelefonu(nr_tel, nr_kier, nr_opis) {
    numer_telefonu = nr_tel;
    numer_kierunkowy = nr_kier;
    opis = nr_opis;
    nastepny = 0;
}

void NumerPozytywny::wyswietl() {
    Kraj nowy_kraj(numer_kierunkowy);
    nowy_kraj.dodaj_kraj();
    std::cout << "[POZYTYWNY] " << ' ' << nowy_kraj << ' ' << '+' << numer_kierunkowy << ' ' << numer_telefonu << "    -    " << opis << std::endl;// '\t' << nowy_kraj <<
}

std::string NumerPozytywny::eksportuj() {
    return std::to_string(typ) + ';' + numer_telefonu + ';' + numer_kierunkowy + ';' + opis;
}

