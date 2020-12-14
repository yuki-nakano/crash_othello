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

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !PALYSCENE_H