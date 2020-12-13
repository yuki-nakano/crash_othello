#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Definition.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Exec();	//�V�[���̎��s
	void Draw();	//�V�[���̎��s

	//���̃V�[����ݒ肷��֐���static�֐��ɂ��邱�Ƃ�
	//���̂��ǂ��ɂ����Ă��悢��Ԃ����
	static void SetNextScene(SceneID next_);	//���̃V�[���ݒ�

private:
	class SceneBase* create_NextScene();		//���̃V�[�����쐬

private:
	class SceneBase* m_pScene;				//���s���̃V�[��
	static SceneID		m_NextSceneID;			//���ɍ��V�[����ID
};

#endif // !SCENEMANAGER_H
