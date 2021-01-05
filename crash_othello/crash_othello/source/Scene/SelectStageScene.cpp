#include "../common.h"

SelectStageScene::SelectStageScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/ゲーム画面背景_青.jpg");
}
SelectStageScene::~SelectStageScene()
{

}
void SelectStageScene::Exec()
{
	if(CheckHitKey(KEY_INPUT_SPACE))
	//m_Step++;
	//if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Play);
	}
}

void SelectStageScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(20, 20, 205, 70, GetColor(0, 0, 0), false);
	DrawBox(1104, 20, 1260, 85, GetColor(0, 0, 0), false);

	DrawBox(440, 0, 840, 100, GetColor(0, 0, 0), false);

	DrawBox(70, 120, 425, 640, GetColor(0, 0, 0), false);
	DrawBox(462, 120, 819, 640, GetColor(0, 0, 0), false);
	DrawBox(855, 120, 1210, 640, GetColor(0, 0, 0), false);

		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "SelectStageScene", GetColor(0, 0, 0));
}

bool SelectStageScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}