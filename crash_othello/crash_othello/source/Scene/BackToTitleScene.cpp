#include "../common.h"

BackToTitleScene::BackToTitleScene()
{

}
BackToTitleScene::~BackToTitleScene()
{

}
void BackToTitleScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Title);
	}
}

void BackToTitleScene::Draw()
{
	//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "BackToTitleScene", GetColor(0, 0, 0));
}

bool BackToTitleScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}