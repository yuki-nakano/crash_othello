#ifndef PIECE_H
#define PIECE_H

#include "Status.h"

class Piece
{
public:
	void DecomposeVec();
	void CalculateV();

	

	void SetV(float v);
	void SetTheta(float theta);
	float GetTheta() const { return Theta; };
	float GetV() const { return V; };
	float GetV_X() const { return V_X; };
	float GetV_Y() const { return V_Y; };

private:
	void Decelerate();
	void Reflect();

public:
	int number = 0;
	bool init = false;
	bool isMoving = false;
	bool isHit = false;
	float pos_x = 0.0f;
	float pos_y = 0.0f;
	Color color = kBlank;

	float kRadius = 22.5f;
	float e = 0.9;

private:
	float V = 0.0f;
	float t;
	float Theta = 0.0f;
	float V_X = 0.0f;
	float V_Y = 0.0f;

	float g = 9.8;
	float M = 0.3;
	float kUp = 0;
	float kDown = 720;
	float kRight = 1280;
	float kLeft = 0;
};

#endif // !CALCULATION_H

