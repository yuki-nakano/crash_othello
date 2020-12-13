#include "../common.h"

SelectCharacterScene::SelectCharacterScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/�Q�[����ʔw�i_��.jpg");

	TextureData::CharacterSelect = LoadGraph("res/�L�����I��.png");

	TextureData::Character1 = LoadGraph("res/�L����1.png");
	TextureData::Character2 = LoadGraph("res/�L����2.png");
	TextureData::Character3 = LoadGraph("res/�L����3.png");
	TextureData::Character4 = LoadGraph("res/�L����4.png");

	TextureData::Player1 = LoadGraph("res/1P.png");
	TextureData::Player2 = LoadGraph("res/2P.png");
	TextureData::Player3 = LoadGraph("res/3P.png");
	TextureData::Player4 = LoadGraph("res/4P.png");

	TextureData::CharacterFlame = LoadGraph("res/�v���C���[�g.png");
	TextureData::Skill = LoadGraph("res/�X�L��.png");
	TextureData::Icon = LoadGraph("res/�A�C�R��.png");
	TextureData::Cursor = LoadGraph("res/�L�����I�J�[�\��.png");
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

		//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "SelectCharacterScene", GetColor(0, 0, 0));
}

bool SelectCharacterScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}