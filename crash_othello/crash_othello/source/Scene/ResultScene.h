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

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !RESULTSCENE_H