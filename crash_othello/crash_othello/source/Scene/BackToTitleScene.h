#ifndef BACKTOTITLESCENE_H
#define BACKTOTITLESCENE_H

#include "../common.h"

class BackToTitleScene : public SceneBase
{
public:
	BackToTitleScene();
	virtual ~BackToTitleScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !BACKTOTITLESCENE_H