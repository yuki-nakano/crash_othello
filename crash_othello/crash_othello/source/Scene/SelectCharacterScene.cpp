#include "../common.h"

SelectCharacterScene::SelectCharacterScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/ゲーム画面背景_青.jpg");

	TextureData::CharacterSelect = LoadGraph("res/キャラ選択.png");

	TextureData::Character1 = LoadGraph("res/キャラ1.png");
	TextureData::Character2 = LoadGraph("res/キャラ2.png");
	TextureData::Character3 = LoadGraph("res/キャラ3.png");
	TextureData::Character4 = LoadGraph("res/キャラ4.png");

	TextureData::Player1 = LoadGraph("res/1P.png");
	TextureData::Player2 = LoadGraph("res/2P.png");
	TextureData::Player3 = LoadGraph("res/3P.png");
	TextureData::Player4 = LoadGraph("res/4P.png");

	TextureData::CharacterFlame = LoadGraph("res/プレイヤー枠.png");
	TextureData::Skill = LoadGraph("res/スキル.png");
	TextureData::Icon = LoadGraph("res/アイコン.png");
	TextureData::Cursor = LoadGraph("res/キャラ選カーソル.png");
}
SelectCharacterScene::~SelectCharacterScene()
{

}
void SelectCharacterScene::Exec()
{
	//if (CheckHitKey(KEY_INPUT_SPACE))
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_SelectStage);
	}
}

void SelectCharacterScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(20, 20, 205, 70, GetColor(0, 0, 0), false);
	DrawBox(1104, 20, 1260, 85, GetColor(0, 0, 0), false);

	DrawGraph(340, 0, TextureData::CharacterSelect, true);
	DrawGraph(475, 160, TextureData::Icon, true);

	DrawGraph(20, 100, TextureData::CharacterFlame, true);
	DrawGraph(860, 100, TextureData::CharacterFlame, true);
	DrawGraph(20, 384, TextureData::CharacterFlame, true);
	DrawGraph(860, 384, TextureData::CharacterFlame, true);
	
	DrawGraph(20, 110, TextureData::Skill, true);
	DrawGraph(860, 110, TextureData::Skill, true);
	DrawGraph(20, 394, TextureData::Skill, true);
	DrawGraph(860, 394, TextureData::Skill, true);

	DrawGraph(236, 110, TextureData::Character1, true);
	DrawGraph(1076, 110, TextureData::Character2, true);
	DrawGraph(236, 394, TextureData::Character3, true);
	DrawGraph(1076, 394, TextureData::Character4, true);

	DrawGraph(476, 161, TextureData::Cursor, true);
	DrawGraph(639, 161, TextureData::Cursor, true);
	DrawGraph(476, 485, TextureData::Cursor, true);
	DrawGraph(639, 324, TextureData::Cursor, true);
	
	DrawGraph(320, 284, TextureData::Player1, true);
	DrawGraph(1160, 284, TextureData::Player2, true);
	DrawGraph(320, 568, TextureData::Player3, true);
	DrawGraph(1160, 568, TextureData::Player4, true);

		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "SelectCharacterScene", GetColor(0, 0, 0));
}

bool SelectCharacterScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}