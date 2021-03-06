﻿#include "../common.h"

int stage = 1;
int Character[4];

int OwnPieceRed = 15;
int OwnPieceBlue = 15;
int OwnPieceBlack = 15;
int OwnPieceWhite = 15;

//Definition definition_G;
Othello othello;
int map[col][row];
int previousMap[col][row];
Color turn;
Piece piece[64];
Collision collision;

enum
{
	kGameStart,
	kGameFinish,

	kInitializePhase,
	kCutInPhase,
	kDecideThetaPhase,
	kDecidePowerPhase,
	kReflectPhase,
	kTurnOverPhase,
	kTurnOverAnimationPhase,
	kFinishPhase,
	kResultPhase,

	kSkillCutInPhase,

	kSkillHanabi,
	kSkillKaminoitte,
	kSkillHebii,
	kSkillMagunetto,
};

enum
{
	kActiveSkill,
	kInactiveSkill,
	kUsedSkill,
};

enum
{
	kGauge,			//ゲージ	
	kGaugeWhite,	//ゲージ空白
	kArrow,			//矢印

	kBoard_Othello,	//オセロボード
	kBoard_Stage1,	//ステージ1ボード
	kBoard_Stage2,	//ステージ2ボード
	kBoard_Stage3,	//ステージ3ボード

	kIcon_1P,		//アイコン１P
	kIcon_2P,		//アイコン２P
	kIcon_3P,		//アイコン３P
	kIcon_4P,		//アイコン４P

	kOwnPiece_1P,	//残り枚数１P
	kOwnPiece_2P,	//残り枚数２P
	kOwnPiece_3P,	//残り枚数３P
	kOwnPiece_4P,	//残り枚数４P

	kRedPiece,		//赤駒
	kBluePiece,		//青駒
	kBlackPiece,	//黒駒
	kWhitePiece,	//白駒

	kCutInStart,	//ゲーム開始
	kCutInFinish,	//ゲーム終了

	kBackGroundYellow,
	kBackGroundPurple,
	kBackGroundBlue,

	kBackGroundResult,
	kResultTitle,

	kReturnTitle,

	kTextureMax
};
//カットイン
enum
{
	kCutIn_Red,
	kCutIn_Blue,
	kCutIn_Black,
	kCutIn_White,
};
//赤数字
enum
{
	kNumber_0,	
	kNumber_1,
	kNumber_2,
	kNumber_3,
	kNumber_4,
	kNumber_5,
	kNumber_6,
	kNumber_7,
	kNumber_8,
	kNumber_9,
};
//スキル
enum
{
	kHANABI,
	kTIKARAKOSO,
	kINBIJIBURU,
	kKAMINOITTE,
	kHEBII,
	kMAGUNETTO,
};
//反射エフェクト
enum
{
	kReflectEffect1,
	kReflectEffect2,
	kReflectEffect3,

};
//マスのエフェクト
enum
{
	kPixelRed,
	kPixelBlue,
	kPixelBlack,
	kPixelWhite,
};

int Texture[kTextureMax];
int TextureCutIn[4];
int TextureNumberRed[10];
int TextureNumberBlue[10];
int TextureNumberBlack[10];
int TextureNumberWhite[10];
int TextureSkillIcon[6];
int TextureSkillCutIn[6];
int TextureReflectEffect[3];
int TexturePixel[4];
int TextureIcon[6];
int TextureResultNumberRed[10];
int TextureResultNumberBlue[10];
int TextureResultNumberBlack[10];
int TextureResultNumberWhite[10];
int TexturePlayerNumber[4];
int TextureSheets[4];
int TextureWin[4];

