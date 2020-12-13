#include "../common.h"

SelectStageScene::SelectStageScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/�Q�[����ʔw�i_��.jpg");
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
	DrawBox(462.5, 120, 818.5, 640, GetColor(0, 0, 0), false);
	DrawBox(855, 120, 1210, 640, GetColor(0, 0, 0), false);

		//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "SelectStageScene", GetColor(0, 0, 0));
}

bool SelectStageScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}