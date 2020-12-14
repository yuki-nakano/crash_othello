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

	virtual bool IsEnd() const; //シーンが終了したかどうかを返す
};

#endif // !CHARACTERSELECTSCENE_H