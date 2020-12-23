#include "common.h"

bool Collision::collid(Piece move_piece, Piece piece)
{
	float DistanceX					= move_piece.pos_x - piece.pos_x;
	float DistanceY					= move_piece.pos_y - piece.pos_y;
	float CircleDistance			= powf(DistanceX, 2.0f) + powf(DistanceY, 2.0f);
	float CollidedDistanceCircle	= powf((move_piece.kRadius + piece.kRadius), 2.0f);

	if (CircleDistance < CollidedDistanceCircle)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Collision::ReflectPiece(Piece piece[], int num)
{
	for (int i = 0; i < 5; i++)
	{
		if (i == num)
		{
			continue;
		}
		
		if (piece[i].color == kBlank)
		{
			continue;
		}

		if (collid(piece[num], piece[i]) == true)
		{
			if (piece[num].GetV() > piece[i].GetV())
			{
				piece[i].isHit = true;

				float distanceX = piece[num].pos_x - piece[i].pos_x;
				float distanceY = piece[num].pos_y - piece[i].pos_y;

				double tmpTheta = atan2f(distanceY, distanceX) * 180 / M_PI;

				if (tmpTheta < 0)
				{
					tmpTheta += 360.0f;
				}

				float distanceCircle = sqrtf(powf(distanceX, 2.0f) + powf(distanceY, 2.0f));

				piece[i].SetTheta(fmodf((tmpTheta + 180.0f), 360.0f));

				piece[i].SetV(piece[i].GetV() + (piece[num].GetV() * (1 - piece[num].e)));

				piece[num].SetTheta(fmodf((tmpTheta * 2 - piece[num].GetTheta() + 360.0f), 360.0f));

				piece[num].pos_x += cosf(piece[num].GetTheta() * M_PI / 180) * (piece[num].kRadius + piece[i].kRadius - distanceCircle + 0.01f);
				piece[num].pos_y -= sinf(piece[num].GetTheta() * M_PI / 180) * (piece[num].kRadius + piece[i].kRadius - distanceCircle + 0.01f);
			}
		}
	}
}

void Collision::ChengeIsMoving(Piece piece[])
{
	for (int i = 0; i < 5; i++)
	{
		if (piece[i].isHit)
		{
			piece[i].isMoving = true;
			piece[i].isHit = false;
		}
	}
}
