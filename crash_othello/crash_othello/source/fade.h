#ifndef FADE_H
#define FADE_H

#include "common.h"


//フェードタイプ
enum FadeType
{
	//フェードを行っていない
	kFadeNot,
	//フェードイン
	kFadeIn,
	//フェードアウト
	kFadeOut,
};

//フェードの状態
enum FadeStatus
{
	//フェードを行っていない
	kDonotFade,
	//フェード中
	kDoingFade,
	//フェードイン終了
	kFinishedFadeIn,
	//フェードアウト終了
	kFinishedFadeOut,
};

//フェード速度
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
	//アルファー値の初期化
	void InitFade(FadeType fade_type);

	/**
	 * @brief フェードタイプに応じてアルファー値の増減を行う関数
	 * @param fade_type フェードタイプ
	 * @param fade_speed フェードの速度
	 * @retval true フェード中もしくはフェードを行っていない
	 * @retval false フェード終了
	 * @note RunFade関数内で実行
	 */
	bool MakeToFluctuateAlpha(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief フェード実行関数
	 * @param fade_type フェードタイプ
	 * @param fade_speed フェードの速度
	 * @return FadeStatus フェードの状態
	 */
	FadeStatus RunFade(FadeType fade_type, FadeSpeed fade_speed);

	/**
	 * @brief フェード用矩形描画関数
	 */
	void Draw();

private:
	bool initCheck_Fade = false;
	int alpha = 0;
};

/**
* @brief シーンの状態
*/
enum Phase
{
	//! タイトルシーン
	kTitle,
	//! オプションシーン
	kOption,
	//! 説明シーン
	kDescription,
	//!	ステージ選択シーン
	kSelectStage,
	//! プレイシーン
	kPlay,
	//! スキル確認シーン
	kCheckSkill,
	//! リザルトシーン
	kResult,
	//! 勝敗
	kOutcome,
	//! タイトルに戻る
	kBacktoTitle,
};


#endif // !FADE_H
