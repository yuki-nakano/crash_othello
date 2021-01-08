#ifndef PIECE_H
#define PIECE_H

#include "Status.h"

class Piece
{
public:
	void DecomposeVec();
	void CalculateV();
	void SetWall(int stage_num);
	
	void SetV(float v);
	void SetTheta(float theta);
	double GetTheta() const { return Theta; };
	float GetV() const { return V; };
	double GetV_X() const { return V_X; };
	double GetV_Y() const { return V_Y; };
	float GetUp() const { return kUp; };
	float GetDown() const { return kDown; };
	float GetRight() const { return kRight; };
	float GetLeft() const { return kLeft; };

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
	float e = 0.9f;

private:
	float V = 0.0f;
	float Theta = 0.0f;
	double V_X = 0.0f;
	double V_Y = 0.0f;

	float g = 9.8f;
	float M = 1.0f;
	float kUp = 0.0f;
	float kDown = 500.0f;
	float kRight = 500.0f;
	float kLeft = 0.0f;
};

#endif // !CALCULATION_H

