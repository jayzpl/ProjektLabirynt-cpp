//Projekt Labiryny Jakub Zasada grupa 7 EiT 181176
#include <iostream>
#include <cstdlib>
#include "conio2.h"


using namespace std;

const int MAX_SZ=40;
const int MAX_WYS = 20;
int lvl;
int x = 0;
int y = 0;
char znak=219;




void wyswietl(char mapa[][MAX_SZ],char znak, int x, int y, char kierunek)
{
	system("cls");
	if(lvl == 1){ cout << "LEVEL 1" << endl; mapa[19][39] = '@';}
	if(lvl == 2) { cout << "LEVEL 2" << endl; mapa[15][25] = '@';}
	if (lvl == 3){ cout << "LEVEL 3" << endl; mapa[0][0] = '*';}
	
	for (int i = 0; i < MAX_WYS; i++) {
		for (int j = 0; j < MAX_SZ; j++) {
			cout << mapa[i][j];
			if (j == MAX_SZ - 1) {
				cout << endl;
			}
		}
	}
	gotoxy(48, 2);
	cputs("Jakub Zasada");
	gotoxy(48, 3);
	cputs("181176");

	gotoxy(48, 5);
	cputs("Legenda:");
	gotoxy(48, 6);
	cputs("w,s = ruch przod / tyl");
	gotoxy(48, 7);
	cputs("a,d = obrot o 90 stopni lewo prawo");
	gotoxy(48, 8);
	cputs("spacja  = uzyj komorki");
	gotoxy(48, 9);
	cputs("esc   = wyjscie z gry");
	gotoxy(48, 10);
	cputs("@ = przejscie ");
	gotoxy(48, 11);
	cputs("* = skarb ");
	gotoxy(48, 12);
	cout << znak <<" = wolne pole";
	gotoxy(48, 13);
	cputs("<,A,V,> = gracz");
}


void poruszaj(char mapa[][MAX_SZ],int x, int y, bool warunek, char kierunek)
{
	char ruch;
	char znaczek[4] = { '>','V','<','A' };
	int licznik = 0;

	
		while (warunek) {
			ruch = getch();

			switch (ruch)
			{
			case 'd': 
				licznik++;
				if (licznik > 3) {
				licznik = 0;
				}
				mapa[y][x] = znaczek[licznik];
				kierunek = znaczek[licznik];
				break;
			
			case 'a':
				licznik--;
				if (licznik < 0) {
					licznik = 3;
				}
				mapa[y][x] = znaczek[licznik];
				kierunek = znaczek[licznik];
				break;

			case 'w':
				if (licznik == 0) {
					if (mapa[y][x + 1] == ' ') { continue; }
					else {
						if (x + 1 < MAX_SZ) {
							mapa[y][x + 1] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							x++;
						}
						else {
							continue;
						}
					}
				}
				if (licznik == 1) {
					if (mapa[y + 1][x] == ' ') { continue; }
					else {
						if (y + 1 < MAX_WYS) {
							mapa[y + 1][x] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							y++;
						}
						else {
							continue;
						}
					}
				}
				if (licznik == 2) {
					if (mapa[y][x - 1] == ' ') { continue; }
					else {
						if (x - 1 >= 0) {
							mapa[y][x - 1] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							x--;
						}
						else {
							continue;
						}
					}
				}
				if (licznik == 3) {
					if (mapa[y - 1][x] == ' ') { continue; }
					else {
						if (y - 1 >= 0) {
							mapa[y - 1][x] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							y--;
						}
						else {
							continue;
						}
					}
				}
				break;

			case 's':
				if (licznik == 2) {
					if (mapa[y][x + 1] == ' ') { continue; }
					else {
						if (x + 1 < MAX_SZ) {
							mapa[y][x + 1] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							x++;
						}
						else {
							continue;
						}
					}
				}
				if (licznik == 3) {
					if (mapa[y + 1][x] == ' ') { continue; }
					else {
						if (y + 1 < MAX_WYS) {
							mapa[y + 1][x] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							y++;
						}
						else {
							continue;
						}
					}
				}
				if (licznik == 0) {
					if (mapa[y][x - 1] == ' ') { continue; }
					else {
						if (x - 1 >= 0) {
							mapa[y][x - 1] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							x--;
						}
						else {
							continue;
						}
					}
				}
				if (licznik == 1) {
					if (mapa[y - 1][x] == ' ') { continue; }
					else {
						if (y - 1 >= 0) {
							mapa[y - 1][x] = znaczek[licznik];
							kierunek = znaczek[licznik];
							mapa[y][x] = 219;
							y--;
						}
						else {
							continue;
						}
					}
				}
				break;
			
			case ' ':
				if (mapa[y][x]=='@' or mapa[y][x] == '*') { lvl++; warunek = false; }
				else { continue; }
				break;

			case 27:
				lvl = 5;
				warunek = false;
				break;
		
			default:
				continue;
				break;
			}

			wyswietl(mapa, znak,x,y,kierunek);
				
		}
}
void stworz(char mapa[][MAX_SZ]) {
	for (int i = 0; i < MAX_WYS; i++)
	{
		for (int j = 0; j < MAX_SZ; j++)
		{
			mapa[i][j] = 219;
		}
	}
}

