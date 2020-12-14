#ifndef OPTIONSCENE_H
#define OPTIONSCENE_H

#include "../common.h"

class OptionScene : public SceneBase
{
public:
	OptionScene();
	~OptionScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !OPTIONSCENE_H