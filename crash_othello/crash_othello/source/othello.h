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
	int CountTurnOver;
	bool CanTurnOver;
	int CountFrame = 0;

public:
	bool IsInitialized;
	int X;
	int Y;
};

#endif // !OTHELLO_H
