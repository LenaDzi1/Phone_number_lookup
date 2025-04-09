#include <iostream>
#include <string>
#include "kraj.h"

std::ostream& operator<<(std::ostream& os, const Kraj& obiekt) {
    os << "[Kraj: " << obiekt.kraj << ']';
    return os;
}


Kraj::Kraj(std::string nr_kier) {
    this->numer_kierunkowy = nr_kier;
    this->typ = std::stoi(nr_kier);
   // void dodaj_kraj();
}

void Kraj::dodaj_kraj() {

    switch (typ) {
    case 1:
        kraj = "Ameryka/Kanada";
        break;
    case 420:
        kraj = "Czechy";
        break;
    case 49:
        kraj = "Niemcy";
        break;
    case 48:
       kraj = "Polska";
       break;
    case 39:
        kraj = "Wlochy";
        break;
    case 36:
        kraj = "Wegry";
        break;
    case 380:
        kraj = "Ukraina";
        break;
    case 90:
        kraj = "Turcja";
        break;
    case 963:
        kraj = "Syria";
        break;
    case 7:
        kraj = "Rosja";
        break;
    case 93:
        kraj = "Afganistan";
        break;
    case 355:
        kraj = "Albania";
        break;
    case 966:
        kraj = "Arabia Saudyjska";
        break;
    case 61:
        kraj = "Australia";
        break;
    case 43:
        kraj = "Austria";
        break;
    case 32:
        kraj = "Belgia";
        break;
    case 375:
        kraj = "Bialorus";
        break;
    case 387:
        kraj = "Bosnia i Hercegowina";
        break;
    case 359:
        kraj = "Bulgaria";
        break;
    case 86:
        kraj = "Chiny";
        break;
    case 385:
        kraj = "Chorwacja";
        break;
    case 42:
        kraj = "Dania";
        break;
    case 20:
        kraj = "Egipt";
    case 33:
        kraj = "Francja";
    case 30:
        kraj = "Grecja";
        break;
    case 34:
        kraj = "Hiszpania";
        break;
    case 91:
        kraj = "Indie";
        break;
    case 370:
        kraj = "Litwa";
        break;
    case 52:
        kraj = "Meksyk";
        break;
    case 373:
        kraj = "Mo³dawia";
        break;
    case 386:
        kraj = "S³owenia";
        break;
    default:
        kraj = "Inny";
        break;
    }
  
}