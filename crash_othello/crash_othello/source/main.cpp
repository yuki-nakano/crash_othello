#include "common.h"
#include "main.h"

void GameProcessing();
void DrawProcessing();

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(Widht, Height, 16);
	SetBackgroundColor(255, 255, 255);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	//管理クラスの作成
	SceneManager* pSceneMng = new SceneManager();

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

			//シーン処理
			pSceneMng->Exec();

			//シーン描画
			pSceneMng->Draw();

			//描画処理
			DrawProcessing();
			ScreenFlip();
		}
	}

	delete pSceneMng;
	pSceneMng = nullptr;

	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}

void  GameProcessing()
{
	/*fadeStatus = fade.RunFade(fadeType, fadeSpeed);
	switch (fadeStatus)
	{
	case kFinishedFadeOut:
		fadeType = kFadeIn;
		phase = nextPhase;
		break;
	case kFinishedFadeIn:
		fadeType = kFadeNot;
		break;
	default:
		break;
	}

	switch (phase)
	{
	case kTitle:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kDescription;
			fadeSpeed = kNormal;
		}
		break;
	case kOption:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kDescription;
			fadeSpeed = kNormal;
		}
		else if (CheckHitKey(KEY_INPUT_T) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kTitle;
			fadeSpeed = kNormal;
		}
		else if (CheckHitKey(KEY_INPUT_S) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kCheckSkill;
			fadeSpeed = kNormal;
		}
		else if (CheckHitKey(KEY_INPUT_TAB) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kPlay;
			fadeSpeed = kNormal;
		}
		break;
	case kDescription:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kSelectStage;
			fadeSpeed = kNormal;
		}
		break;
	case kSelectStage:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kPlay;
			fadeSpeed = kNormal;
		}
		break;
	case kPlay:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kResult;
			fadeSpeed = kNormal;
		}
		else if (CheckHitKey(KEY_INPUT_TAB) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kOption;
			fadeSpeed = kNormal;
		}
		break;
	case kCheckSkill:
		if (CheckHitKey(KEY_INPUT_S) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kOption;
			fadeSpeed = kNormal;
		}
	case kResult:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kOutcome;
			fadeSpeed = kFast;
		}
		break;
	case kOutcome:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kBacktoTitle;
			fadeSpeed = kFast;
		}
		break;
	case kBacktoTitle:
		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			fadeType = kFadeOut;
			nextPhase = kTitle;
			fadeSpeed = kNormal;
		}
		break;
	}*/
}

void DrawProcessing()
{
	/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	switch (phase)
	{
	case kTitle:
		DrawString(0, 0, "title\nSPACE => description", GetColor(255, 0, 0));
		break;
	case kOption:
		DrawString(0, 0, "option\nSPACE => description\nT => title\nS => checkskill\nTAB => play", GetColor(255, 0, 0));
		break;
	case kDescription:
		DrawString(0, 0, "description\nSPACE => selectstage", GetColor(255, 0, 0));
		break;
	case kSelectStage:
		DrawString(0, 0, "selectstage\nSPACE => play", GetColor(255, 0, 0));
		break;
	case kPlay:
		LoadGraphScreen(0, 0, "res/ゲーム画面背景_青.jpg", false);
		DrawString(0, 0, "play\nSPACE => result\nTAB => option", GetColor(255, 0, 0));
		break;
	case kCheckSkill:
		DrawString(0, 0, "checkskill\n S => option", GetColor(255, 0, 0));
		break;
	case kResult:
		DrawString(0, 0, "result\nSPACE => outcome", GetColor(255, 0, 0));
		break;
	case kOutcome:
		DrawString(0, 0, "outcome\nSPACE => backtotitle", GetColor(255, 0, 0));
		break;
	case kBacktoTitle:
		DrawString(0, 0, "backtotitle\n SPACE => title", GetColor(255, 0, 0));
		break;
	}
	fade.Draw();*/
}
