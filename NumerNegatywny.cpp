#include "lista.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include "NumerTelefonu.h"
#include "kraj.h"
#include <iostream>

NumerNegatywny::NumerNegatywny(std::string nr_tel, std::string nr_kier, std::string nr_opis, bool oszust) : NumerTelefonu(nr_tel, nr_kier, nr_opis) {
    numer_telefonu = nr_tel;
    numer_kierunkowy = nr_kier;
    opis = nr_opis;
    czyOszust = oszust;
    nastepny = 0;
}

void NumerNegatywny::wyswietl() {
    Kraj nowy_kraj(numer_kierunkowy);
    nowy_kraj.dodaj_kraj();
    if (czyOszust) {
        std::cout << "[NEGATYWNY] [OSZUST] " << ' ' << nowy_kraj << ' ' << '+' << numer_kierunkowy << ' ' << numer_telefonu << "    -    " << opis << std::endl;// 
    }
    else {
        std::cout << "[NEGATYWNY] " << ' ' << nowy_kraj << ' ' << '+' << numer_kierunkowy << ' ' << numer_telefonu << "    -    " << opis << std::endl;//<< '\t' << nowy_kraj 
    }
}

std::string NumerNegatywny::eksportuj() {
    return std::to_string(typ) + ';' + numer_telefonu + ';' + numer_kierunkowy + ';' + opis + ';' + std::to_string(czyOszust);
}
