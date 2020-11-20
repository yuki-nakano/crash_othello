#include "common.h"
#include "main.h"

Othello othello;
int map[col][row];
Piece phase = kWhite;

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
	SetGraphMode(Widht, Height, 16);
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
	othello.InitBoard(map);
	othello.MoveCursor(&othello.X, &othello.Y);
	if (map[othello.Y][othello.X] == Piece::kNone && CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		map[othello.Y][othello.X] = phase;
		othello.TurnOverMethod(&othello.X, &othello.Y, map, phase);
		switch (phase)
		{
		case Piece::kWhite:
			phase = Piece::kBlack;
			break;
		case Piece::kBlack:
			phase = Piece::kWhite;
			break;
		default:
			break;
		}
	}
}

void DrawProcessing()
{
	othello.DrawOthello(map);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			DrawBox(i * 45, j * 45, (i + 1) * 45, (j + 1) * 45, GetColor(0, 0, 255), false);
		}
	}
	DrawBox(othello.X * 45, othello.Y * 45, (othello.X + 1) * 45, (othello.Y + 1) * 45, GetColor(255, 0, 0), false);
	DrawBox(othello.X * 45+1, othello.Y * 45+1, (othello.X + 1) * 45-1, (othello.Y + 1) * 45-1, GetColor(255, 0, 0), false);
	DrawCircle(472.5f, 67.5f, 22.5f, GetColor(0, 0, 0), true);
}
