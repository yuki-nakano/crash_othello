#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
public:
	void ReflectPiece(Piece piece[], int num);
	void ChengeIsMoving(Piece piece[]);

private:
	bool collid(Piece move_piece, Piece piece);
};




#endif // !COLLISION_H
