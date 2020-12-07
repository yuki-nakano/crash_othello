#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "../common.h"

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //ƒV[ƒ“‚ªI—¹‚µ‚½‚©‚Ç‚¤‚©‚ğ•Ô‚·
};

#endif // !PALYSCENE_H