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
	double GetTheta() const { return Theta; };
	float GetV() const { return V; };
	double GetV_X() const { return V_X; };
	double GetV_Y() const { return V_Y; };

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
	float t;
	float Theta = 0.0f;
	double V_X = 0.0f;
	double V_Y = 0.0f;

	float g = 9.8f;
	float M = 0.3f;
	float kUp = 0.0f;
	float kDown = 720.0f;
	float kRight = 1280.0f;
	float kLeft = 0.0f;
};

#endif // !CALCULATION_H