void sciany_jeden(char mapa[][MAX_SZ]) {
	for (int i = 0; i < MAX_WYS; i++) {
		for (int j = 1; j < MAX_SZ-1; j++) {
			if (j % 2 != 0) {
				mapa[i][j] = ' ';
			}
			if (i % 9 == 0 and j<13) {
				mapa[i][j] = ' ';
			}
			if (j<20 and i%5==0) {
				mapa[i][j] = znak;
			}
			if (j > 20 and i % 7 == 0) {
				mapa[i][j] = znak;
			}
			if (i == 0 and j == 33) { mapa[i][j] = ' '; }
		}
	}
}
void sciany_dwa(char mapa[][MAX_SZ]) {
	for (int i = 0; i < MAX_WYS; i++) {
		for (int j = 1; j < MAX_SZ - 1; j++) {
			if (j % 3 != 0) {
				mapa[i][j] = ' ';
			}
			if (j < 10 and i % 19 == 0) {
				mapa[i][j] = znak;
			}
			if (j > 10 and i % 11 == 0) {
				mapa[i][j] = znak;
			}
			if (i == 0 and j == 33) { mapa[i][j] = ' '; }
			if (i == 17) { mapa[i][10] = znak; mapa[i][11] = znak;}
		}
	}
}
void sciany_trzy(char mapa[][MAX_SZ]) {
	for (int i = 0; i < MAX_WYS; i++) {
		for (int j = 0; j < MAX_SZ; j++) {
			if (i%2!=0) {
				mapa[i][j] = ' ';
			}
			if (j % 9 == 0) {
				mapa[i][j] = znak;
			}
			if (i % 2 != 0 and j < 19 and i>11) {
				mapa[i][j] = ' ';
			}
		}
	}
}


void level_one(char mapa[][MAX_SZ],bool warunek, char kierunek)
{
		clrscr();
		if (lvl == 1) {
			stworz(mapa);
			sciany_jeden(mapa);
			x = 0;
			y = 0;
			cout << "LEVEL 1" << endl;
			mapa[0][0] = '>';
			mapa[19][39] = '@';
			wyswietl(mapa,znak,x,y,kierunek);
			poruszaj(mapa,x,y,warunek,kierunek);
		}
		if(lvl == 2)
		{
			warunek = true;
			stworz(mapa);
			sciany_dwa(mapa);
			x = 1;
			y = 0;
			cout << "LEVEL 2" << endl;
			mapa[0][1] = '>';
			mapa[15][25] = '@';
			mapa[19][39] = 219;
			wyswietl(mapa,znak,x,y,kierunek);
			poruszaj(mapa,x,y,warunek,kierunek);
		}
		if (lvl == 3)
		{
			warunek = true;
			stworz(mapa);
			sciany_trzy(mapa);
			x = 25;
			y = 15;
			cout << "LEVEL 3" << endl;
			mapa[15][25] = 219;
			mapa[0][0] = '*';
			mapa[15][25] = '>';
			wyswietl(mapa,znak,x,y,kierunek);
			poruszaj(mapa, x, y,warunek,kierunek);
		}
		if(lvl == 4)
		{	
			gotoxy(1, 22);
			cout << "GRATULACJE WYGRALES !" << endl;
		}
		if (lvl == 5)
		{
			gotoxy(1, 22);
			cout << "GAME OVER" << endl;
		}
}


int main()
{
	_setcursortype(_NOCURSOR);
	char mapa[MAX_WYS][MAX_SZ];
	cout << "Hello" << endl;
	lvl = 1;
	bool warunek;
	char kierunek = '>';
	warunek = true;
	level_one(mapa,warunek,kierunek);
}
