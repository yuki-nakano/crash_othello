#ifndef OTHELLO_H
#define OTHELLO_H

#include "common.h"

const int row = 8;
const int col = 8;

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
	void TurnOverMethod(int* X, int* Y, int map[][row], Color phase);

private:
	void TurnOver(Direction* direction, int* X, int* Y, int map[][row], Color phase);
	void ChangCoordinate(Direction direction, int* X, int* Y, bool WhichDirection);

private:
	int CountTurnOver = 0;
	bool CanTurnOver = false;
	int CountFrame = 0;

public:
	bool IsInitialized = false;
	int X = 0;
	int Y = 0;
};

#endif // !OTHELLO_H
