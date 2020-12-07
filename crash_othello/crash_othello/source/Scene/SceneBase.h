#ifndef SCENEBASE_H
#define SCENEBASE_H

//�V�[�����N���X
class SceneBase
{
public:
	int m_Step = 0;
	SceneBase();
	virtual ~SceneBase();

	//�������e�͔h���N���X���ɈႤ�̂ŁA
	//�������z�֐��Ƃ��Đ錾���Ă���
	virtual void Exec() = 0;	//�������s��
	virtual void Draw() = 0;	//�`����s��

	virtual bool IsEnd() const = 0; //�V�[�����I���������ǂ�����Ԃ�
};

#endif // !SCENEBASE_H
