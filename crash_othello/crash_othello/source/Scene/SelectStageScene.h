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

	virtual bool IsEnd() const; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !SELECTSTAGESCENE_H