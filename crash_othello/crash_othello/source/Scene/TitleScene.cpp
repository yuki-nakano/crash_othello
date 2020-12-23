#include "../common.h"

int back_posx1 = 0;				//背景配置のイメージ
int back_posy1 = 0;				//		4
int back_posx2 = 0;				//	2	3
int back_posy2 = -720;			//	1	
int back_posx3 = 1280;
int back_posy3 = -720;
int back_posx4 = 1280;
int back_posy4 = 0;

int scroll_speed = 5;


TitleScene::TitleScene()
{
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 2;

	//音声の読み込み(変数名は仮置き)
	SoundData::A = LoadSoundMem("res/Sound/START!!.mp3"/*"res/Sound/retroparty.mp3"*/);
	ChangeVolumeSoundMem(255 * SceneBase::VolumePer / 100, SoundData::A);

	//画像の読み込み
	TextureData::BackGround_BLUE = LoadGraph("res/haikei_blue.png");
	TextureData::Button_Start = LoadGraph("res/タイトルボタン_スタート.png");
	TextureData::Button_Rule = LoadGraph("res/タイトルボタン_ルール.png");

	SceneBase::Choice = 0;
}
TitleScene::~TitleScene()
{
	
}
void TitleScene::Exec()
{
	if (CheckSoundMem(SoundData::A) != 1 && DrawGraph(back_posx4, back_posy4, TextureData::BackGround_BLUE, false) == 0)
	{
		PlaySoundMem(SoundData::A, DX_PLAYTYPE_LOOP, true);
	}

	/*back_posx1 -= scroll_speed;
	back_posy1 += scroll_speed;
	back_posx2 -= scroll_speed;
	back_posy2 += scroll_speed;
	back_posx3 -= scroll_speed;
	back_posy3 += scroll_speed;
	back_posx4 -= scroll_speed;
	back_posy4 += scroll_speed;*/

	if (back_posx1 <= -720 && back_posy1 >= 720)
	{
		back_posx1 = 720;
		back_posy1 = -720;
		back_posx4 = 560;
		back_posy4 = -720;
	}
	if (back_posx2 <= -720 && back_posy2 >= 0)
	{
		back_posx2 = 0;
		back_posy2 = -720;
		back_posx3 = 2000;
		back_posy3 = -720;
	}

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
		SceneManager::SetNextScene(SceneID_SelectNumberOfPeople);
	}
	else if (Choice == 2 && IsKeyPushed(KEY_INPUT_RETURN))
	{
		SceneManager::SetNextScene(SceneID_Description);
	}
}

void TitleScene::Draw()
{
	DrawGraph(back_posx1, back_posy1, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx2, back_posy2, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx3, back_posy3, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx4, back_posy4, TextureData::BackGround_BLUE, false);

	if (Choice == 0)
	{
		DrawGraph(250, 500, TextureData::Button_Start, true);
		DrawGraph(700, 500, TextureData::Button_Rule, true);
	}
	else if (Choice == 1)
	{
		DrawExtendGraph(240, 490, 590, 635, TextureData::Button_Start, true);
		DrawGraph(700, 500, TextureData::Button_Rule, true);
	}
	else if (Choice == 2)
	{
		DrawGraph(250, 500, TextureData::Button_Start, true);
		DrawExtendGraph(690, 490, 1040, 635, TextureData::Button_Rule, true);
	}

	DrawBox(190, 0, 1090, 400, GetColor(0, 0, 0), false);
		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
	if (IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0)
	{
		TextureData::DeleteTex();
		return true;
	}
}