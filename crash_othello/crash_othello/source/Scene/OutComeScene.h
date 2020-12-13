#ifndef OUTCOMESCENE_H
#define OUTCOMESCENE_H

#include "../common.h"

class OutComeScene : public SceneBase
{
public:
	OutComeScene();
	~OutComeScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //ƒV[ƒ“‚ªI—¹‚µ‚½‚©‚Ç‚¤‚©‚ğ•Ô‚·
};

#endif // !OUTCOMESCENE_H