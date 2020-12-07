#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include "../common.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	~ResultScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //ƒV[ƒ“‚ªI—¹‚µ‚½‚©‚Ç‚¤‚©‚ğ•Ô‚·
};

#endif // !RESULTSCENE_H