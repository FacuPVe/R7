#include "EnemigoFinal.h"

using namespace std;
// Constructor
EnemigoFinal::EnemigoFinal(int pHp, 
                           string pName, 
                           int pAttack, 
                           int pPosicionX, 
                           int pPosicionY, 
                           int pMegaAttack, 
                           int pHiperAttack) : Personaje(pHp, 
                                                         pName, 
                                                         pAttack, 
                                                         pPosicionX, 
                                                         pPosicionY) {megaAttack = pMegaAttack;
                                                                      hiperAttack = pHiperAttack;
}

EnemigoFinal::EnemigoFinal() 
{
}

// Getters
int EnemigoFinal::getMegaAttack() {
    return megaAttack;
}
int EnemigoFinal::getHiperAttack() {
    return hiperAttack;
}

// Setters
void EnemigoFinal::setMegaAttack(int pMegaAttack)
{
    megaAttack = pMegaAttack;
}
void EnemigoFinal::setHiperAttack(int pHiperAttack)
{
    hiperAttack = pHiperAttack;
}

// Métodos propios
void EnemigoFinal::printAllStats() {
    cout << "El nombre del enemigo final es " << getName() << endl;
    cout << "La vida del enemigo final es " << getHp() << endl;
    cout << "El ataque normal del enemigo final es " << getAttack() << endl;
    cout << "La posición es " << getPosicionX() << "," << getPosicionY() << endl;
    cout << "El mega ataque del enemigo final es " << getMegaAttack() << endl;
    cout << "El hiper ataque del enemigo final es " << getHiperAttack() << endl;
}