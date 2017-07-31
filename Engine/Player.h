#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"
class Player
{
public:
	void DrawCross(int r, int g, int b, Graphics &gfx);
	void UpdateP(const Keyboard &kbd,Graphics &gfx,float dt);
	Vec2 GetPos() const;
	float GetPx() const;
	float GetPy() const;
	void SetPos(const Vec2 &pos_in);
	void SetInhi(bool inhi);
	bool GetInhi() const;
private:
	Vec2 pos = Vec2(400.0f,550.0f);
	Vec2 vel;
	bool inhibitV = false;
};