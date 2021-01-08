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
	for (int i = 0; i < 64; i++)
	{
		if (i == num)
		{
			continue;
		}
		
		if (piece[i].color == kBlank)
		{
			continue;
		}

		if (Collision::collid(piece[num], piece[i]) == true)
		{
			if (piece[num].GetV() > piece[i].GetV())
			{
				piece[i].isHit = true;

				float distanceX = piece[num].pos_x - piece[i].pos_x;
				float distanceY = (piece[num].pos_y - piece[i].pos_y) * -1;

				float distanceCircle = sqrtf(powf(distanceX, 2.0f) + powf(distanceY, 2.0f));

				piece[num].pos_x -= cosf(piece[num].GetTheta() * M_PI / 180) * (piece[num].kRadius + piece[i].kRadius - distanceCircle + 0.1f);
				piece[num].pos_y += sinf(piece[num].GetTheta() * M_PI / 180) * (piece[num].kRadius + piece[i].kRadius - distanceCircle + 0.1f);

				double atanTheta = atan2(distanceY, distanceX) * 180 / M_PI;

				if (atanTheta < 0)
				{
 					atanTheta += 360.0f;
				}

				double tmpTheta = (atanTheta + 180.0f > 360.0f ? atanTheta - 180.0f : atanTheta + 180.0f);
				
				piece[i].SetTheta(tmpTheta);

				piece[i].SetV(piece[i].GetV() + (piece[num].GetV() * (1 - piece[num].e)));

				piece[num].SetTheta(fmodf(360.0f - piece[num].GetTheta() + atanTheta * 2, 360.0f));

				//piece[num].SetTheta(tmpTheta * 2 - piece[num].GetTheta());

			}
		}
	}
}

void Collision::ChengeIsMoving(Piece piece[])
{
	for (int i = 0; i < 64; i++)
	{
		if (piece[i].isHit)
		{
			piece[i].isMoving = true;
			piece[i].isHit = false;
		}
	}
}
