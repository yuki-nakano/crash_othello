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

	virtual bool IsEnd() const; //ÉVÅ[ÉìÇ™èIóπÇµÇΩÇ©Ç«Ç§Ç©Çï‘Ç∑
};

#endif // !BACKTOTITLESCENE_H