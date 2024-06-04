#pragma once
#include <iostream>
#include <string>

using namespace std;

class Personaje {
private:
    int hp;
    string name;
    int attack;
    int posicionX;
    int posicionY;

public:
    // Constructor
    Personaje(int pHp, string pName, int pAttack, int pPosicionX, int pPosicionY);
    Personaje();

    // Getters
    int getHp();
    
    string getName();
    
    int getAttack();
    
    int getPosicionX();
    int getPosicionY();

    // Setters
    void setHp(int php);

    void setName(string pname);
    
    void setAttack(int pattack);
    
    void setPosicionX(int pPosicionX);
    void setPosicionY(int pPosicionY);

    // Métodos propios
    void printStatus();
};
