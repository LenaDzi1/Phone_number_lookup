#ifndef	REKORD_H
#define REKORD_H

#include "lista.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include "NumerTelefonu.h"
#include "Dane.h"

class Rekord {
    int rozmiarListy = 0;

public:
    Dane* pierwszy;
    void dodaj(Dane* nowy);
    void usun(int indeks);
    int rozmiar();
    Rekord();
    Dane* operator[](int indeks);
};


#endif
