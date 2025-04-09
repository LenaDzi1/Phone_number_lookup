#include "Dane.h"
#include "bazadanych.h"
#include "Rekord.h"
#include <iostream>
#include <fstream>
#include <sstream>

Dane::Dane(std::string wartosc) {
    nastepny = 0;
    tresc = wartosc;
}