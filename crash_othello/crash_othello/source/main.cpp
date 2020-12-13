#include "common.h"
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

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

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
	for (int i = 0; i < 5; i++)
	{
		if (!piece[i].init)
		{
			if (i == 0)
			{
				piece[i].SetTheta(225.0f);
			}
			piece[i].pos_x = 200.0f * (i + 1);
			piece[i].pos_y = 130.0f * (i + 1);
			piece[i].init = true;
			piece[i].color = kBlack;
		}
	}

	piece[0].SetV(50);
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		piece[0].SetV(50);
		piece[0].isMoving = true;
	}

	for (int i = 0; i < 5; i++)
	{
		piece[i].CalculateV();

		if (piece[i].isMoving)
		{
			collision.ReflectPiece(piece, i);
		}
	}

	collision.ChengeIsMoving(piece);
}

void DrawProcessing()
{
	for (int i = 0; i < 5; i++)
	{
		DrawCircle(piece[i].pos_x, piece[i].pos_y, 22.5f, GetColor(0, 0, 0), true);
	}
}
