#include "lista.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include "NumerTelefonu.h"
#include "kraj.h"
#include <iostream>

NumerIrytujacy::NumerIrytujacy(std::string nr_tel, std::string nr_kier, std::string nr_opis, bool marketing) : NumerTelefonu(nr_tel, nr_kier, nr_opis) {
    numer_telefonu = nr_tel;
    numer_kierunkowy = nr_kier;
    opis = nr_opis;
    czyMarketing = marketing;
    nastepny = 0;
}


void NumerIrytujacy::wyswietl() {
    Kraj nowy_kraj(numer_kierunkowy);
    nowy_kraj.dodaj_kraj();
    if (czyMarketing) {
        std::cout << "[IRYTUJACY] [MARKETING] " << ' ' << nowy_kraj << ' ' << '+' << numer_kierunkowy << ' ' << numer_telefonu << "    -    " << opis << std::endl;// << '\t' << nowy_kraj
    }
    else {
        std::cout << "[IRYTUJACY] " << ' ' << nowy_kraj << ' ' << '+' << numer_kierunkowy << ' ' << numer_telefonu << "    -    " << opis << std::endl;//<< '\t' << nowy_kraj 
    }
}

std::string NumerIrytujacy::eksportuj() {
    return std::to_string(typ) + ';' + numer_telefonu + ';' + numer_kierunkowy + ';' + opis + ';' + std::to_string(czyMarketing);
}
