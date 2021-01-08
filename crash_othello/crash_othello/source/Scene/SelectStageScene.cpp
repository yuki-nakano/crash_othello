#include "../common.h"

//int Timer_Start = 0;
//bool SelectConfirm = false;

SelectStageScene::SelectStageScene()
{
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 3;
	SceneBase::Choice = 0;

	TextureData::BackGround_BLUE = LoadGraph("res/setumeihaikei.png");

	TextureData::Enter = LoadGraph("res/enter.png");
	TextureData::Esc = LoadGraph("res/esc.png");

	TextureData::StageSelect = LoadGraph("res/ステージ選択.png");

	TextureData::Stage1 = LoadGraph("res/ステージアイコン_ノーマル.png");
	TextureData::Stage2 = LoadGraph("res/ステージアイコン_クロス.png");
	TextureData::Stage3 = LoadGraph("res/ステージアイコン_ボウリング.png");

	TextureData::StageConfirm1 = LoadGraph("res/ノーマルステージ確定.png");
	TextureData::StageConfirm2 = LoadGraph("res/クロスステージ確定.png");
	TextureData::StageConfirm3 = LoadGraph("res/ボウリングステージ確定.png");


	SceneBase::back_posx1 = 0.0f;
	SceneBase::back_posy1 = 0.0f;
	SceneBase::back_posx2 = 0.0f;
	SceneBase::back_posy2 = -720.0f;
	SceneBase::back_posx3 = 1280.0f;
	SceneBase::back_posy3 = -720.0f;
	SceneBase::back_posx4 = 1280.0f;
	SceneBase::back_posy4 = -1440.0f;
	SceneBase::back_posx5 = 0.0f;
	SceneBase::back_posy5 = 720.0f;
	SceneBase::back_posx6 = 1280.0f;
	SceneBase::back_posy6 = 0.0f;

	SceneBase::scroll_speedx = 8.0f;
	SceneBase::scroll_speedy = 4.5f;
}

SelectStageScene::~SelectStageScene()
{

}

void SelectStageScene::Exec()
{
	back_posx1 -= scroll_speedx;
	back_posy1 += scroll_speedy;
	back_posx2 -= scroll_speedx;
	back_posy2 += scroll_speedy;
	back_posx3 -= scroll_speedx;
	back_posy3 += scroll_speedy;
	back_posx4 -= scroll_speedx;
	back_posy4 += scroll_speedy;
	back_posx5 -= scroll_speedx;
	back_posy5 += scroll_speedy;
	back_posx6 -= scroll_speedx;
	back_posy6 += scroll_speedy;

	if (back_posx1 <= -1280)
	{
		back_posx1 = 1280;
		back_posy1 = -720;
	}
	if (back_posx3 <= -1280)
	{
		back_posx3 = 1280;
		back_posy3 = -720;
	}
	if (back_posx2 <= -1280)
	{
		back_posx2 = 1280;
		back_posy2 = -1440;
	}
	if (back_posx4 <= -1280)
	{
		back_posx4 = 1280;
		back_posy4 = -1440;
	}
	if (back_posx5 <= -1280)
	{
		back_posx5 = 1280;
		back_posy5 = 0;
	}
	if (back_posx6 <= -1280)
	{
		back_posx6 = 1280;
		back_posy6 = 0;
	}

	//Timer_Start++;
	if (IsKeyPushed(KEY_INPUT_RIGHT))
	{
		if (Choice == 0)
		{
			Choice = 3;
		}
		else if (Choice < Choice_Max)
		{
			Choice += 1;
		}
	}
	else if (IsKeyPushed(KEY_INPUT_LEFT))
	{
		if (Choice > Choice_Min)
		{
			Choice -= 1;
		}
		else if (Choice == 0)
		{
			Choice = 1;
		}
	}

	if (IsKeyPushed(KEY_INPUT_RETURN))
	{
		switch (Choice)
		{
		case 1:
			SceneBase::Stage = 1;
			SceneManager::SetNextScene(SceneID_Play);
			//SceneManager::SetNextScene(SceneID_Play);
			break;
		case 2:
			SceneBase::Stage = 2;
			SceneManager::SetNextScene(SceneID_Play);
			//SceneManager::SetNextScene(SceneID_Play);
			break;
		case 3:
			SceneBase::Stage = 3;
			SceneManager::SetNextScene(SceneID_Play);
			//SceneManager::SetNextScene(SceneID_Play);
			break;
		default:
			break;
		}
	}
}

void SelectStageScene::Draw()
{
	DrawGraph(back_posx1, back_posy1, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx2, back_posy2, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx3, back_posy3, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx4, back_posy4, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx5, back_posy5, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx6, back_posy6, TextureData::BackGround_BLUE, false);

	DrawGraph(20, 20, TextureData::Enter, true);
	DrawGraph(1104, 20, TextureData::Esc, true);

	DrawGraph(440, 0, TextureData::StageSelect, true);

	if (Choice == 0)
	{
		DrawExtendGraph(70, 120, 425, 640, TextureData::Stage1, true);
		DrawExtendGraph(462, 120, 819, 640, TextureData::Stage2, true);
		DrawExtendGraph(855, 120, 1210, 640, TextureData::Stage3, true);
	}
	else if (Choice == 1)
	{
		DrawExtendGraph(60, 110, 435, 650, TextureData::Stage1, true);
		DrawExtendGraph(462, 120, 819, 640, TextureData::Stage2, true);
		DrawExtendGraph(855, 120, 1210, 640, TextureData::Stage3, true);
	}
	else if (Choice == 2)
	{
		DrawExtendGraph(70, 120, 425, 640, TextureData::Stage1, true);
		DrawExtendGraph(452, 110, 829, 650, TextureData::Stage2, true);
		DrawExtendGraph(855, 120, 1210, 640, TextureData::Stage3, true);
	}
	else if (Choice == 3)
	{
		DrawExtendGraph(70, 120, 425, 640, TextureData::Stage1, true);
		DrawExtendGraph(462, 120, 819, 640, TextureData::Stage2, true);
		DrawExtendGraph(845, 110, 1220, 650, TextureData::Stage3, true);
	}

		//画面左上にデバッグ用の文字を黒で表示する
	//DrawString(20, 20, "SelectStageScene", GetColor(0, 0, 0));
}

bool SelectStageScene::IsEnd() const
{
	/*if (IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0 && SelectConfirm == false)
	{
		Timer_Start = 0;
		SelectConfirm = true;
	}
	if (SelectConfirm == true && Timer_Start >= 120)
	{
		return true;
	}*/
	if (IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0)
	{
		TextureData::DeleteTex();
		return true;
	}
}