PlayScene::PlayScene()
{
	for (int i = 0; i < 3; i++)
	{
		TextureBackGround_posX[i] = 0;
		TextureBackGround_posY[i] = (i - 1) * 720;

		TextureBackGround_posX_2[i] = 1280;
		TextureBackGround_posY_2[i] = (i - 2) * 720;


	}
	

	Character[0] = kKAMINOITTE;
	Character[1] = kTIKARAKOSO;
	Character[2] = kINBIJIBURU;
	Character[3] = kHANABI;

	for (int i = 0; i < MaxPiece; i++)
	{
		piece[i].color = kBlank;
		piece[i].SetWall(stage);
	}

	for (int i = 0; i < 4; i++)
	{
		skillState[i] = kInactiveSkill;
	}

	Hanabi = false;
	Inbijiburu = false;
	Magunetto = false;

	countFrame = 0;
	phase = kGameStart;
	turnNumber = 0;
	theta = 0;
	turn = kRed;
	cutIn_y = 0;
	countCutIn = 0;

	piece[MaxPiece - 1].color = kRed;
	piece[MaxPiece - 1].pos_x = 640 - 24.625f;
	piece[MaxPiece - 1].pos_y = 360 - 24.625f;

	piece[MaxPiece - 2].color = kBlue;
	piece[MaxPiece - 2].pos_x = 640 + 24.625f;
	piece[MaxPiece - 2].pos_y = 360 - 24.625f;

	piece[MaxPiece - 3].color = kBlack;
	piece[MaxPiece - 3].pos_x = 640 - 24.625f;
	piece[MaxPiece - 3].pos_y = 360 + 24.625f;

	piece[MaxPiece - 4].color = kWhite;
	piece[MaxPiece - 4].pos_x = 640 + 24.625f;
	piece[MaxPiece - 4].pos_y = 360 + 24.625f;

	FinishedEffect = false;

	Texture[kGauge]		 = LoadGraph("res/GameScene/ge-ji.png");
	Texture[kGaugeWhite] = LoadGraph("res/GameScene/ge-ji_ironasi.png");
	Texture[kArrow]		 = LoadGraph("res/GameScene/yajirusi.png");
	
	Texture[kBoard_Othello] = LoadGraph("res/GameScene/仮盤面.jpg");
	Texture[kBoard_Stage1]  = LoadGraph("res/GameScene/normal.png");
	Texture[kBoard_Stage2]  = LoadGraph("res/GameScene/");
	Texture[kBoard_Stage3]  = LoadGraph("res/GameScene/");
	
	Texture[kIcon_1P] = LoadGraph("res/GameScene/アイコン枠_1P.png");
	Texture[kIcon_2P] = LoadGraph("res/GameScene/アイコン枠_2P.png");
	Texture[kIcon_3P] = LoadGraph("res/GameScene/アイコン枠_3P.png");
	Texture[kIcon_4P] = LoadGraph("res/GameScene/アイコン枠_4P.png");
	
	Texture[kOwnPiece_1P] = LoadGraph("res/GameScene/残り枚_1P.png");
	Texture[kOwnPiece_2P] = LoadGraph("res/GameScene/残り枚_2P.png");
	Texture[kOwnPiece_3P] = LoadGraph("res/GameScene/残り枚_3P.png");
	Texture[kOwnPiece_4P] = LoadGraph("res/GameScene/残り枚_4P.png");

	Texture[kRedPiece]   = LoadGraph("res/GameScene/コマ_赤.png");
	Texture[kBluePiece]  = LoadGraph("res/GameScene/コマ_青.png");
	Texture[kBlackPiece] = LoadGraph("res/GameScene/コマ_黒.png");
	Texture[kWhitePiece] = LoadGraph("res/GameScene/コマ_白.png");
	
	Texture[kCutInStart]  = LoadGraph("res/GameScene/ゲームスタート.png");
	Texture[kCutInFinish] = LoadGraph("res/GameScene/ゲーム終了.png");

	Texture[kBackGroundYellow] = LoadGraph("res/GameScene/ゲーム画面背景_黄.jpg");
	Texture[kBackGroundPurple] = LoadGraph("res/GameScene/ゲーム画面背景_紫.jpg");
	Texture[kBackGroundBlue]   = LoadGraph("res/GameScene/ゲーム画面背景_青.jpg");

	Texture[kBackGroundResult] = LoadGraph("res/GameScene/リザルト/オプション_集計_勝利画面背景.png");

	Texture[kResultTitle] = LoadGraph("res/GameScene/リザルト/結果発表.png");

	Texture[kReturnTitle] = LoadGraph("res/GameScene/リザルト/勝利画面_タイトルに戻る.png");

	TextureCutIn[kCutIn_Red]   = LoadGraph("res/GameScene/ターンのカットイン1P.png");
	TextureCutIn[kCutIn_Blue]  = LoadGraph("res/GameScene/ターンのカットイン2P.png");
	TextureCutIn[kCutIn_Black] = LoadGraph("res/GameScene/ターンのカットイン3P.png");
	TextureCutIn[kCutIn_White] = LoadGraph("res/GameScene/ターンのカットイン4P.png");

	TextureNumberRed[kNumber_0] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤0.png");
	TextureNumberRed[kNumber_1] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤1.png");
	TextureNumberRed[kNumber_2] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤2.png");
	TextureNumberRed[kNumber_3] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤3.png");
	TextureNumberRed[kNumber_4] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤4.png");
	TextureNumberRed[kNumber_5] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤5.png");
	TextureNumberRed[kNumber_6] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤6.png");
	TextureNumberRed[kNumber_7] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤7.png");
	TextureNumberRed[kNumber_8] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤8.png");
	TextureNumberRed[kNumber_9] = LoadGraph("res/GameScene/残り〇枚_4色0~9/赤9.png");

	TextureNumberBlue[kNumber_0] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青0.png");
	TextureNumberBlue[kNumber_1] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青1.png");
	TextureNumberBlue[kNumber_2] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青2.png");
	TextureNumberBlue[kNumber_3] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青3.png");
	TextureNumberBlue[kNumber_4] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青4.png");
	TextureNumberBlue[kNumber_5] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青5.png");
	TextureNumberBlue[kNumber_6] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青6.png");
	TextureNumberBlue[kNumber_7] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青7.png");
	TextureNumberBlue[kNumber_8] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青8.png");
	TextureNumberBlue[kNumber_9] = LoadGraph("res/GameScene/残り〇枚_4色0~9/青9.png");

	TextureNumberBlack[kNumber_0] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒0.png");
	TextureNumberBlack[kNumber_1] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒1.png");
	TextureNumberBlack[kNumber_2] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒2.png");
	TextureNumberBlack[kNumber_3] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒3.png");
	TextureNumberBlack[kNumber_4] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒4.png");
	TextureNumberBlack[kNumber_5] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒5.png");
	TextureNumberBlack[kNumber_6] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒6.png");
	TextureNumberBlack[kNumber_7] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒7.png");
	TextureNumberBlack[kNumber_8] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒8.png");
	TextureNumberBlack[kNumber_9] = LoadGraph("res/GameScene/残り〇枚_4色0~9/黒9.png");

	TextureNumberWhite[kNumber_0] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白0.png");
	TextureNumberWhite[kNumber_1] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白1.png");
	TextureNumberWhite[kNumber_2] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白2.png");
	TextureNumberWhite[kNumber_3] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白3.png");
	TextureNumberWhite[kNumber_4] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白4.png");
	TextureNumberWhite[kNumber_5] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白5.png");
	TextureNumberWhite[kNumber_6] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白6.png");
	TextureNumberWhite[kNumber_7] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白7.png");
	TextureNumberWhite[kNumber_8] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白8.png");
	TextureNumberWhite[kNumber_9] = LoadGraph("res/GameScene/残り〇枚_4色0~9/白9.png");

	TextureSkillIcon[kHANABI]	  = LoadGraph("res/GameScene/スキルアイコン_花火.png");
	TextureSkillIcon[kTIKARAKOSO] = LoadGraph("res/GameScene/スキルアイコン_力こそパワー.png");
	TextureSkillIcon[kINBIJIBURU] = LoadGraph("res/GameScene/スキルアイコン_インビジブルショット.png");
	TextureSkillIcon[kKAMINOITTE] = LoadGraph("res/GameScene/スキルアイコン_神の一手.png");
	TextureSkillIcon[kHEBII]	  = LoadGraph("res/GameScene/スキルアイコン_ヘビーショット.png");
	TextureSkillIcon[kMAGUNETTO]  = LoadGraph("res/GameScene/スキルアイコン_マグネット.png");

	TextureSkillCutIn[kHANABI]     = LoadGraph("res/GameScene/スキルカットイン/カットイン_花火.png");
	TextureSkillCutIn[kTIKARAKOSO] = LoadGraph("res/GameScene/スキルカットイン/カットイン_力こそパワー.png");
	TextureSkillCutIn[kINBIJIBURU] = LoadGraph("res/GameScene/スキルカットイン/カットイン_インビジブルショット.png");
	TextureSkillCutIn[kKAMINOITTE] = LoadGraph("res/GameScene/スキルカットイン/カットイン_神の一手.png");
	TextureSkillCutIn[kHEBII]      = LoadGraph("res/GameScene/スキルカットイン/カットイン_ヘビーショット.png");
	TextureSkillCutIn[kMAGUNETTO]  = LoadGraph("res/GameScene/スキルカットイン/カットイン_マグネット.png");

	TextureReflectEffect[kReflectEffect1] = LoadGraph("res/GameScene/hansya_1.png");
	TextureReflectEffect[kReflectEffect2] = LoadGraph("res/GameScene/hansya_2.png");
	TextureReflectEffect[kReflectEffect3] = LoadGraph("res/GameScene/hansya_3.png");

	TexturePixel[kPixelRed] = LoadGraph("res/GameScene/マス_色_赤.png");
	TexturePixel[kPixelBlue] = LoadGraph("res/GameScene/マス_色_青.png");
	TexturePixel[kPixelBlack] = LoadGraph("res/GameScene/マス_色_黒.png");
	TexturePixel[kPixelWhite] = LoadGraph("res/GameScene/マス_色_白.png");

	TextureIcon[kHANABI]	 = LoadGraph("res/GameScene/アイコン_花火.png");
	TextureIcon[kTIKARAKOSO] = LoadGraph("res/GameScene/アイコン_力こそパワー.png");
	TextureIcon[kINBIJIBURU] = LoadGraph("res/GameScene/アイコン_インビジブルショット.png");
	TextureIcon[kKAMINOITTE] = LoadGraph("res/GameScene/アイコン_神の一手.png");
	TextureIcon[kHEBII]		 = LoadGraph("res/GameScene/アイコン_ヘビーショット.png");
	TextureIcon[kMAGUNETTO]  = LoadGraph("res/GameScene/アイコン_マグネット.png");

	TextureResultNumberRed[kNumber_0] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤0.png");
	TextureResultNumberRed[kNumber_1] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤1.png");
	TextureResultNumberRed[kNumber_2] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤2.png");
	TextureResultNumberRed[kNumber_3] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤3.png");
	TextureResultNumberRed[kNumber_4] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤4.png");
	TextureResultNumberRed[kNumber_5] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤5.png");
	TextureResultNumberRed[kNumber_6] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤6.png");
	TextureResultNumberRed[kNumber_7] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤7.png");
	TextureResultNumberRed[kNumber_8] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤8.png");
	TextureResultNumberRed[kNumber_9] = LoadGraph("res/GameScene/リザルト/集計画面数字/赤9.png");

	TextureResultNumberBlue[kNumber_0] = LoadGraph("res/GameScene/リザルト/集計画面数字/青0.png");
	TextureResultNumberBlue[kNumber_1] = LoadGraph("res/GameScene/リザルト/集計画面数字/青1.png");
	TextureResultNumberBlue[kNumber_2] = LoadGraph("res/GameScene/リザルト/集計画面数字/青2.png");
	TextureResultNumberBlue[kNumber_3] = LoadGraph("res/GameScene/リザルト/集計画面数字/青3.png");
	TextureResultNumberBlue[kNumber_4] = LoadGraph("res/GameScene/リザルト/集計画面数字/青4.png");
	TextureResultNumberBlue[kNumber_5] = LoadGraph("res/GameScene/リザルト/集計画面数字/青5.png");
	TextureResultNumberBlue[kNumber_6] = LoadGraph("res/GameScene/リザルト/集計画面数字/青6.png");
	TextureResultNumberBlue[kNumber_7] = LoadGraph("res/GameScene/リザルト/集計画面数字/青7.png");
	TextureResultNumberBlue[kNumber_8] = LoadGraph("res/GameScene/リザルト/集計画面数字/青8.png");
	TextureResultNumberBlue[kNumber_9] = LoadGraph("res/GameScene/リザルト/集計画面数字/青9.png");

	TextureResultNumberBlack[kNumber_0] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒0.png");
	TextureResultNumberBlack[kNumber_1] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒1.png");
	TextureResultNumberBlack[kNumber_2] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒2.png");
	TextureResultNumberBlack[kNumber_3] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒3.png");
	TextureResultNumberBlack[kNumber_4] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒4.png");
	TextureResultNumberBlack[kNumber_5] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒5.png");
	TextureResultNumberBlack[kNumber_6] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒6.png");
	TextureResultNumberBlack[kNumber_7] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒7.png");
	TextureResultNumberBlack[kNumber_8] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒8.png");
	TextureResultNumberBlack[kNumber_9] = LoadGraph("res/GameScene/リザルト/集計画面数字/黒9.png");

	TextureResultNumberWhite[kNumber_0] = LoadGraph("res/GameScene/リザルト/集計画面数字/白0.png");
	TextureResultNumberWhite[kNumber_1] = LoadGraph("res/GameScene/リザルト/集計画面数字/白1.png");
	TextureResultNumberWhite[kNumber_2] = LoadGraph("res/GameScene/リザルト/集計画面数字/白2.png");
	TextureResultNumberWhite[kNumber_3] = LoadGraph("res/GameScene/リザルト/集計画面数字/白3.png");
	TextureResultNumberWhite[kNumber_4] = LoadGraph("res/GameScene/リザルト/集計画面数字/白4.png");
	TextureResultNumberWhite[kNumber_5] = LoadGraph("res/GameScene/リザルト/集計画面数字/白5.png");
	TextureResultNumberWhite[kNumber_6] = LoadGraph("res/GameScene/リザルト/集計画面数字/白6.png");
	TextureResultNumberWhite[kNumber_7] = LoadGraph("res/GameScene/リザルト/集計画面数字/白7.png");
	TextureResultNumberWhite[kNumber_8] = LoadGraph("res/GameScene/リザルト/集計画面数字/白8.png");
	TextureResultNumberWhite[kNumber_9] = LoadGraph("res/GameScene/リザルト/集計画面数字/白9.png");

	TexturePlayerNumber[0] = LoadGraph("res/GameScene/リザルト/集計画面_1p.png");
	TexturePlayerNumber[1] = LoadGraph("res/GameScene/リザルト/集計画面_2p.png");
	TexturePlayerNumber[2] = LoadGraph("res/GameScene/リザルト/集計画面_3p.png");
	TexturePlayerNumber[3] = LoadGraph("res/GameScene/リザルト/集計画面_4p.png");

	TextureSheets[0] = LoadGraph("res/GameScene/リザルト/集計画面_枚_1p.png");
	TextureSheets[1] = LoadGraph("res/GameScene/リザルト/集計画面_枚_2p.png");
	TextureSheets[2] = LoadGraph("res/GameScene/リザルト/集計画面_枚_3p.png");
	TextureSheets[3] = LoadGraph("res/GameScene/リザルト/集計画面_枚_4p.png");

	TextureWin[0] = LoadGraph("res/GameScene/リザルト/1Pの勝利.png");
	TextureWin[1] = LoadGraph("res/GameScene/リザルト/2Pの勝利.png");
	TextureWin[2] = LoadGraph("res/GameScene/リザルト/3Pの勝利.png");
	TextureWin[3] = LoadGraph("res/GameScene/リザルト/4Pの勝利.png");

}

