#include "Yilan.h"
#include<iostream>
Yilan::Yilan()
{
	yilanBoyutu = 1;
	kuyruk[0].x = 20;
	kuyruk[0].y = 10;
	kuyruk[0].renk =(RENK)(210+rand()%9);
	kuyruk[0].karakter = 219;
	kuyruk[0].yon = YON_SAG;
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
	kuyrugaEkle();
}

void Yilan::hareketEt()
{
	for (int i = yilanBoyutu - 1; i > 0; i--)
	{
		hucreHareketEt(i);

		kuyruk[i].yon = kuyruk[i - 1].yon;
	}
	hucreHareketEt(0);
}

void Yilan::kuyrugaEkle()
{
	int index = yilanBoyutu - 1;

	int x = kuyruk[index].x;
	int y = kuyruk[index].y;

	switch (kuyruk[index].yon)
	{
	case YON_SOL:
		x++;
		break;
	case YON_SAG:
		x--;
		break;
	case YON_YUKARI:
		y++;
		break;
	case YON_ASAGI:
		y--;
		break;
	}
	kuyruk[index + 1].x = x;
	kuyruk[index + 1].y = y;
	kuyruk[index + 1].yon = kuyruk[index].yon;
	kuyruk[index + 1].karakter = kuyruk[index].karakter;
	kuyruk[index + 1].renk = (RENK)(210 + rand() % 9);
	yilanBoyutu++;
}

YilanHucresi Yilan::hucreGetir(int index)
{
	return kuyruk[index];

}

int Yilan::yilanBoyuGetir()
{
	return yilanBoyutu;
	
}

void Yilan::yilanYonAta(YON yon)
{
	if (yon == YON_SAG && kuyruk[0].yon != YON_SOL)
	{
		kuyruk[0].yon = yon;
	}
	if (yon == YON_SOL && kuyruk[0].yon != YON_SAG)
	{
		kuyruk[0].yon = yon;
	}
	if (yon == YON_YUKARI && kuyruk[0].yon != YON_ASAGI)
	{
		kuyruk[0].yon = yon;
	}
	if (yon == YON_ASAGI && kuyruk[0].yon != YON_YUKARI)
	{
		kuyruk[0].yon = yon;
	}
}

void Yilan::hucreHareketEt(int index)
{
	switch (kuyruk[index].yon)
	{
	case YON_SOL:
		kuyruk[index].x--;
		break;
	case YON_SAG:
		kuyruk[index].x++;
		break;
	case YON_YUKARI:
		kuyruk[index].y--;
		break;
	case YON_ASAGI:
		kuyruk[index].y++;
		break;
	}
}
