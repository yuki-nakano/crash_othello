﻿#include "common.h"
#include "main.h"

void GameProcessing();
void DrawProcessing();

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(definition.Widht, definition.Height, 16);
	SetBackgroundColor(255, 255, 255);
	SetMainWindowText("CrashOthello");


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	while (true)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1 ||
			CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;        // エラーが起きたらループを抜ける
		}
		else
		{
			//フレームごとにキーの状態更新
			UpdateKeyStatus();

			//ゲーム処理
			GameProcessing();

			ClearDrawScreen();
			clsDx();
			//描画処理
			DrawProcessing();
			ScreenFlip();
		}
	}

	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}

void  GameProcessing()
{

}

void DrawProcessing()
{

}
