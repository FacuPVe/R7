#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje {
private:
    int megaAttack;
    int hiperAttack;

public:
    // Constructor con elementos de la clase padre y propia
    EnemigoFinal(
        int pHp, 
        string pName, 
        int pAttack, 
        int pPosicionX, 
        int pPosicionY, 
        int pMegaAttack, 
        int pHiperAttack);
    EnemigoFinal();

    // Getters
    int getMegaAttack();
    int getHiperAttack();

    // Setters
    void setMegaAttack(int pMegaAttack);
    void setHiperAttack(int pHiperAttack);

    // Métodos propios
    void printAllStats();
};
