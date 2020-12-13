#include "../common.h"

SelectNumberOfPeopleScene::SelectNumberOfPeopleScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/ゲーム画面背景_青.jpg");
}
SelectNumberOfPeopleScene::~SelectNumberOfPeopleScene()
{

}
void SelectNumberOfPeopleScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_SelectCharacter);
	}
}

void SelectNumberOfPeopleScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(20, 20, 205, 70, GetColor(0, 0, 0), false);
	DrawBox(1104, 20, 1260, 85, GetColor(0, 0, 0), false);

	DrawBox(375, 0, 905, 100, GetColor(0, 0, 0), false);

	DrawBox(275, 120, 630, 640, GetColor(0, 0, 0), false);
	DrawBox(650, 120, 1005, 640, GetColor(0, 0, 0), false);

		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "NumberOfPeople", GetColor(0, 0, 0));
}

bool SelectNumberOfPeopleScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}