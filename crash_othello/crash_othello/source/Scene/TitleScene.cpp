#include "../common.h"

TitleScene::TitleScene()
{
	//音声の読み込み(変数名は仮置き)
	SoundData::A = LoadSoundMem("res/Sound/START!!.mp3"/*"res/Sound/retroparty.mp3"*/);
	ChangeVolumeSoundMem(255 * SceneBase::VolumePer / 100, SoundData::A);

	//画像の読み込み
	TextureData::BackGround_BLUE = LoadGraph("res/ゲーム画面背景_青.jpg");
}
TitleScene::~TitleScene()
{
	
}
void TitleScene::Exec()
{
	if (CheckSoundMem(SoundData::A) != 1 && DrawGraph(0, 0, TextureData::BackGround_BLUE, false) == 0)
	{
		PlaySoundMem(SoundData::A, DX_PLAYTYPE_LOOP, true);
	}

	/*m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::SetNextScene(SceneID_Description);
	}*/
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawBox(190, 0, 1090, 400, GetColor(0, 0, 0), false);
	DrawBox(250, 500, 580, 625, GetColor(0, 0, 0), false);
	DrawBox(700, 500, 1030, 625, GetColor(0, 0, 0), false);
		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step >= 120);
}