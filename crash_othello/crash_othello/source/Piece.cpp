#include "common.h"

void Piece::Calculate()
{
	if (!IsAlive)
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
	if (pos_x - 22.5f < left)
	{
		pos_x = left + 22.6f;

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
	else if (pos_x + 22.5f > right)
	{
		pos_x = right - 22.6f;

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
	else if (pos_y - 22.5f < up)
	{
		pos_y = up + 22.6f;

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
	else if (pos_y + 22.5f > down)
	{
		pos_y = down - 22.6f;

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
		IsAlive = false;
		return;
	}
	V_X = cosf(Theta * M_PI / 180) * V;
	V_Y = sinf(Theta * M_PI / 180) * V;
}

void Piece::SetV(float v)
{
	V = v;
}

void Piece::SetTheta(float theta)
{
	Theta = theta;
}
