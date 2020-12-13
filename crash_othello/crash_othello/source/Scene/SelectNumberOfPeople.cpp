#include "../common.h"

SelectNumberOfPeopleScene::SelectNumberOfPeopleScene()
{
	TextureData::BackGround_BLUE = LoadGraph("res/�Q�[����ʔw�i_��.jpg");
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

		//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "NumberOfPeople", GetColor(0, 0, 0));
}

bool SelectNumberOfPeopleScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}