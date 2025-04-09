#include "bazadanych.h"
#include "Rekord.h"
#include "Dane.h"
#include <iostream>
#include <fstream>
#include <sstream>

BazaDanych::BazaDanych(std::string _nazwa){
    
    nazwaPliku = _nazwa;

    std::ifstream plik(nazwaPliku+".txt");
    if (!plik.is_open()) {
      std::cout << "Nie udalo sie otworzyc pliku "+nazwaPliku << std::endl;
      return;
    }

    std::string linia;
    while (std::getline(plik, linia)) {
        Rekord rekord;
        std::istringstream iss(linia);
        std::string tresc;

        while (std::getline(iss, tresc, ';')) {
            Dane *nowy = new Dane(tresc);

            rekord.dodaj(nowy);
        }

        NumerTelefonu* nowy = nullptr;

        switch(stoi(rekord[0]->tresc)){
            case 1:
                nowy = new NumerNegatywny(rekord[1]->tresc, rekord[2]->tresc, rekord[3]->tresc, std::stoi(rekord[4]->tresc));
            break;
            case 2:
                nowy = new NumerIrytujacy(rekord[1]->tresc, rekord[2]->tresc, rekord[3]->tresc, std::stoi(rekord[4]->tresc));
            break;
            case 3:
                nowy = new NumerNieznany(rekord[1]->tresc, rekord[2]->tresc, rekord[3]->tresc);
            break;
            case 4:
                nowy = new NumerPozytywny(rekord[1]->tresc, rekord[2]->tresc, rekord[3]->tresc);
            break;
        }

        listaNumerow.dodaj_numer(nowy);
    }
}

BazaDanych::BazaDanych() : BazaDanych("bazaNumerow"){
    
}

BazaDanych::~BazaDanych(){
    std::ofstream plik(nazwaPliku+".txt");

    if (!plik) {
      std::cout << "Nie udalo sie otworzyc pliku "+nazwaPliku << std::endl;
      return;
    }

    for(int i=0; i<listaNumerow.rozmiar(); i++){
        plik << listaNumerow[i]->eksportuj() << "\n";
    }

    plik.close();
}



