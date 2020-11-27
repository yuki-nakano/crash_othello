#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
	void Calculate();
	void SetV(float v);
	void SetTheta(float theta);

private:
	void Decelerate();
	void Reflect();
	void DecomposeVec();

public:
	bool Init = false;
	float pos_x;
	float pos_y;

private:
	bool IsAlive = true;
	float V;
	float t;
	float Theta;
	float V_X;
	float V_Y;
	const float g = 9.8;
	const float M = 0.3;
	const float e = 0.9;
	const float up = 0;
	const float down = 480;
	const float right = 640;
	const float left = 0;
};

#endif // !CALCULATION_H

