#include "../common.h"

OutComeScene::OutComeScene()
{

}
OutComeScene::~OutComeScene()
{

}
void OutComeScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_BacktoTitle);
	}
}

void OutComeScene::Draw()
{
	//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "OutComeScene", GetColor(0, 0, 0));
}

bool OutComeScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}