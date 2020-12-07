#include "../common.h"

TitleScene::TitleScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/�Q�[����ʔw�i_��.jpg");
}
TitleScene::~TitleScene()
{
	
}
void TitleScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Description);
	}
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(190, 0, 1090, 400, GetColor(0, 0, 0), false);
	DrawBox(250, 500, 580, 625, GetColor(0, 0, 0), false);
	DrawBox(700, 500, 1030, 625, GetColor(0, 0, 0), false);
		//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}