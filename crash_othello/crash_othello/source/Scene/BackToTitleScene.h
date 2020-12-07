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

	virtual bool IsEnd() const; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !BACKTOTITLESCENE_H