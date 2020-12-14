#ifndef DEFINITION_H
#define DEFINITION_H

class Definition
{
public:
	const int Widht = 1280;
	const int Height = 720;

	const int MaxPiece = 64;
};

enum SceneID
{
	//! タイトルシーン
	SceneID_Title,
	//! オプションシーン
	SceneID_Option,
	//! 説明シーン
	SceneID_Description,
	//! 人数選択シーン
	SceneID_SelectNumberOfPeople,
	//! キャラクター選択シーン
	SceneID_SelectCharacter,
	//!	ステージ選択シーン
	SceneID_SelectStage,
	//! プレイシーン
	SceneID_Play,
	//! スキル確認シーン
	SceneID_CheckSkill,
	//! リザルトシーン
	SceneID_Result,
	//! 勝敗
	SceneID_Outcome,
	//! タイトルに戻る
	SceneID_BacktoTitle,
	

	SceneID_Max,
	SceneID_Invalid,	//無効値
};

#endif // !DEFINITION_H
