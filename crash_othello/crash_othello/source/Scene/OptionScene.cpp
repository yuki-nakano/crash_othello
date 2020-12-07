#include "../common.h"

OptionScene::OptionScene()
{

}
OptionScene::~OptionScene()
{

}
void OptionScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Play);
	}
}

void OptionScene::Draw()
{
	//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "OptionScene", GetColor(0, 0, 0));
}

bool OptionScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}