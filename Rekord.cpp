#include "Rekord.h"
#include "bazadanych.h"
#include "Dane.h"
#include <iostream>
#include <fstream>
#include <sstream>

Rekord::Rekord() {
    pierwszy = 0;
}

int Rekord::rozmiar() {
    return rozmiarListy;
}

void Rekord::dodaj(Dane* nowy) {
    if (rozmiarListy == 0) {
        pierwszy = nowy;
        rozmiarListy++;
    }
    else {
        Dane* temp = pierwszy;

        while (temp->nastepny) {
            temp = temp->nastepny;
        }

        temp->nastepny = nowy;
        rozmiarListy++;
    }
}

void Rekord::usun(int indeks) {
    if (indeks >= 0 && indeks < rozmiarListy) {
        if (indeks == 0) {

            Dane* temp = pierwszy;
            pierwszy = temp->nastepny;
            delete temp;

        }
        else {

            Dane* temp = pierwszy;

            int i = 0;

            while (temp) {
                if ((i + 1) == indeks) {
                    break;
                }
                temp = temp->nastepny;
                i++;
            }

            temp->nastepny = temp->nastepny->nastepny;

            delete temp->nastepny;

        }

        rozmiarListy--;
    }
}

Dane* Rekord::operator[](int indeks) {
    if (indeks >= 0 && indeks < rozmiarListy) {
        Dane* temp = pierwszy;
        for (int i = 0; i < indeks; i++) {
            temp = temp->nastepny;
        }
        return temp;
    }
    else {
        return nullptr;
    }
}