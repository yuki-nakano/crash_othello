#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "../common.h"

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !PALYSCENE_H