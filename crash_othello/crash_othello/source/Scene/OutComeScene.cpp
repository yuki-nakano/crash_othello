#include "../common.h"

OutComeScene::OutComeScene()
{

}
OutComeScene::~OutComeScene()
{

}
void OutComeScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_BacktoTitle);
	}
}

void OutComeScene::Draw()
{
	//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "OutComeScene", GetColor(0, 0, 0));
}

bool OutComeScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}