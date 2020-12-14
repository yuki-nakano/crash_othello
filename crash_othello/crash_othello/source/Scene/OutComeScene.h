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

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !OUTCOMESCENE_H