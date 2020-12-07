#ifndef OUTCOMESCENE_H
#define OUTCOMESCENE_H

#include "../common.h"

class OutComeScene : public SceneBase
{
public:
	OutComeScene();
	~OutComeScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !OUTCOMESCENE_H