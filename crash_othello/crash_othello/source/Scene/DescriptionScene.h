#ifndef DESCRIPTIONSCENE_H
#define DESCRIPTIONSCENE_H

#include"SceneBase.h"

class DescriptionScene : public SceneBase
{
public:
	DescriptionScene();
	~DescriptionScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //ÉVÅ[ÉìÇ™èIóπÇµÇΩÇ©Ç«Ç§Ç©Çï‘Ç∑
};

#endif // !DESCRIPTIONSCENE_H