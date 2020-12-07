#ifndef CHARACTERSELECTSCENE_H
#define CHARACTERSELECTSCENE_H

#include "../common.h"

class SelectCharacterScene : public SceneBase
{
public:
	SelectCharacterScene();
	~SelectCharacterScene();
public:
	void Exec();
	void Draw();

	virtual bool IsEnd() const; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !CHARACTERSELECTSCENE_H