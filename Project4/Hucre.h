#pragma once
enum RENK
{
	RENK_SIYAH = 0,
	RENK_KOYUMAVI = 1,
	RENK_KOYUYESIL = 2,
	RENK_KOYUKIRMIZI = 4,
	RENK_KOYUMOR = 5,
	RENK_KOYUSARI = 6,
	RENK_KOYUBEYAZ = 7,
	RENK_GRI = 8,
	RENK_MAVI = 9,
	RENK_YESIL = 10,
	RENK_ACIKMAVI = 11,
	RENK_KIRMIZI = 12,
	RENK_PEMBE = 13,
	RENK_SARI = 14,
	RENK_BEYAZ = 15
};
enum YON
{
	YON_SOL=1,
	YON_SAG=2,
	YON_YUKARI=3,
	YON_ASAGI=4
};

struct YilanHucresi
{
	int x;
	int y;
	char karakter;
	RENK renk;
	YON yon;
};
struct SahneHucresi
{
	char karakter;
	RENK renk;
};