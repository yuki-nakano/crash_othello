#include "common.h"

void Piece::CalculateV()
{
	if (!isMoving)
	{
		return;
	}

	Decelerate();
	
	DecomposeVec();

	pos_x += V_X;
	
	pos_y += V_Y;
	
	Reflect();
}

void Piece::Decelerate()
{
	V -= g * M / 60;
	if (V < 0)
	{
		V = 0;
	}
}

void Piece::Reflect()
{
	if (pos_x - kRadius < kLeft)
	{
		pos_x = kLeft + (kRadius + 0.1f);

		if (Theta == 180)
		{
			Theta = 0;
		}
		else if (Theta < 180)
		{
			Theta = 180 - Theta;
		}
		else if (Theta > 180)
		{
			Theta = 540 - Theta;
		}

		V *= 0.9f;
	}
	else if (pos_x + kRadius > kRight)
	{
		pos_x = kRight - (kRadius + 0.1f);

		if (Theta == 0 || Theta == 360)
		{
			Theta = 180;
		}
		else if (Theta < 180)
		{
			Theta = 180 - Theta;
		}
		else if (Theta > 180)
		{
			Theta = 540 - Theta;
		}

		V *= 0.9f;
	}
	else if (pos_y - kRadius < kUp)
	{
		pos_y = kUp + (kRadius + 0.1f);

		if (Theta == 90)
		{
			Theta = 270;
		}
		else if (Theta < 90)
		{
			Theta = 360 - Theta;
		}
		else if (Theta > 90)
		{
			Theta = 360 - Theta;
		}

		V *= 0.9f;
	}
	else if (pos_y + kRadius > kDown)
	{
		pos_y = kDown - (kRadius + 0.1f);

		if (Theta == 270)
		{
			Theta = 90;
		}
		else if (Theta < 270)
		{
			Theta = 360 - Theta;
		}
		else if (Theta > 270)
		{
			Theta = 360 - Theta;
		}

		V *= 0.9f;
	}

}

void Piece::DecomposeVec()
{
	if (V <= 0)
	{
		V_X = 0;
		V_Y = 0;
		isMoving = false;
		return;
	}
	V_X = cos(Theta * M_PI / 180) * V;
	V_Y = sin(Theta * M_PI / 180) * V * -1;
}

void Piece::SetWall(int stage_num)
{
	switch (stage_num)
	{
	case 1:
		kUp = 90.0f;
		kDown = 630.0f;
		kRight = 1070.0f;
		kLeft = 210.0f;
		break;
	case 2:
		kUp = 0.0f;
		kDown = 0.0f;
		kRight = 0.0f;
		kLeft = 0.0f;
		break;
	case 3:
		kUp = 0.0f;
		kDown = 0.0f;
		kRight = 0.0f;
		kLeft = 0.0f;
		break;
	default:
		break;
	}
}

void Piece::SetV(float v)
{
	V = v;
}

void Piece::SetTheta(float theta)
{
	Theta = theta;
}

