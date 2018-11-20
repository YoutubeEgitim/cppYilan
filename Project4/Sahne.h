#pragma once

#include "Yilan.h"


class Sahne
{
public:
	Sahne();
	void basla();
	
private:
	static const int genislik = 80;
	static const int yukseklik = 20;
	
	void pozisyonAta(int x, int y);
	void renkAta(RENK renk);
	void sinirlariOlustur();
	void temizle();
	void ciz();
	void kursorGizle();
	void yilaniYerlestir();
	void klavyeOku();
	void klavyeKontrol();

	SahneHucresi ekran[genislik][yukseklik];
	Yilan   yilan;
	char klavyeTuslari[256];
};
