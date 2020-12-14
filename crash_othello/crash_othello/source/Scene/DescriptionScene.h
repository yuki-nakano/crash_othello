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

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !DESCRIPTIONSCENE_H