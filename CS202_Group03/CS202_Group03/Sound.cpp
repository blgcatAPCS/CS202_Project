#include "header/header.h"
void BackGround()
{
	if (checkSound)
		PlaySound(TEXT("DummyUndertaleOST-TobyFox.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void Enter()
{
	if (checkSound)
		PlaySound(TEXT("enter.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void Tap()
{
	if (checkSound)
		PlaySound(TEXT("tap.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
}
void DrawMusic()
{
	if (checkSound)
		PlaySound(TEXT("Undertale OST_ 015 - sans.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void WinMusic()
{
	if (checkSound)
		PlaySound(TEXT("Undertale OST_ 046 - Spear of Justice.wav"), NULL, SND_LOOP | SND_ASYNC);
}
void LoseMusic()
{
	if (checkSound)
		PlaySound(TEXT("Undertale OST_ 011 - Determination.wav"), NULL, SND_LOOP | SND_ASYNC);
}


//main
