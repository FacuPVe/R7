#pragma once
#include "Personaje.h"
#include  <iostream>
using namespace std;
// Constructor
Personaje::Personaje(int pHp, std::string pName, int pAttack, int pPosicionX, int pPosicionY) {
	hp = pHp;
	name = pName;
	attack = pAttack;
	posicionX = pPosicionX;
	posicionY = pPosicionY;
}

Personaje::Personaje()
{
}

// Getters
int Personaje::getHp()
{
	return hp;
}
string Personaje::getName()
{
	return name;
}
int Personaje::getAttack() {
	return attack;
}
int Personaje::getPosicionX()
{
	return posicionX;
}
int Personaje::getPosicionY()
{
	return posicionY;
}

// Setters
void Personaje::setHp(int php)
{
	hp = php;
}
void Personaje::setName(string pname)
{
	name = pname;
}
void Personaje::setAttack(int pattack)
{
	attack = pattack;
}
void Personaje::setPosicionX(int pPosicionX)
{
	posicionX = pPosicionX;
}
void Personaje::setPosicionY(int pPosicionY)
{
	posicionY = pPosicionY;
}

// Métodos propios
void Personaje::printStatus() {
	cout << "El nombre del personaje es " << getName() << " y tiene una vida de " << getHp() << endl;
}
