#include "othello.h"

void Othello::InitBoard(int map[][row])
{
	if (!IsInitialized)
	{
		for (int Y = 0; Y < col; Y++)
		{
			for (int X = 0; X < row; X++)
			{
				if (X == row / 2 - 1 && Y == col / 2)
				{
					map[Y][X] = Color::kBlack;
				}
				else if (X == row / 2 - 1 && Y == col / 2 - 1)
				{
					map[Y][X] = Color::kWhite;
				}
				else if (X == row / 2 && Y == col / 2 - 1)
				{
					map[Y][X] = Color::kBlue;
				}
				else if (X == row / 2 && Y == col / 2)
				{
					map[Y][X] = Color::kRed;
				}
				else
				{
					map[Y][X] = Color::kBlank;
				}
			}
		}
		IsInitialized = true;
	}
}

void Othello::TurnOverMethod(int* X, int* Y, int map[][row], Color phase)
{
	Direction direction;
	direction = Direction::kUp;

	int TmpX = *X;
	int TmpY = *Y;

	for (int i = 0; i < 8; i++)
	{
		switch (i)
		{
		case 0:
			direction = Direction::kUp;
			break;
		case 1:
			direction = Direction::kUpRight;
			break;
		case 2:
			direction = Direction::kRight;
			break;
		case 3:
			direction = Direction::kDownRight;
			break;
		case 4:
			direction = Direction::kDown;
			break;
		case 5:
			direction = Direction::kDownLeft;
			break;
		case 6:
			direction = Direction::kLeft;
			break;
		case 7:
			direction = Direction::kUpLeft;
			break;
		}

		CountTurnOver = 0;
		CanTurnOver = false;
		TurnOver(&direction, X, Y, map, phase);
		*X = TmpX;
		*Y = TmpY;
	}
}

void Othello::TurnOver(Direction* direction, int* X, int* Y, int map[][row], Color phase)
{
	CountTurnOver++;
	switch (*direction)
	{
	case Direction::kUp:
		if (*Y - 1 < 0)
		{
			CanTurnOver = false;
			return;
		}
		break;
	case Direction::kUpRight:
		if (*X + 1 >= row || *Y - 1 < 0)
		{
			CanTurnOver = false;
			return;
		}
		break;
	case Direction::kRight:
		if (*X + 1 >= row)
		{
			CanTurnOver = false;
			return;
		}
		break;
	case Direction::kDownRight:
		if (*X + 1 >= row || *Y + 1 >= col)
		{
			CanTurnOver = false;
			return;
		}
		break;
	case Direction::kDown:
		if (*Y + 1 >= col)
		{
			CanTurnOver = false;
			return;
		}
		break;
	case Direction::kDownLeft:
		if (*X - 1 < 0 || *Y + 1 >= col)
		{
			CanTurnOver = false;
			return;
		}
		break;
	case Direction::kLeft:
		if (*X - 1 < 0)
		{
			CanTurnOver = false;
			return;
		}
		break;
	case Direction::kUpLeft:
		if (*X - 1 < 0 || *Y - 1 < 0)
		{
			CanTurnOver = false;
			return;
		}
		break;
	}

	ChangCoordinate(*direction, X, Y, true);

	if (map[*Y][*X] == Color::kBlank)
	{
		CanTurnOver = false;
		return;
	}
	else if (map[*Y][*X] == phase)
	{
		return;
	}
	else if (map[*Y][*X] != phase)
	{
		CanTurnOver = true;
		TurnOver(direction, X, Y, map, phase);
	}

	ChangCoordinate(*direction, X, Y, false);
	
	if (CanTurnOver)
	{
		map[*Y][*X] = phase;
		return;
	}
	else
	{
		return;
	}
}

void Othello::ChangCoordinate(Direction direction, int* X, int* Y, bool WhichDirection)
{
	if (WhichDirection)
	{
		switch (direction)
		{
		case Direction::kUp:
			*Y -= 1;
			break;
		case Direction::kUpRight:
			*X += 1;
			*Y -= 1;
			break;
		case Direction::kRight:
			*X += 1;
			break;
		case Direction::kDownRight:
			*X += 1;
			*Y += 1;
			break;
		case Direction::kDown:
			*Y += 1;
			break;
		case Direction::kDownLeft:
			*X -= 1;
			*Y += 1;
			break;
		case Direction::kLeft:
			*X -= 1;
			break;
		case Direction::kUpLeft:
			*X -= 1;
			*Y -= 1;
			break;
		}
	}
	else
	{
		switch (direction)
		{
		case Direction::kUp:
			*Y += 1;
			break;
		case Direction::kUpRight:
			*X -= 1;
			*Y += 1;
			break;
		case Direction::kRight:
			*X -= 1;
			break;
		case Direction::kDownRight:
			*X -= 1;
			*Y -= 1;
			break;
		case Direction::kDown:
			*Y -= 1;
			break;
		case Direction::kDownLeft:
			*X += 1;
			*Y -= 1;
			break;
		case Direction::kLeft:
			*X += 1;
			break;
		case Direction::kUpLeft:
			*X += 1;
			*Y += 1;
			break;
		}
	}

	return;
}
