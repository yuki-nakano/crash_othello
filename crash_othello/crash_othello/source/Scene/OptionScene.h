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

	virtual bool IsEnd() const; //ƒV[ƒ“‚ªI—¹‚µ‚½‚©‚Ç‚¤‚©‚ğ•Ô‚·
};

#endif // !OPTIONSCENE_H