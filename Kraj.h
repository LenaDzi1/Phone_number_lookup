#ifndef KRAJ_H
#define KRAJ_H

#include <iostream>
#include <string>
class Kraj {
public:
    std::string numer_kierunkowy;
    std::string kraj;
    int typ;

  
    Kraj(std::string nr_kier);

    ~Kraj(){};
    void dodaj_kraj();

    friend std::ostream& operator<<(std::ostream& os, const Kraj& obiekt);
};



#endif
