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

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す

};

#endif // !TITLESCENE_H