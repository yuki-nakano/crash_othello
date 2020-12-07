#include "../common.h"

OptionScene::OptionScene()
{

}
OptionScene::~OptionScene()
{

}
void OptionScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Play);
	}
}

void OptionScene::Draw()
{
	//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "OptionScene", GetColor(0, 0, 0));
}

bool OptionScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}