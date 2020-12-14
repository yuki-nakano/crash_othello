#ifndef SELECTSTAGESCENE_H
#define SELECTSTAGESCENE_H

#include "../common.h"

class SelectStageScene : public SceneBase
{
public:
	SelectStageScene();
	~SelectStageScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !SELECTSTAGESCENE_H