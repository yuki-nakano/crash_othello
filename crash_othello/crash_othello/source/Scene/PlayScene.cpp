#include "../common.h"

PlayScene::PlayScene()
{

}
PlayScene::~PlayScene()
{

}
void PlayScene::Exec()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager::SetNextScene(SceneID_Result);
	}
	else if(CheckHitKey(KEY_INPUT_1))
	{
		SceneManager::SetNextScene(SceneID_Option);
	}
}

void PlayScene::Draw()
{
	//LoadGraphScreen(0, 0, "res/仮盤面.jpg", false);
		//画面左上にデバッグ用の文字を黒で表示する
	//DrawString(20, 20, "PlayScene", GetColor(0, 0, 0));
}

bool PlayScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}