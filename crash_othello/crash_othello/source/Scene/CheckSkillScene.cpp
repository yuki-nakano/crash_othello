#include "../common.h"

CheckSkillScene::CheckSkillScene()
{

}
CheckSkillScene::~CheckSkillScene()
{

}
void CheckSkillScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Option);
	}
}

void CheckSkillScene::Draw()
{
	//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "CheckSkillScene", GetColor(0, 0, 0));
}

bool CheckSkillScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}