PlayScene::~PlayScene()
{
	for (int i = 0; i < kTextureMax; i++)
	{
		DeleteGraph(Texture[i]);
		if (i < 10)
		{
			DeleteGraph(TextureNumberRed[i]);
			DeleteGraph(TextureNumberBlue[i]);
			DeleteGraph(TextureNumberBlack[i]);
			DeleteGraph(TextureNumberWhite[i]);

			DeleteGraph(TextureResultNumberRed[i]);
			DeleteGraph(TextureResultNumberBlue[i]);
			DeleteGraph(TextureResultNumberBlack[i]);
			DeleteGraph(TextureResultNumberWhite[i]);
			if (i < 6)
			{
				DeleteGraph(TextureSkillIcon[i]);
				DeleteGraph(TextureSkillCutIn[i]);
				DeleteGraph(TextureIcon[i]);
				if (i < 4)
				{
					DeleteGraph(TexturePlayerNumber[i]);
					DeleteGraph(TextureSheets[i]);
					DeleteGraph(TextureWin[i]);
					DeleteGraph(TexturePixel[i]);
					DeleteGraph(TextureCutIn[i]);
					if (i < 3)
					{
						DeleteGraph(TextureReflectEffect[i]);
					}
				}
			}
		}
	}
}

void PlayScene::Exec()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	TextureBackGround_posX[i] -= 16;
	//	TextureBackGround_posY[i] += 9;
	//	if (TextureBackGround_posX[i] == -1280)
	//	{
	//		TextureBackGround_posX[i] += 2560;
	//		TextureBackGround_posY[i] -= 1440;
	//	}

	//	TextureBackGround_posX_2[i] -= 16;
	//	TextureBackGround_posY_2[i] += 9;
	//	if (TextureBackGround_posX_2[i] == -1280)
	//	{
	//		TextureBackGround_posX_2[i] += 2560;
	//		TextureBackGround_posY_2[i] -= 1440;
	//	}
	//}

	//デバッグ用
	if (IsKeyPushed(KEY_INPUT_R))
	{
		OwnPieceRed = 0;
		OwnPieceBlue = 0;
		OwnPieceBlack = 0;
		OwnPieceWhite = 0;

		for (int i = 0; i < 4; i++)
		{
			skillState[i] = kUsedSkill;
		}

		result[0] = 16;
		result[1] = 13;
		result[2] = 10;
		result[3] = 20;
		result[4] = 5;

		for (int i = 0; i < 4; i++)
		{
			countPiece[i] = result[i];
			order[i] = i;
		}

		int j = 0;

		for (int i = 0; i < MaxPiece; i++)
		{
			result[j]--;

			resultColor[i] = j;

			if (result[j] == 0)
			{
				j++;
			}
		}

		MaxOrder = 0;

		resultCount = 0;
		resultFlameCount = 0;

		for (int i = 0; i < 4; i++)
		{
			orderNumber[i] = countPiece[i];
			order[i] = i;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (orderNumber[i] > orderNumber[j])
				{
					int tmp = order[i];
					order[i] = order[j];
					order[j] = tmp;

					int tmp_2 = orderNumber[i];
					orderNumber[i] = orderNumber[j];
					orderNumber[j] = tmp_2;

				}
			}
		}

		phase = kResultPhase;
	}
	if (IsKeyPushed(KEY_INPUT_N))
	{
		switch (turn)
		{
		case kRed:
			OwnPieceRed--;
			break;
		case kBlue:
			OwnPieceBlue--;
			break;
		case kBlack:
			OwnPieceBlack--;
			break;
		case kWhite:
			OwnPieceWhite--;
			break;
		case kBlank:
			break;
		default:
			break;
		}

		phase = kFinishPhase;

		piece[turnNumber].color = kBlank;
	}

	countFrame++;

	switch (phase)
	{
	case kGameStart:

		if (countFrame > 60)
		{
			phase = kInitializePhase;
		}

		break;
	case kInitializePhase:
		
		piece[turnNumber].color = turn;

		switch (turn)
		{
		case kRed:

			piece[turnNumber].pos_x = 230.0f + 22.5f;
			piece[turnNumber].pos_y = 110.0f + 22.5f;

			break;
		case kBlue:

			piece[turnNumber].pos_x = 1050.0f - 22.5f;
			piece[turnNumber].pos_y = 110.0f + 22.5f;

			break;
		case kBlack:
			
			piece[turnNumber].pos_x = 230.0f + 22.5f;
			piece[turnNumber].pos_y = 610.0f - 22.5f;

			break;
		case kWhite:
			
			piece[turnNumber].pos_x = 1050.0f - 22.5f;
			piece[turnNumber].pos_y = 610.0f - 22.5f;

			break;
		}

		powerGauge = 0;
		variateGauge = 1;

		cutIn_y = 0;
		countCutIn = 0;

		variateGauge = 0;
		powerGauge = 0;
		gaugeDirection = true;

		phase = kCutInPhase;

		break;
	case kCutInPhase:
		
		if (cutIn_y < 255)
		{
			cutIn_y += 10;
		}

		countCutIn++;

		if (countCutIn > 100)
		{
			phase = kDecideThetaPhase;
		}

		break;
	case kDecideThetaPhase:
		
		//でバック用
		if (IsKeyPushed(KEY_INPUT_A))
		{
			switch (turn)
			{
			case kRed:
				OwnPieceRed--;
				break;
			case kBlue:
				OwnPieceBlue--;
				break;
			case kBlack:
				OwnPieceBlack--;
				break;
			case kWhite:
				OwnPieceWhite--;
				break;
			case kBlank:
				break;
			default:
				break;
			}
			piece[turnNumber].SetV(0);
			pos_X_kami = 0;
			pos_Y_kami = 0;
			phase = kSkillKaminoitte;
		}

		theta += 2;

		if (IsKeyPushed(KEY_INPUT_SPACE))
		{
			piece[turnNumber].SetTheta(450.0f - theta > 360.0f ? 90.0f - theta : 450.0f - theta);
			phase = kDecidePowerPhase;
		}

		if (IsKeyPushed(KEY_INPUT_S) && skillState[turnNumber % 4] != kUsedSkill)
		{
			switch (skillState[turnNumber % 4])
			{
			case kActiveSkill:
				
				skillState[turnNumber % 4] = kInactiveSkill;
				
				break;
			case kInactiveSkill:

				skillState[turnNumber % 4] = kActiveSkill;
				
				break;
			}
		}

		break;
	case kDecidePowerPhase:
		
		switch (gaugeDirection)
		{
		case true:
			
			variateGauge += 2;
			powerGauge += variateGauge;
			
			if (powerGauge > 4000)
			{
				powerGauge = 4000;
				variateGauge = 129;
				gaugeDirection = false;
			}

			break;
		case false:

			variateGauge -= 2;
			powerGauge -= variateGauge;

			if (powerGauge < 0)
			{
				variateGauge = 0;
				powerGauge = 0;
				gaugeDirection = true;
			}

			break;
		}

		if (IsKeyPushed(KEY_INPUT_SPACE))
		{
			piece[turnNumber].isMoving = true;
			
			//仮数値
			piece[turnNumber].SetV(10 + (0.1f * powerGauge / 40));
			
			phase = kReflectPhase;

			if (skillState[turnNumber % 4] == kActiveSkill)
			{
				phase = kSkillCutInPhase;

				cutIn_x = 0;

				countCutIn = 0;;
			}

			switch (turn)
			{
			case kRed:
				OwnPieceRed--;
				break;
			case kBlue:
				OwnPieceBlue--;
				break;
			case kBlack:
				OwnPieceBlack--;
				break;
			case kWhite:
				OwnPieceWhite--;
				break;
			}
		}

		break;
	case kSkillCutInPhase:

		countCutIn++;

		if (countCutIn > 100)
		{
			phase = kReflectPhase;

			Skill(piece, turnNumber);
		}

		break;
	case kSkillKaminoitte:

		KAMINOITTE(piece, turnNumber);

		if (IsKeyPushed(KEY_INPUT_SPACE))
		{
			for (int i = 0; i < MaxPiece; i++)
			{
				if (i == turnNumber)
				{
					continue;
				}

				float DistanceX = piece[turnNumber].pos_x - piece[i].pos_x;
				float DistanceY = piece[turnNumber].pos_y - piece[i].pos_y;
				float CircleDistance = powf(DistanceX, 2.0f) + powf(DistanceY, 2.0f);
				float CollidedDistanceCircle = powf((piece[turnNumber].kRadius + piece[i].kRadius), 2.0f);

				if (CircleDistance < CollidedDistanceCircle)
				{
					piece[i].color = kBlank;
				}
			}

			phase = kTurnOverPhase;
		}

		break;
	case kReflectPhase:

		for (int i = 0; i < MaxPiece; i++)
		{
			if (piece[i].GetV() > 0)
			{
				break;
			}
			if (i == MaxPiece - 1)
			{
				phase = kTurnOverPhase;
				if (Hanabi)
				{
					HanabiCount = 0;
					phase = kSkillHanabi;
				}
				if (Inbijiburu)
				{
					for (int i = 0; i < MaxPiece; i++)
					{
						if (i == turnNumber)
						{
							continue;
						}

						float DistanceX = piece[turnNumber].pos_x - piece[i].pos_x;
						float DistanceY = piece[turnNumber].pos_y - piece[i].pos_y;
						float CircleDistance = powf(DistanceX, 2.0f) + powf(DistanceY, 2.0f);
						float CollidedDistanceCircle = powf((piece[turnNumber].kRadius + piece[i].kRadius), 2.0f);

						if (CircleDistance < CollidedDistanceCircle)
						{
							piece[i].color = kBlank;
						}
					}
				}
			}
		}

		if (Inbijiburu)
		{
			piece[turnNumber].CalculateV();
			
			break;
		}

		for (int i = 0; i < MaxPiece; i++)
		{
			piece[i].CalculateV();

			if (piece[i].isMoving)
			{
				Collision::ReflectPiece(piece, i);
			}
		}

		Collision::ChengeIsMoving(piece);

		break;
	case kSkillHanabi:

		HanabiCount++;

		for (int i = 0; i < MaxPiece; i++)
		{
			if (i == turnNumber)
			{
				continue;
			}

			float DistanceX = piece[turnNumber].pos_x - piece[i].pos_x;
			float DistanceY = piece[turnNumber].pos_y - piece[i].pos_y;
			float CircleDistance = sqrtf(powf(DistanceX, 2.0f) + powf(DistanceY, 2.0f));

			if (CircleDistance - 22.5f < HanabiCount / 3)
			{
				piece[i].color = piece[turnNumber].color;
			}
		}

		if (HanabiCount > 180)
		{
			phase = kFinishPhase;
		}

		break;
	case kSkillMagunetto:




		break;
	case kTurnOverPhase:

		if (piece[turnNumber].pos_x > 873 ||
			piece[turnNumber].pos_x < 443 ||
			piece[turnNumber].pos_y > 554 ||
			piece[turnNumber].pos_y < 160)
		{
			phase = kFinishPhase;
			break;
		}

		for (int i = 0; i < 64; i++)
		{
			map[i / 8][i % 8] = -1;
		}

		for (int col = 0; col <= 7; col++)
		{
			for (int row = 0; row <= 7; row++)
			{
				for (int i = 0; i < 64; i++)
				{
					if (piece[i].color == kBlank)
					{
						continue;
					}

					if (piece[i].pos_x > 443 + 49.25f * (row) &&
						piece[i].pos_x < 443 + 49.25f * (row + 1) &&
						piece[i].pos_y > 163 + 49.25f * (col) &&
						piece[i].pos_y < 163 + 49.25f * (col + 1))
					{
						if (i == turnNumber)
						{
							map[col][row] = i;
							posX = row;
							posY = col;

							continue;
						}

						if (map[col][row] != -1)
						{
							if (powf(piece[map[col][row]].pos_x - 465.5f + 49.25f * (row + 1), 2.0f) + powf(piece[map[col][row]].pos_y - 185.5f + 49.25f * (col + 1), 2.0f) <
								powf(piece[i].pos_x - 465.5f + 49.25f * (row + 1), 2.0f) + powf(piece[i].pos_y - 185.5f + 49.25f * (col + 1), 2.0f))
							{
								continue;
							}
							else
							{
								map[col][row] = i;
							}
						}
						else
						{
							map[col][row] = i;
						}
					}

				}

				map[col][row] == -1 ? map[col][row] = kBlank : map[col][row] = piece[map[col][row]].color ;

			}
		}
	
		for (int i = 0; i < 64; i++)
		{
			previousMap[i / 8][i % 8] = map[i / 8][i % 8];
		}

		othello.TurnOverMethod(&posX, &posY, map, turn);
		
		animationCount = 0;
		phase = kTurnOverAnimationPhase;

		break;
	case kTurnOverAnimationPhase:

		animationCount++;

		if (animationCount > 180)
		{
			for (int Y = 0; Y < col; Y++)
			{
				for (int X = 0; X < row; X++)
				{
					if (map[Y][X] != previousMap[Y][X])
					{
						for (int i = 0; i < MaxPiece; i++)
						{
							if (piece[i].pos_x > 443 + 49.25f * (X) &&
								piece[i].pos_x < 443 + 49.25f * (X + 1) &&
								piece[i].pos_y > 163 + 49.25f * (Y) &&
								piece[i].pos_y < 163 + 49.25f * (Y + 1))
							{
								piece[i].color = turn;
							}
						}

						previousMap[Y][X] = map[Y][X];
					}
				}
			}
		}

		if (animationCount > 300)
		{
			phase = kFinishPhase;
		}

		break;
	case kFinishPhase:

		switch (turn)
		{
		case kRed:
			turn = kBlue;
			break;
		case kBlue:
			turn = kBlack;
			break;
		case kBlack:
			turn = kWhite;
			break;
		case kWhite:
			turn = kRed;
			break;
		}

		if (skillState[turnNumber % 4] == kActiveSkill)
		{
			switch (Character[turnNumber % 4])
			{
			case kHANABI:
				Hanabi = false;
				break;
			case kINBIJIBURU:
				Inbijiburu = false;
				break;
			}
			skillState[turnNumber % 4] = kUsedSkill;
		}

		phase = kInitializePhase;

		if (OwnPieceRed == 0 &&
			OwnPieceBlue == 0 &&
			OwnPieceBlack == 0 &&
			OwnPieceWhite == 0)
		{
			phase = kGameFinish;
		}

		turnNumber++;
		
		break;
	case kGameFinish:

		if (countFrame > 60)
		{
			phase = kResultPhase;

			for (int i = 0; i < 4; i++)
			{
				result[i] = 0;
				countPiece[i] = 0;
			}

			for (int i = 0; i < MaxPiece; i++)
			{
				switch (piece[i].color)
				{
				case kRed:
					result[0]++;
					countPiece[0]++;
					break;
				case kBlue:
					result[1]++;
					countPiece[1]++;
					break;
				case kBlack:
					result[2]++;
					countPiece[2]++;
					break;
				case kWhite:
					result[3]++;
					countPiece[3]++;
					break;
				case kBlank:
					result[4]++;
					countPiece[4]++;
					break;
				}
			}

			int j = 0;

			for (int i = 0; i < MaxPiece; i++)
			{
				result[j]--;

				resultColor[i] = j;

				if (result[j] == 0)
				{
					j++;
				}
			}

			resultCount = 0;
			resultFlameCount = 0;

			MaxOrder = 0;

			for (int i = 0; i < 4; i++)
			{
				orderNumber[i] = countPiece[i];
				order[i] = i;
			}

			for (int i = 0; i < 4; i++)
			{
				for (int j = i + 1; j < 4; j++)
				{
					if (orderNumber[i] > orderNumber[j])
					{
						int tmp = order[i];
						order[i] = order[j];
						order[j] = tmp;

						int tmp_2 = orderNumber[i];
						orderNumber[i] = orderNumber[j];
						orderNumber[j] = tmp_2;

					}
				}
			}
		}

		break;
	case kResultPhase:

		resultFlameCount++;

		if (resultFlameCount > 1 && resultCount < 64)
		{
			resultFlameCount = 0;

			resultCount++;
		}

		if (resultFlameCount > 180 && MaxOrder < 4)
		{
			MaxOrder++;

			resultFlameCount = 121;
		}

		break;
	}
}

