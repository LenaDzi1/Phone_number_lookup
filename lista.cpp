#include "lista.h"
#include "NumerIrytujacy.h"
#include "NumerNegatywny.h"
#include "NumerNieznany.h"
#include "NumerPozytywny.h"
#include "NumerTelefonu.h"
#include "kraj.h"
#include <iostream>


Lista::Lista(){
    pierwszy = 0;
}

void Lista::wyswietl_liste()
{
	NumerTelefonu *temp = pierwszy;
    int licznik = 1;

	while (temp){
        std::cout << licznik << ". ";
		temp->wyswietl();
		temp=temp->nastepny;
        licznik++;
	}
}


void Lista::dodaj_numer(NumerTelefonu *nowy){

    if(rozmiarListy==0){
        pierwszy=nowy;
        rozmiarListy++;
    }else{
        NumerTelefonu *temp = pierwszy;

        while (temp->nastepny){
            temp=temp->nastepny;
        }

        temp->nastepny = nowy;
        rozmiarListy++;
    }
}

void Lista::usun_numer(int indeks){

    indeks--;

    if(indeks>=0 && indeks<rozmiarListy){
        if(indeks==0){

            NumerTelefonu* temp = pierwszy;
            pierwszy = temp->nastepny;
            delete temp;

        }else{

            NumerTelefonu *temp = pierwszy;

            int i=0;

            while (temp){
                if((i+1)==indeks){
                    break;
                }
                temp=temp->nastepny;
                i++;
            }


            if(temp->nastepny->nastepny==0){
                delete temp->nastepny;
                temp->nastepny = 0;
            }else{
                NumerTelefonu* doUsuniecia = temp->nastepny;
                temp->nastepny = temp->nastepny->nastepny;
                delete doUsuniecia;
            }

        }

        rozmiarListy--;
    }
}

int Lista::rozmiar(){
    return rozmiarListy;
}

NumerTelefonu* Lista::operator[](int indeks){
    if (indeks >= 0 && indeks < rozmiarListy) {
        NumerTelefonu* temp = pierwszy;
        for (int i = 0; i < indeks; i++) {
            temp = temp->nastepny;
        }
        return temp;
    }else{
        return nullptr;
    }
}

