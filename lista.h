#ifndef LISTA_H
#define LISTA_H
#include "NumerTelefonu.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include <string>

class Lista{

    int rozmiarListy = 0;

    public:
        NumerTelefonu* pierwszy;
        void dodaj_numer(NumerTelefonu *nowy);
        void usun_numer (int indeks);
        void wyswietl_liste ();
        int rozmiar();
        Lista();
        NumerTelefonu* operator[](int indeks);
};

#endif