void PlayScene::Draw()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	DrawGraph(TextureBackGround_posX[i], TextureBackGround_posY[i], Texture[kBackGroundBlue], TRUE);
	//	DrawGraph(TextureBackGround_posX_2[i], TextureBackGround_posY_2[i], Texture[kBackGroundBlue], TRUE);
	//}

	DrawGraph(0, 0, Texture[kBackGroundBlue], TRUE);

	switch (stage)
	{
	case 1:
		DrawGraph(0, 0, Texture[kBoard_Stage1], TRUE);
		break;
	case 2:
		DrawGraph(0, 0, Texture[kBoard_Stage2], TRUE);
		break;
	case 3:
		DrawGraph(0, 0, Texture[kBoard_Stage3], TRUE);
		break;
	}

	DrawGraph(443, 163, Texture[kBoard_Othello], FALSE);

	for (int i = 0; i < 4; i++)
	{
		DrawGraph(15 + i % 2 * 1085, 184 + i / 2 * 186, TextureIcon[Character[i]], TRUE);
	}

	DrawGraph(15, 184, Texture[kIcon_1P], TRUE);
	DrawGraph(1100, 184, Texture[kIcon_2P], TRUE);
	DrawGraph(15, 370, Texture[kIcon_3P], TRUE);
	DrawGraph(1100, 370, Texture[kIcon_4P], TRUE);
	
	DrawGraph(25, 4, Texture[kOwnPiece_1P], TRUE);
	DrawGraph(1200, 4, Texture[kOwnPiece_2P], TRUE);
	DrawGraph(25, 625, Texture[kOwnPiece_3P], TRUE);
	DrawGraph(1200, 625, Texture[kOwnPiece_4P], TRUE);

	if (OwnPieceRed >= 10)
	{
		DrawGraph(45, 40, TextureNumberRed[OwnPieceRed - 10], TRUE);
		DrawGraph(15, 40, TextureNumberRed[1], TRUE);
	}
	else
	{
		DrawGraph(45, 40, TextureNumberRed[OwnPieceRed], TRUE);
	}

	if (OwnPieceBlue >= 10)
	{
		DrawGraph(1220, 40, TextureNumberBlue[OwnPieceBlue - 10], TRUE);
		DrawGraph(1190, 40, TextureNumberBlue[1], TRUE);
	}
	else
	{
		DrawGraph(1220, 40, TextureNumberBlue[OwnPieceBlue], TRUE);
	}
	
	if (OwnPieceBlack >= 10)
	{
		DrawGraph(45, 661, TextureNumberBlack[OwnPieceBlack - 10], TRUE);
		DrawGraph(15, 661, TextureNumberBlack[1], TRUE);
	}
	else
	{
		DrawGraph(45, 661, TextureNumberBlack[OwnPieceBlack], TRUE);
	}
	
	if (OwnPieceWhite >= 10)
	{
		DrawGraph(1220, 661, TextureNumberWhite[OwnPieceWhite - 10], TRUE);
		DrawGraph(1190, 661, TextureNumberWhite[1], TRUE);
	}
	else
	{
		DrawGraph(1220, 661, TextureNumberWhite[OwnPieceWhite], TRUE);
	}

	for (int i = 0; i < 4; i++)
	{
		switch (skillState[i])
		{
		case kActiveSkill:
			if (countFrame % 40 < 20)
			{
				DrawGraph(22 + i % 2 * 1086, 104 + i / 2 * 442, TextureSkillIcon[Character[i]], TRUE);
			}
			break;
		case kInactiveSkill:
			DrawGraph(22 + i % 2 * 1086, 104 + i / 2 * 442, TextureSkillIcon[Character[i]], TRUE);
			break;
		case kUsedSkill:

			break;
		}
	}

	if (phase != kResultPhase)
	{
		for (int i = 0; i < MaxPiece; i++)
		{
			switch (piece[i].color)
			{
			case kRed:

				DrawGraph(piece[i].pos_x - piece[i].kRadius, piece[i].pos_y - piece[i].kRadius, Texture[kRedPiece], TRUE);

				break;
			case kBlue:

				DrawGraph(piece[i].pos_x - piece[i].kRadius, piece[i].pos_y - piece[i].kRadius, Texture[kBluePiece], TRUE);

				break;
			case kBlack:

				DrawGraph(piece[i].pos_x - piece[i].kRadius, piece[i].pos_y - piece[i].kRadius, Texture[kBlackPiece], TRUE);

				break;
			case kWhite:

				DrawGraph(piece[i].pos_x - piece[i].kRadius, piece[i].pos_y - piece[i].kRadius, Texture[kWhitePiece], TRUE);

				break;
			}
		}
	}

	switch (phase)
	{
	case kGameStart:

		DrawGraph(0, 226.5f, Texture[kCutInStart], TRUE);

		break;
	case kInitializePhase:

		break;
	case kCutInPhase:

		DrawGraph(0, cutIn_y, TextureCutIn[turnNumber % 4], TRUE);

		break;
	case kDecideThetaPhase:
		
		DrawRotaGraph2(piece[turnNumber].pos_x,
			piece[turnNumber].pos_y,
			22.5f, 282.0f, 1.0f, theta / 180 * M_PI,
			Texture[kArrow],
			TRUE,
			FALSE
		);
		
		break;
	case kDecidePowerPhase:

		DrawRotaGraph2(piece[turnNumber].pos_x,
			piece[turnNumber].pos_y,
			22.5f, 282.0f, 1.0f, theta / 180 * M_PI,
			Texture[kArrow],
			TRUE,
			FALSE
		);

		DrawRectGraph(436, 592, 0, 0, powerGauge / 10, 80, Texture[kGauge], TRUE, FALSE);
		DrawGraph(436, 592, Texture[kGaugeWhite], TRUE);

		break;
	case kSkillCutInPhase:

		DrawGraph(cutIn_x, 226.5f, TextureSkillCutIn[Character[turnNumber % 4]], TRUE);

		break;
	case kReflectPhase:

		DrawRectGraph(436, 592, 0, 0, powerGauge / 10, 80, Texture[kGauge], TRUE, FALSE);
		DrawGraph(436, 592, Texture[kGaugeWhite], TRUE);

		break;
	case kSkillHanabi:

		int cr;

		switch (turn)
		{
		case kRed:
			cr = GetColor(255, 0, 0);
			break;
		case kBlue:
			cr = GetColor(0, 0, 255);
			break;
		case kBlack:
			cr = GetColor(0, 0, 0);
			break;
		case kWhite:
			cr = GetColor(200, 200, 200);
			break;
		case kBlank:
			break;
		default:
			break;
		}

		DrawCircle(piece[turnNumber].pos_x, piece[turnNumber].pos_y, HanabiCount / 3, cr, FALSE);

		break;
	case kTurnOverAnimationPhase:

		for (int Y = 0; Y < col; Y++)
		{
			for (int X = 0; X < row; X++)
			{
				if (posX == X && posY == Y)
				{
					if (animationCount < 120)
					{
						continue;
					}
					else
					{
						if (countFrame % 60 < 30)
						{
							switch (previousMap[Y][X])
							{
							case kRed:
								DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelRed], TRUE);
								break;
							case kBlue:
								DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelBlue], TRUE);
								break;
							case kBlack:
								DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelBlack], TRUE);
								break;
							case kWhite:
								DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelWhite], TRUE);
								break;
							}
						}
					}
				}

				switch (previousMap[Y][X])
				{
				case kRed:
					DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelRed], TRUE);
					break;
				case kBlue:
					DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelBlue], TRUE);
					break;
				case kBlack:
					DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelBlack], TRUE);
					break;
				case kWhite:
					DrawGraph(443.125f + X * 49.25f, 163.125f + Y * 49.25f, TexturePixel[kPixelWhite], TRUE);
					break;
				}
			}
		}

		break;
	case kGameFinish:

		DrawGraph(0, 226.5f, Texture[kCutInFinish], TRUE);

		break;
	case kResultPhase:

		for (int i = 0; i < resultCount + 1; i++)
		{
			switch (resultColor[i])
			{
			case kRed:
				DrawGraph(445.125f + i % 8 * 49.25f, 165.125f + i / 8 * 49.25f, Texture[kRedPiece], TRUE);
				break;
			case kBlue:
				DrawGraph(445.125f + i % 8 * 49.25f, 165.125f + i / 8 * 49.25f, Texture[kBluePiece], TRUE);
				break;
			case kBlack:		
				DrawGraph(445.125f + i % 8 * 49.25f, 165.125f + i / 8 * 49.25f, Texture[kBlackPiece], TRUE);
				break;
			case kWhite:		
				DrawGraph(445.125f + i % 8 * 49.25f, 165.125f + i / 8 * 49.25f, Texture[kWhitePiece], TRUE);
				break;
			}
		}

		if (resultFlameCount > 120)
		{
			DrawGraph(0, 0, Texture[kBackGroundResult], TRUE);

			DrawGraph(501, 34, Texture[kResultTitle], TRUE);

			for (int i = 0; i < 4; i++)
			{
				DrawGraph(454, 246 + i * 110, TexturePlayerNumber[i], TRUE);

				DrawGraph(802, 246 + i * 110, TextureSheets[i], TRUE);
			}

			for (int i = 0; i < MaxOrder; i++)
			{
				switch (order[i])
				{
				case 0:
					if (countPiece[0] >= 10)
					{
						DrawGraph(730, 246, TextureResultNumberRed[countPiece[0] % 10], TRUE);
						DrawGraph(660, 246, TextureResultNumberRed[countPiece[0] / 10], TRUE);
					}
					else
					{
						DrawGraph(730, 246, TextureResultNumberRed[countPiece[0]], TRUE);
					}
					break;
				case 1:
					if (countPiece[1] >= 10)
					{
						DrawGraph(730, 356, TextureResultNumberBlue[countPiece[1] % 10], TRUE);
						DrawGraph(660, 356, TextureResultNumberBlue[countPiece[1] / 10], TRUE);
					}
					else
					{
						DrawGraph(730, 356, TextureResultNumberBlue[countPiece[1]], TRUE);
					}
					break;
				case 2:
					if (countPiece[2] >= 10)
					{
						DrawGraph(730, 466, TextureResultNumberBlack[countPiece[2] % 10], TRUE);
						DrawGraph(660, 466, TextureResultNumberBlack[countPiece[2] / 10], TRUE);
					}
					else
					{
						DrawGraph(730, 466, TextureResultNumberBlack[countPiece[2]], TRUE);
					}
					break;
				case 3:
					if (countPiece[3] >= 10)
					{
						DrawGraph(730, 576, TextureResultNumberWhite[countPiece[3] % 10], TRUE);
						DrawGraph(660, 576, TextureResultNumberWhite[countPiece[3] / 10], TRUE);
					}
					else
					{
						DrawGraph(730, 576, TextureResultNumberWhite[countPiece[3]], TRUE);
					}
					break;
				}
			}
		}

		if (resultFlameCount > 240)
		{
			DrawGraph(175, 176, TextureWin[order[3]], TRUE);
		}

		if (resultFlameCount > 300)
		{
			DrawGraph(459, 545, Texture[kReturnTitle], TRUE);
			
			if (IsKeyPushed(KEY_INPUT_RETURN))
			{
				FinishedGame = true;
			}
		}

		break;
	default:
		break;
	}
}

