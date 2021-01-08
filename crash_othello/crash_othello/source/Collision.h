#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
public:
	static void ReflectPiece(Piece piece[], int num);
	static void ChengeIsMoving(Piece piece[]);

private:
	static bool collid(Piece move_piece, Piece piece);
};




#endif // !COLLISION_H
