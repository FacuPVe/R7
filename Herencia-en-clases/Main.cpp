#include <iostream>
#include <ctime>
#include "Personaje.h"
#include "EnemigoFinal.h"

using namespace std;

void crearMapa(string moves[3], int mapa[5][5]) {
	for (size_t i = 0; i < 5; i++) 
	{
		for (size_t j = 0; j < 5; j++)
		{
			if (mapa[i][j] == 0 || mapa[i][j] == 2 || mapa[i][j] == 1)
			{
				cout << moves[0];
			}
			else if (mapa[i][j] == 3)
			{
				cout << moves[1];
			}
			else
			{
				cout << moves[2];
			}
		}
		cout << "\n";
	}
}

// Batalla contra enemigos
void batalla(Personaje& heroe, Personaje& enemigo) {
	while (heroe.getHp() > 0 && enemigo.getHp() > 0) {
		enemigo.setHp(enemigo.getHp() - heroe.getAttack());
		if (enemigo.getHp() <= 0) {
			cout << "El " << enemigo.getName() << " ha sido derrotado!\n";
			return;
		}
		heroe.setHp(heroe.getHp() - enemigo.getAttack());
		if (heroe.getHp() <= 0) {
			cout << "Has sido derrotado por el " << enemigo.getName() << "... Has perdido...\n";
			exit(0);
		}
	}
}

// Batalla contra el enemigo final
void batallaFinal(Personaje& heroe, EnemigoFinal& boss) {
	while (heroe.getHp() > 0 && boss.getHp() > 0) {
		boss.setHp(boss.getHp() - heroe.getAttack());
		if (boss.getHp() <= 0) {
			cout << "¡Has sobrevivido y conseguido derrotar al enemigo final!\n¡Has ganado felicidades!\n";
			return;
		}
		int ataque = rand() % 3;
		if (ataque == 0) {
			heroe.setHp(heroe.getHp() - boss.getAttack());
		}
		else if (ataque == 1) {
			heroe.setHp(heroe.getHp() - boss.getMegaAttack());
		}
		else {
			heroe.setHp(heroe.getHp() - boss.getHiperAttack());
		}

		if (heroe.getHp() <= 0) {
			cout << "Te ha derrotado el enemigo final... Has perdido, has estado tan cerca de poder escapar...\n";
			exit(0);
		}
	}
}

int main() {
	setlocale(LC_ALL, "en_US.UTF-8");

	srand(time(NULL));

	int num;
	int mapa[5][5];
	string moves[3] = { " - ", " * ", " ! " };

	Personaje heroe(1500, "Heroe", 150, 4, 0);
	Personaje enemigo1(150, "Enemigo 1", 50, 1, 0);
	Personaje enemigo2(150, "Enemigo 2", 30, 2, 0);
	Personaje enemigo3(160, "Enemigo 3", 20, 3, 0);
	Personaje enemigo4(305, "Enemigo 4", 15, 4, 0);
	EnemigoFinal boss(1000, "Boss", 150, 0, 0, 300, 400);

	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			mapa[i][j] = 0;
		}
	}

	// Carga de los enemigos en columnas aleatorias
	// Enemigo 1
	num = rand() % 5;
	mapa[1][num] = 1;
	enemigo1.setPosicionY(num);
	// Enemigo 2
	num = rand() % 5;
	mapa[2][num] = 1;
	enemigo2.setPosicionY(num);
	// Enemigo 3
	num = rand() % 5;
	mapa[3][num] = 1;
	enemigo3.setPosicionY(num);
	// Enemigo 4
	num = rand() % 5;
	mapa[4][num] = 1;
	enemigo4.setPosicionY(num);

	// Carga del enemigo final
	num = rand() % 5;
	mapa[0][num] = 2;
	boss.setPosicionY(num);

	// Carga del héroe en la primera fila en una columna aleatoria
	do {
		num = rand() % 5;
		if (mapa[4][num] == 0) {
			mapa[4][num] = 3;
			heroe.setPosicionY(num);
		}
	} while (mapa[4][num] != 3);

	while (heroe.getHp() > 0 && boss.getHp() > 0) {
		crearMapa(moves, mapa);

		cout << "Movimiento (w-a-s-d): ";
		char letra;
		cin >> letra;
		int x = heroe.getPosicionX();
		int y = heroe.getPosicionY();
		int antX = x;
		int antY = y;

		if (letra == 's' && x != 4) {
			x += 1;
		}
		else if (letra == 'w' && x != 0) {
			x -= 1;
		}
		else if (letra == 'd' && y != 4) {
			y += 1;
		}
		else if (letra == 'a' && y != 0) {
			y -= 1;
		}
		else {
			cout << "Tecla o movimiento incorrecto\n";
			continue;
		}

		if (mapa[x][y] == 0) {
			mapa[x][y] = 3;
			mapa[antX][antY] = 0;
		}
		else if (mapa[x][y] == 1) {
			cout << "¡Te has encontrado con un enemigo!\n";
			if (x == enemigo1.getPosicionX() && y == enemigo1.getPosicionY()) {
				batalla(heroe, enemigo1);
			}
			else if (x == enemigo2.getPosicionX() && y == enemigo2.getPosicionY()) {
				batalla(heroe, enemigo2);
			}
			else if (x == enemigo3.getPosicionX() && y == enemigo3.getPosicionY()) {
				batalla(heroe, enemigo3);
			}
			else if (x == enemigo4.getPosicionX() && y == enemigo4.getPosicionY()) {
				batalla(heroe, enemigo4);
			}
			mapa[x][y] = 3;
			mapa[antX][antY] = 0;
		}
		else if (mapa[x][y] == 2) {
			cout << "!Has encontrado la salida y el boss ha aparecido!\n";
			batallaFinal(heroe, boss);
			mapa[x][y] = 3;
			mapa[antX][antY] = 0;
		}

		heroe.setPosicionX(x);
		heroe.setPosicionY(y);
	}

	return 0;
}