bool PlayScene::IsEnd() const
{
	SceneManager::SetNextScene(SceneID_Title);

	// @@Dummy 遷移確認用の仮処理
	return (FinishedGame);
}

void PlayScene::Skill(Piece piece[], int num)
{
	switch (Character[num % 4])
	{
	case kHANABI:
		Hanabi = true;
		break;
	case kTIKARAKOSO:
		piece[num].SetV(piece[num].GetV() * 2);
		break;
	case kINBIJIBURU:
		Inbijiburu = true;
		break;
	case kKAMINOITTE:
		piece[num].SetV(0);
		pos_X_kami = 0;
		pos_Y_kami = 0;
		phase = kSkillKaminoitte;
		break;
	case kHEBII:
		phase = kSkillHebii;
		break;
	case kMAGUNETTO:
		Magunetto = true;
		break;
	}
}

void PlayScene::KAMINOITTE(Piece piece[], int num)
{
	if (IsKeyHeld(KEY_INPUT_UP))
	{
		piece[num].pos_y -= 4.0f;
		if (piece[num].pos_y < piece[num].GetUp() + 22.5f)
		{
			piece[num].pos_y = piece[num].GetUp() + 22.5f;
		}
	}
	if (IsKeyHeld(KEY_INPUT_DOWN))
	{
		piece[num].pos_y += 4.0f;
		if (piece[num].pos_y > piece[num].GetDown() - 22.5f)
		{
			piece[num].pos_y = piece[num].GetDown() - 22.5f;
		}
	}
	if (IsKeyHeld(KEY_INPUT_RIGHT))
	{
		piece[num].pos_x += 4.0f;
		if (piece[num].pos_x > piece[num].GetRight() - 22.5f)
		{
			piece[num].pos_x= piece[num].GetRight() - 22.5f;
		}
	}
	if (IsKeyHeld(KEY_INPUT_LEFT))
	{
		piece[num].pos_x -= 4.0f;
		if (piece[num].pos_x < piece[num].GetLeft() - 22.5f)
		{
			piece[num].pos_x = piece[num].GetLeft() - 22.5f;
		}
	}
}

void PlayScene::HEBII(Piece piece[], int num)
{

}

void PlayScene::MAGUNETTO()
{
	
}
