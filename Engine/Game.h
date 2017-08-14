/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Object.h"
#include "Fire.h"
#include <random>
#include "Score.h"
#include "EnemyFire.h"
#include "FrameTimer.h"
#include "Sound.h"
#include "Stars.h"
#include "Upgrade.h"
#include "FrUpgrade.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void DrawTitleScreen(int x, int y);
	void DrawGameOver(int x, int y);
	void NewStage(int objectnumber1, int upgradecounter1);
private:
	int objectnumber = 10;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	std::uniform_real_distribution<float> vDist;
	std::uniform_real_distribution<float> sDist;
	std::uniform_int_distribution<int> pupgrade;
	MainWindow& wnd;
	Graphics gfx;
	bool collide = false;
	bool Change_Color = false;
	Player player;
	Object object[30];
	Fire fire[4];
	Score s;
	EnemyFire enemf[30];
	FrameTimer ft;
	Stars star[599];
	Upgrade upgrade[2];
	FrUpgrade frupgrade[2];
	int fcount = 0;
	int fcount1 = 0;
	bool permitfire = false;
	bool isStarted = false;
	bool isOver = false;
	bool Replay = false;
	int DesCount = 0;
	float adderx = 100.0f;
	float addery = 60.0f;
	Sound start;
	Sound endwin;
	Sound plaser;
	Sound elaser;
	Sound backg;
	Sound endlose;
	Sound upgradeup;
	Sound upgradedown;
	bool firstGameStart = true;
	bool winGame = true;
	bool plaserstart = true;
	bool elaserstart = true;
	bool background = true;
	bool loseGame = true;
	bool wupgrade = true;
	bool wdowngrade = true;
	bool playerlost = false;
	bool playerwon = false;
	int stage = 1;
	float framecounter = 0.0f;
	float framecounterlimit = 30.0f;
	int fireborcounter = 0;
	int defaultfcount = 1;
	int upgrades[4] = {-1,-1,-1,-1};
	int upgradecounter = 4;
	float enemfcd[30];
	bool acceptu = false;
	int randomizer = 0;
	float pausetimer = 0.0f;
	bool pause = false;
};