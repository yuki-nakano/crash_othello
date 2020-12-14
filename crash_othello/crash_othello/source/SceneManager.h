#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Definition.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Exec();	//シーンの実行
	void Draw();	//シーンの実行

	//次のシーンを設定する関数をstatic関数にすることで
	//実体がどこにあってもよい状態を作る
	static void SetNextScene(SceneID next_);	//次のシーン設定

private:
	class SceneBase* create_NextScene();		//次のシーンを作成

private:
	class SceneBase* m_pScene;				//実行中のシーン
	static SceneID		m_NextSceneID;			//次に作るシーンのID
};

#endif // !SCENEMANAGER_H
