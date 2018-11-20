#include "Sahne.h"
#include<iostream>
#include <Windows.h>
using namespace std;
Sahne::Sahne()
{
}

void Sahne::basla()
{
	kursorGizle();

	while (true)
	{
		pozisyonAta(0, 0);

		temizle();
		klavyeOku();
		klavyeKontrol();
		yilan.hareketEt();
		yilaniYerlestir();
		sinirlariOlustur();
		
		ciz();

		
		
	}
}

void Sahne::ciz()
{
	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			renkAta(ekran[x][y].renk);
			cout << ekran[x][y].karakter;
		}
		cout << endl;
	}
}

void Sahne::kursorGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Sahne::yilaniYerlestir()
{
	int yilanBoyu = yilan.yilanBoyuGetir();

	for (int i = 0; i < yilanBoyu; i++)
	{
		YilanHucresi hucre = yilan.hucreGetir(i);

		ekran[hucre.x][hucre.y].renk = hucre.renk;
		ekran[hucre.x][hucre.y].karakter = hucre.karakter;
	}

}

void Sahne::klavyeOku()
{
	for (int x = 0; x < 256; x++)
		klavyeTuslari[x] = (char)(GetAsyncKeyState(x) >> 8);
}

void Sahne::klavyeKontrol()
{
	if (klavyeTuslari['A'])
		yilan.yilanYonAta(YON_SOL);
	if (klavyeTuslari['D'])
		yilan.yilanYonAta(YON_SAG);
	if (klavyeTuslari['W'])
		yilan.yilanYonAta(YON_YUKARI);
	if (klavyeTuslari['S'])
		yilan.yilanYonAta(YON_ASAGI);
}

void Sahne::pozisyonAta(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Sahne::renkAta(RENK renk)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), renk);
	
}

void Sahne::sinirlariOlustur()
{
	for (int x = 0; x < genislik; x++)
	{
		ekran[x][0].karakter = 219;
		ekran[x][0].renk = RENK_ACIKMAVI;
		ekran[x][yukseklik - 1].karakter = 219;
		ekran[x][yukseklik - 1].renk = RENK_ACIKMAVI;
	}
	for (int y = 0; y < yukseklik; y++)
	{
		ekran[0][y].karakter = 219;
		ekran[0][y].renk = RENK_ACIKMAVI;
		ekran[genislik - 1][y].karakter = 219;
		ekran[genislik - 1][y].renk = RENK_ACIKMAVI;
	}
}

void Sahne::temizle()
{
	for (int x = 0; x < genislik; x++)
	{
		for (int y = 0; y < yukseklik; y++)
		{
			ekran[x][y].karakter = ' ';
			ekran[x][y].renk = RENK_KIRMIZI;
		}
	}
}
