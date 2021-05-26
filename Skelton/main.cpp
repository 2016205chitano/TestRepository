#include<DxLib.h>
#include"Geometry.h"
#include<cmath>

bool IsHit(const Rect& rcA,const Rect& rcB) {
	if (fabsf(rcA.center.x - rcB.center.x) > rcA.w + rcB.w) {
		return false;
	}
	if (fabsf(rcA.center.y - rcB.center.y) > rcA.h + rcB.h) {
		return false;
	}
	return true;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true);
	SetWindowText(L"2016205_èºîˆå˙éu");
	DxLib_Init();

	SetDrawScreen(DX_SCREEN_BACK);

	Rect rcA = { 100,100,50,50 };
	Rect rcB = { 400,300,75,125 };

	char keystate[256];
	while (ProcessMessage() != -1) {
		ClearDrawScreen();
		GetHitKeyStateAll(keystate);
		constexpr float speed = 4.0f;
		//è„
		if (keystate[KEY_INPUT_UP])
		{
			rcA.center.y -= speed;
		}
		if (keystate[KEY_INPUT_DOWN])
		{
			rcA.center.y += speed;
		}
		if (keystate[KEY_INPUT_LEFT])
		{
			rcA.center.x -= speed;
		}
		if (keystate[KEY_INPUT_RIGHT])
		{
			rcA.center.x += speed;
		}

		UINT32 color = 0xffffff;
		if (IsHit(rcA, rcB))
		{
			color = 0xffaaaa;
			float diffX = rcB.center.x - rcA.center.x;
			float diffY = rcB.center.y - rcA.center.y;
			float signX = diffX < 0 ? -1.0f : 1.0f;
			float signY = diffY < 0 ? -1.0f : 1.0f;
			diffX = (rcA.w + rcB.w) - fabsf(rcA.center.x - rcB.center.x);
			diffY = (rcA.h + rcB.h) - fabsf(rcA.center.y - rcB.center.y);
			if (diffX < diffY) {
				rcA.center.x -= signX * diffX;
			}
			else {
				rcA.center.y -= signY * diffY;
			}
		}

		DrawBox(rcA.Left(), rcA.Top(),
			rcA.Right(), rcA.Bottom(), color, true);

		DrawBox(rcB.Left(), rcB.Top(),
			rcB.Right(), rcB.Bottom(), color, true);

		ScreenFlip();

	}
	DxLib_End();
	return 0;
}

	
