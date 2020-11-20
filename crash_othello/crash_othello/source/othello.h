#ifndef OTHELLO_H
#define OTHELLO_H

#include "DxLib.h"

//削除
const int row = 8;
const int col = 8;

enum Piece
{
	kBlack,
	kWhite,
	kNone
};

enum Direction
{
	kUp,
	kUpRight,
	kRight,
	kDownRight,
	kDown,
	kDownLeft,
	kLeft,
	kUpLeft
};

class Othello
{
public:
	void InitBoard(int map[][row]);
	void TurnOverMethod(int* X, int* Y, int map[][row], Piece phase);
	void DrawOthello(int map[][row]);
	void MoveCursor(int* X, int* Y);
private:
	void TurnOver(Direction* direction, int* X, int* Y, int map[][row], Piece phase);
	void ChangCoordinate(Direction direction, int* X, int* Y, bool WhichDirection);
private:
	int CountTurnOver;
	bool CanTurnOver;
	int CountFrame = 0;
public:
	bool IsInitialized;
	int X;
	int Y;
};

#endif // !OTHELLO_H
