#ifndef BAZADANYCH_H
#define BAZADANYCH_H

#include "lista.h"

class BazaDanych{

    public:
        Lista listaNumerow;
        std::string nazwaPliku = "bazaNumerow";

    BazaDanych();
    BazaDanych(std::string plik);
    ~BazaDanych();
};




#endif