#include "../common.h"

CheckSkillScene::CheckSkillScene()
{

}
CheckSkillScene::~CheckSkillScene()
{

}
void CheckSkillScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Option);
	}
}

void CheckSkillScene::Draw()
{
	//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "CheckSkillScene", GetColor(0, 0, 0));
}

bool CheckSkillScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}