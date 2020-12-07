#ifndef FADE_H
#define FADE_H

#include "common.h"


//�t�F�[�h�^�C�v
enum FadeType
{
	//�t�F�[�h���s���Ă��Ȃ�
	kFadeNot,
	//�t�F�[�h�C��
	kFadeIn,
	//�t�F�[�h�A�E�g
	kFadeOut,
};

//�t�F�[�h�̏��
enum FadeStatus
{
	//�t�F�[�h���s���Ă��Ȃ�
	kDonotFade,
	//�t�F�[�h��
	kDoingFade,
	//�t�F�[�h�C���I��
	kFinishedFadeIn,
	//�t�F�[�h�A�E�g�I��
	kFinishedFadeOut,
};

//�t�F�[�h���x
enum FadeSpeed
{
	//4.2s
	kSlow = 1,
	//1.4s
	kNormal = 3,
	//0.8s
	kFast = 5,
};

class Fade
{
public:
	//�A���t�@�[�l�̏�����
	void InitFade(FadeType fade_type);

	/**
	 * @brief �t�F�[�h�^�C�v�ɉ����ăA���t�@�[�l�̑������s���֐�
	 * @param fade_type �t�F�[�h�^�C�v
	 * @param fade_speed �t�F�[�h�̑��x
	 * @retval true �t�F�[�h���������̓t�F�[�h���s���Ă��Ȃ�
	 * @retval false �t�F�[�h�I��
	 * @note RunFade�֐����Ŏ��s
	 */
	bool MakeToFluctuateAlpha(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief �t�F�[�h���s�֐�
	 * @param fade_type �t�F�[�h�^�C�v
	 * @param fade_speed �t�F�[�h�̑��x
	 * @return FadeStatus �t�F�[�h�̏��
	 */
	FadeStatus RunFade(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief �t�F�[�h�p��`�`��֐�
	 */
	void Draw();

private:
	bool initCheck_Fade = false;
	int alpha = 0;
};

/**
* @brief �V�[���̏��
*/
enum Phase
{
	//! �^�C�g���V�[��
	kTitle,
	//! �I�v�V�����V�[��
	kOption,
	//! �����V�[��
	kDescription,
	//!	�X�e�[�W�I���V�[��
	kSelectStage,
	//! �v���C�V�[��
	kPlay,
	//! �X�L���m�F�V�[��
	kCheckSkill,
	//! ���U���g�V�[��
	kResult,
	//! ���s
	kOutcome,
	//! �^�C�g���ɖ߂�
	kBacktoTitle,
};


#endif // !FADE_H
