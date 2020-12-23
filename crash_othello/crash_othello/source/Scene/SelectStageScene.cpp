#include "../common.h"

SelectStageScene::SelectStageScene()
{
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 3;
	SceneBase::Choice = 0;

	TextureData::BackGround_BLUE = LoadGraph("res/setumeihaikei.png");
	TextureData::StageSelect = LoadGraph("res/ステージ選択.png");
}

SelectStageScene::~SelectStageScene()
{

}

void SelectStageScene::Exec()
{
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
			SceneManager::SetNextScene(SceneID_Title);
			//SceneManager::SetNextScene(SceneID_Play);
			break;
		case 2:
			SceneBase::Stage = 2;
			SceneManager::SetNextScene(SceneID_Title);
			//SceneManager::SetNextScene(SceneID_Play);
			break;
		case 3:
			SceneBase::Stage = 3;
			SceneManager::SetNextScene(SceneID_Title);
			//SceneManager::SetNextScene(SceneID_Play);
			break;
		default:
			break;
		}
	}
}

void SelectStageScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(20, 20, 205, 70, GetColor(0, 0, 0), false);
	DrawBox(1104, 20, 1260, 85, GetColor(0, 0, 0), false);

	DrawGraph(440, 0, TextureData::StageSelect, true);

	if (Choice == 0)
	{
		DrawBox(70, 120, 425, 640, GetColor(0, 0, 0), false);
		DrawBox(462, 120, 819, 640, GetColor(0, 0, 0), false);
		DrawBox(855, 120, 1210, 640, GetColor(0, 0, 0), false);
	}
	else if (Choice == 1)
	{
		DrawBox(60, 110, 435, 650, GetColor(0, 0, 0), false);
		DrawBox(462, 120, 819, 640, GetColor(0, 0, 0), false);
		DrawBox(855, 120, 1210, 640, GetColor(0, 0, 0), false);
	}
	else if (Choice == 2)
	{
		DrawBox(70, 120, 425, 640, GetColor(0, 0, 0), false);
		DrawBox(452, 110, 829, 650, GetColor(0, 0, 0), false);
		DrawBox(855, 120, 1210, 640, GetColor(0, 0, 0), false);
	}
	else if (Choice == 3)
	{
		DrawBox(70, 120, 425, 640, GetColor(0, 0, 0), false);
		DrawBox(462, 120, 819, 640, GetColor(0, 0, 0), false);
		DrawBox(845, 110, 1220, 650, GetColor(0, 0, 0), false);
	}

		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "SelectStageScene", GetColor(0, 0, 0));
}

bool SelectStageScene::IsEnd() const
{
	if (IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0)
	{
		TextureData::DeleteTex();
		return true;
	}
}