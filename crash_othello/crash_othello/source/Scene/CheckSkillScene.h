#ifndef CHECKSKILLSCENE_H
#define CHECKSKILLSCENE_H

#include "../common.h"

class CheckSkillScene : public SceneBase
{
public:
	CheckSkillScene();
	~CheckSkillScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !CHECKSKILLSCENE_H