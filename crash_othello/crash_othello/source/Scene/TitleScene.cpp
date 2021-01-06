#include "../common.h"

		
//int back_posx1 = 0;
//int back_posy1 = 0;

//int back_posx4 = 1280;
//int back_posy4 = 0;


TitleScene::TitleScene()
{
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 2;

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

	//音声の読み込み(変数名は仮置き)
	SoundData::A = LoadSoundMem("res/Sound/START!!.mp3"/*"res/Sound/retroparty.mp3"*/);
	ChangeVolumeSoundMem(255 * SceneBase::VolumePer / 100, SoundData::A);

	//画像の読み込み
	TextureData::Title = LoadGraph("res/タイトルロゴ.png");
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
	/*back_posx1 -= scroll_speed;
	back_posx4 -= scroll_speed;*/

	/*if (back_posx1 <= -1280)
	{
		back_posx1 = 1280;
	}
	if (back_posx4 <= -1280)
	{
		back_posx4 = 1280;
	}*/
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
	DrawGraph(back_posx5, back_posy5, TextureData::BackGround_BLUE, false);
	DrawGraph(back_posx6, back_posy6, TextureData::BackGround_BLUE, false);
	
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

	DrawGraph(190, 0, TextureData::Title, true);
		//画面左上にデバッグ用の文字を黒で表示する
	//DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
	if (IsKeyPushed(KEY_INPUT_RETURN) && Choice != 0)
	{
		StopSoundMem(SoundData::A);
		DeleteSoundMem(SoundData::A);
		TextureData::DeleteTex();
		return true;
	}
}