#include "../common.h"

SelectNumberOfPeopleScene::SelectNumberOfPeopleScene()
{
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 2;

	TextureData::BackGround_BLUE = LoadGraph("res/setumeihaikei.png");
	TextureData::NumberOfPeople = LoadGraph("res/プレイ人数選択.png");
}
SelectNumberOfPeopleScene::~SelectNumberOfPeopleScene()
{

}
void SelectNumberOfPeopleScene::Exec()
{
	if (IsKeyPushed(KEY_INPUT_RIGHT))
	{
		if (Choice == 0)
		{
			Choice = 2;
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

	if (Choice == 1 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		SceneBase::People_Max = 2;
		SceneManager::SetNextScene(SceneID_SelectCharacter);
	}
	else if (Choice == 2 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		SceneBase::People_Max = 4;
		SceneManager::SetNextScene(SceneID_SelectCharacter);
	}
	else if (IsKeyPushed(KEY_INPUT_ESCAPE))
	{
		SceneManager::SetNextScene(SceneID_Title);
	}
}

void SelectNumberOfPeopleScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(20, 20, 205, 70, GetColor(0, 0, 0), false);
	DrawBox(1104, 20, 1260, 85, GetColor(0, 0, 0), false);

	DrawGraph(375, 0, TextureData::NumberOfPeople, true);

	if (Choice == 0)
	{
		DrawBox(275, 120, 630, 640, GetColor(0, 0, 0), false);
		DrawBox(650, 120, 1005, 640, GetColor(0, 0, 0), false);
	}
	else if (Choice == 1)
	{
		//DrawExtendGraph();
		DrawBox(265, 110, 640, 650, GetColor(0, 0, 0), false);
		DrawBox(650, 120, 1005, 640, GetColor(0, 0, 0), false);
	}
	else if (Choice == 2)
	{
		DrawBox(275, 120, 630, 640, GetColor(0, 0, 0), false);
		DrawBox(640, 110, 1015, 650, GetColor(0, 0, 0), false);
		//DrawExtendGraph();
	}

		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "NumberOfPeople", GetColor(0, 0, 0));
}

bool SelectNumberOfPeopleScene::IsEnd() const
{
	if ((IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0) || (IsKeyPushed(KEY_INPUT_ESCAPE)))
	{
		TextureData::DeleteTex();
		return true;
	}
}