#include "../common.h"

PlayScene::PlayScene()
{

}
PlayScene::~PlayScene()
{

}
void PlayScene::Exec()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager::SetNextScene(SceneID_Result);
	}
	else if(CheckHitKey(KEY_INPUT_1))
	{
		SceneManager::SetNextScene(SceneID_Option);
	}
}

void PlayScene::Draw()
{
	//LoadGraphScreen(0, 0, "res/���Ֆ�.jpg", false);
		//��ʍ���Ƀf�o�b�O�p�̕��������ŕ\������
	//DrawString(20, 20, "PlayScene", GetColor(0, 0, 0));
}

bool PlayScene::IsEnd() const
{
	// @@Dummy �J�ڊm�F�p�̉�����
	return (m_Step >= 120);
}