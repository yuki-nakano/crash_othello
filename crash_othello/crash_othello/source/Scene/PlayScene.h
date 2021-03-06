﻿#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "../common.h"

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す

private:
	void Skill(Piece piece[], int num);

	void KAMINOITTE(Piece piece[], int num);
	void HEBII(Piece piece[], int num);
	void MAGUNETTO();

private:
	int cutIn_y;
	int cutIn_x;
	int countCutIn;
	int countFrame;
	int phase;
	int turnNumber;
	int skillState[4];
	float theta;
	bool FinishedEffect;
	int powerGauge = 0;
	int variateGauge = 0;
	bool gaugeDirection = true;
	const int MaxPiece = 64;
	int posX = 0;
	int posY = 0;

	bool finishAnimation;
	int animationCount;

	bool Hanabi;
	int HanabiCount;
	int HanabiDistance;
	bool Magunetto;
	bool Inbijiburu;

	int pos_X_kami;
	int pos_Y_kami;

	bool GameFinish;

	int result[5];
	int countPiece[5];
	int resultColor[64];
	int resultCount;
	int resultFlameCount;

	int order[4];
	int orderNumber[4];
	int MaxOrder;

	bool FinishedGame = false;

	int TextureBackGround_posX[3];
	int TextureBackGround_posY[3];

	int TextureBackGround_posX_2[3];
	int TextureBackGround_posY_2[3];


};

#endif // !PALYSCENE_H