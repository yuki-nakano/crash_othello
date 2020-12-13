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

	virtual bool IsEnd() const; //ÉVÅ[ÉìÇ™èIóπÇµÇΩÇ©Ç«Ç§Ç©Çï‘Ç∑
};

#endif // !SELECTSTAGESCENE_H