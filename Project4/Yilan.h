#pragma once
#include "Hucre.h"

class Yilan
{
public:
	Yilan();
	void			hareketEt();
	void			kuyrugaEkle();
	YilanHucresi	hucreGetir(int index);
	int				yilanBoyuGetir();
	void			yilanYonAta(YON yon);
private:
	void hucreHareketEt(int index);

	static const int maxYilanBoyu = 500;
	
	int		yilanBoyutu;
	
	YilanHucresi kuyruk[maxYilanBoyu];
};
