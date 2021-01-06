#include "../common.h"

SelectNumberOfPeopleScene::SelectNumberOfPeopleScene()
{
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 2;

	TextureData::BackGround_BLUE = LoadGraph("res/setumeihaikei.png");

	TextureData::Enter = LoadGraph("res/enter.png");
	TextureData::Esc = LoadGraph("res/esc.png");

	TextureData::NumberOfPeople = LoadGraph("res/プレイ人数選択.png");

	TextureData::Player2 = LoadGraph("res/2人であそぶ.png");
	TextureData::Player4 = LoadGraph("res/4人であそぶ.png");
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

	DrawGraph(20, 20, TextureData::Enter, true);
	DrawGraph(1104, 20, TextureData::Esc, true);

	DrawGraph(375, 0, TextureData::NumberOfPeople, true);

	if (Choice == 0)
	{
		DrawExtendGraph(275, 120, 630, 640, TextureData::Player2, false);
		DrawExtendGraph(650, 120, 1005, 640, TextureData::Player4, false);
	}
	else if (Choice == 1)
	{
		//DrawExtendGraph();
		DrawExtendGraph(265, 110, 640, 650, TextureData::Player2, false);
		DrawExtendGraph(650, 120, 1005, 640, TextureData::Player4, false);
	}
	else if (Choice == 2)
	{
		DrawExtendGraph(275, 120, 630, 640, TextureData::Player2, false);
		DrawExtendGraph(640, 110, 1015, 650, TextureData::Player4, false);
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