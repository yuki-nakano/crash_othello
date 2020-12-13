#include "../common.h"

ResultScene::ResultScene()
{

}
ResultScene::~ResultScene()
{

}
void ResultScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Outcome);
	}
}

void ResultScene::Draw()
{
	//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "ResultScene", GetColor(0, 0, 0));
}

bool ResultScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}