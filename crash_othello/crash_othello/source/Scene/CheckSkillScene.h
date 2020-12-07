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

	virtual bool IsEnd() const; //ƒV[ƒ“‚ªI—¹‚µ‚½‚©‚Ç‚¤‚©‚ğ•Ô‚·
};

#endif // !CHECKSKILLSCENE_H