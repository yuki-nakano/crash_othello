#ifndef SELECTNUMBEROFPEOPLE_H
#define SELECTNUMBEROFPEOPLE_H

#include "../common.h"

class SelectNumberOfPeopleScene : public SceneBase
{
public:
	SelectNumberOfPeopleScene();
	virtual ~SelectNumberOfPeopleScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !SELECTNUMBEROFPEOPLE_H
