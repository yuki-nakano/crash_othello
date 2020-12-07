#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "../common.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //ƒV[ƒ“‚ªI—¹‚µ‚½‚©‚Ç‚¤‚©‚ğ•Ô‚·
};

#endif // !TITLESCENE_H