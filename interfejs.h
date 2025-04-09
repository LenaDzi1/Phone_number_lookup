#ifndef INTERFEJS_H
#define INTERFEJS_H

#include "lista.h"

class Interfejs {
public:
    static void wyswietlMenu();
    static void wyszukajNumer(Lista& listaNumerow, const std::string& numerDoWyszukania);
    static void zaktualizujNumer(Lista& listaNumerow, int indeks);
    static void uruchomInterfejs();
};

#endif // INTERFEJS_H
