#include "../common.h"

BackToTitleScene::BackToTitleScene()
{

}
BackToTitleScene::~BackToTitleScene()
{

}
void BackToTitleScene::Exec()
{
	m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Title);
	}
}

void BackToTitleScene::Draw()
{
	//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	DrawString(20, 20, "BackToTitleScene", GetColor(0, 0, 0));
}

bool BackToTitleScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}