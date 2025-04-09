#include "interfejs.h"
#include "bazadanych.h"
#include "Dane.h"
#include "Rekord.h"
#include <iostream>

void Interfejs::wyswietlMenu() {
    std::cout << "=========== Menu ============" << std::endl;
    std::cout << "1. Wyswietl liste numerow" << std::endl;
    std::cout << "2. Dodaj numer" << std::endl;
    std::cout << "3. Usun numer" << std::endl;
    std::cout << "4. Wyszukaj numer" << std::endl;
    std::cout << "5. Zaktualizuj numer" << std::endl;
    std::cout << "6. Zapisz i wyjdz" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Wybierz opcje: ";
}

void Interfejs::wyszukajNumer(Lista& listaNumerow, const std::string& numerDoWyszukania) {
    bool znaleziono = false;

    for (int i = 0; i < listaNumerow.rozmiar(); i++) {
        NumerTelefonu* numer = listaNumerow[i];
        if (numer->numer_telefonu == numerDoWyszukania) {
            znaleziono = true;
            numer->wyswietl();
            std::cout << "Znaleziono numer w bazie danych." << std::endl;
            break;
        }
    }

    if (!znaleziono) {
        std::cout << "Nie znaleziono numeru w bazie danych." << std::endl;
    }
}

void Interfejs::zaktualizujNumer(Lista& listaNumerow, int indeks) {
    indeks--;

    if (indeks >= 0 && indeks < listaNumerow.rozmiar()) {
        NumerTelefonu* numer = listaNumerow[indeks];
        std::string numerTelefonu, numerKierunkowy, opis;
        int typ = numer->typ;
        bool oszust = false;
        bool marketing = false;

        std::cout << "Aktualizacja danych numeru" << std::endl;
        std::cout << "Podaj numer telefonu: ";
        std::cin >> numerTelefonu;
        std::cout << "Podaj numer kierunkowy: ";
        std::cin >> numerKierunkowy;
        std::cout << "Podaj opis: ";
        std::cin.ignore();  // Ignorowanie znaku nowej linii z poprzedniego wczytania
        std::getline(std::cin, opis);

        if (typ == 1) { // NumerNegatywny
            std::cout << "Czy to numer oszusta (1-tak, 0-nie): ";
            std::cin >> oszust;
        } else if (typ == 2) { // NumerIrytujacy
            std::cout << "Czy to numer marketingowy (1-tak, 0-nie): ";
            std::cin >> marketing;
        }

        numer->numer_telefonu = numerTelefonu;
        numer->numer_kierunkowy = numerKierunkowy;
        numer->opis = opis;

        if (typ == 1) { // NumerNegatywny
            NumerNegatywny* numerNegatywny = dynamic_cast<NumerNegatywny*>(numer);
            numerNegatywny->czyOszust = oszust;
        } else if (typ == 2) { // NumerIrytujacy
            NumerIrytujacy* numerIrytujacy = dynamic_cast<NumerIrytujacy*>(numer);
            numerIrytujacy->czyMarketing = marketing;
        }

        std::cout << "Dane numeru zostaly zaktualizowane." << std::endl;
    } else {
        std::cout << "Niepoprawny indeks numeru." << std::endl;
    }
}

void Interfejs::uruchomInterfejs() {
    BazaDanych baza("bazaNumerow");
    Lista& listaNumerow = baza.listaNumerow;

    int opcja;
    std::string numer, kierunkowy, opis, szukanyNumer;
    int indeks;
    NumerTelefonu* nowyNumer = nullptr;

    while (true) {
        wyswietlMenu();
        std::cin >> opcja;

        switch (opcja) {
            case 1:
                listaNumerow.wyswietl_liste();
                break;

            case 2:
                int rodzajNumeru;
                std::cout << "Wybierz rodzaj numeru:" << std::endl;
                std::cout << "1. Negatywny" << std::endl;
                std::cout << "2. Irytujacy" << std::endl;
                std::cout << "3. Nieznany" << std::endl;
                std::cout << "4. Pozytywny" << std::endl;
                std::cin >> rodzajNumeru;

                std::cout << "Podaj numer telefonu: ";
                std::cin >> numer;
                std::cout << "Podaj numer kierunkowy: ";
                std::cin >> kierunkowy;
                std::cout << "Podaj opis: ";
                std::cin.ignore();  // Ignorowanie znaku nowej linii z poprzedniego wczytania
                std::getline(std::cin, opis);

                int numerTyp;

                if (rodzajNumeru >= 1 && rodzajNumeru <= 4) {
                    numerTyp = rodzajNumeru;
                } else {
                    std::cout << "Niepoprawny rodzaj numeru." << std::endl;
                    continue;
                }

                if (numerTyp == 1) {
                    bool oszust;
                    std::cout << "Czy to numer oszusta (1-tak, 0-nie): ";
                    std::cin >> oszust;
                    nowyNumer = new NumerNegatywny(numer, kierunkowy, opis, oszust);
                } else if (numerTyp == 2) {
                    bool marketing;
                    std::cout << "Czy to numer marketingowy (1-tak, 0-nie): ";
                    std::cin >> marketing;
                    nowyNumer = new NumerIrytujacy(numer, kierunkowy, opis, marketing);
                } else if (numerTyp == 3) {
                    nowyNumer = new NumerNieznany(numer, kierunkowy, opis);
                } else if (numerTyp == 4) {
                    nowyNumer = new NumerPozytywny(numer, kierunkowy, opis);
                } else {
                    std::cout << "Niepoprawny rodzaj numeru." << std::endl;
                    continue;
                }

                listaNumerow.dodaj_numer(nowyNumer);
                std::cout << "Dodano nowy numer do bazy danych." << std::endl;
                break;

            case 3:
                std::cout << "Podaj indeks numeru do usuniecia: ";
                std::cin >> indeks;
                listaNumerow.usun_numer(indeks);
                std::cout << "Numer zostal usuniety z bazy danych." << std::endl;
                break;

            case 4:
                std::cout << "Podaj numer do wyszukania: ";
                std::cin >> szukanyNumer;
                wyszukajNumer(listaNumerow, szukanyNumer);
                break;

            case 5:
                std::cout << "Podaj indeks numeru do zaktualizowania: ";
                std::cin >> indeks;
                zaktualizujNumer(listaNumerow, indeks);
                break;

            case 6:
                return;

            default:
                std::cout << "Niepoprawna opcja. Sprobuj ponownie." << std::endl;
                break;
        }
        std::cout << std::endl; // Dodaj odstęp po każdej opcji
    }
}
