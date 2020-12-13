#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "../common.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !TITLESCENE_H