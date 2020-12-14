#include "../common.h"

DescriptionScene::DescriptionScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/ゲーム画面背景_青.jpg");
}
DescriptionScene::~DescriptionScene()
{

}
void DescriptionScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_SelectNumberOfPeople);
	}
}

void DescriptionScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(20, 20, 205, 70, GetColor(0, 0, 0), false);
	DrawBox(1104, 20, 1260, 85, GetColor(0, 0, 0), false);

	DrawBox(445, 0, 835, 100, GetColor(0, 0, 0), false);

	DrawBox(125, 124, 969, 544, GetColor(0, 0, 0), false);

	DrawBox(21, 232, 151, 352, GetColor(0, 0, 0), false);
	DrawBox(940, 232, 1070, 352, GetColor(0, 0, 0), false);

	DrawBox(523, 546, 539, 562, GetColor(0, 0, 0), false);
	DrawBox(539, 546, 555, 562, GetColor(0, 0, 0), false);
	DrawBox(555, 546, 571, 562, GetColor(0, 0, 0), false);

	DrawBox(152, 564, 942, 684, GetColor(0, 0, 0), false);

	DrawBox(999, 272, 1280, 770, GetColor(0, 0, 0), false);

		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "DescriptionScene", GetColor(0, 0, 0));
}

bool DescriptionScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}