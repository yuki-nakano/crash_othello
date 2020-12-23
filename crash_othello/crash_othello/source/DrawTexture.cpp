#include "./common.h"

int TextureData::BackGround_BLUE;
int TextureData::Button_Start;
int TextureData::Button_Rule;

int TextureData::Description;

int TextureData::NumberOfPeople;

int TextureData::CharacterSelect;
int TextureData::Character1;
int TextureData::Character2;
int TextureData::Character3;
int TextureData::Character4;
int TextureData::Character5;
int TextureData::Character6;

int TextureData::Player1;
int TextureData::Player2;
int TextureData::Player3;
int TextureData::Player4;

int TextureData::CharacterFlame;
int TextureData::Skill_Name1;
int TextureData::Skill_Name2;
int TextureData::Skill_Name3;
int TextureData::Skill_Name4;
int TextureData::Skill_Name5;
int TextureData::Skill_Name6;
int TextureData::Skill_Desc1;
int TextureData::Skill_Desc2;
int TextureData::Skill_Desc3;
int TextureData::Skill_Desc4;
int TextureData::Skill_Desc5;
int TextureData::Skill_Desc6;
int TextureData::Icon;

int TextureData::SetCursor1;
int TextureData::SetCursor2;
int TextureData::SetCursor3;
int TextureData::SetCursor4;

int TextureData::Cursor1_1;
int TextureData::Cursor1_2;
int TextureData::Cursor1_3;
int TextureData::Cursor1_4;
int TextureData::Cursor2_1;
int TextureData::Cursor2_2;
int TextureData::Cursor2_3;
int TextureData::Cursor2_4;
int TextureData::Cursor3_1;
int TextureData::Cursor3_2;
int TextureData::Cursor3_3;
int TextureData::Cursor3_4;
int TextureData::Cursor4_1;
int TextureData::Cursor4_2;
int TextureData::Cursor4_3;
int TextureData::Cursor4_4;

int TextureData::StageSelect;

TextureData::TextureData()
{
	//画像の読み込み

	/*TextureData::BackGround_BLUE		= LoadGraph("res/ゲーム画面背景_青.jpg");
	TextureData::BackGround_YELLOW		= LoadGraph("res/ゲーム画面背景_黄.jpg");

	TextureData::CharacterSelect		= LoadGraph("res/キャラ選択.png");

	TextureData::Character1				= LoadGraph("res/キャラ1.png");
	TextureData::Character2				= LoadGraph("res/キャラ2.png");
	TextureData::Character3				= LoadGraph("res/キャラ3.png");
	TextureData::Character4				= LoadGraph("res/キャラ4.png");

	TextureData::Player1				= LoadGraph("res/1P.png");
	TextureData::Player2				= LoadGraph("res/2P.png");
	TextureData::Player3				= LoadGraph("res/3P.png");
	TextureData::Player4				= LoadGraph("res/4P.png");

	TextureData::CharacterFlame			= LoadGraph("res/プレイヤー枠.png");
	TextureData::Skill					= LoadGraph("res/スキル.png")
	TextureData::Icon = LoadGraph("res/アイコン.png");
	TextureData::Cursor = LoadGraph("res/キャラ選カーソル.png");*/
}

TextureData::~TextureData()
{

}

bool TextureData::DeleteTex()
{
	DeleteGraph(TextureData::BackGround_BLUE);
	DeleteGraph(TextureData::Button_Start);
	DeleteGraph(TextureData::Button_Rule);
	DeleteGraph(TextureData::Description);
	DeleteGraph(TextureData::NumberOfPeople);
	DeleteGraph(TextureData::CharacterSelect);
	DeleteGraph(TextureData::Character1);
	DeleteGraph(TextureData::Character2);
	DeleteGraph(TextureData::Character3);
	DeleteGraph(TextureData::Character4);
	DeleteGraph(TextureData::Character5);
	DeleteGraph(TextureData::Character6);
	DeleteGraph(TextureData::Player1);
	DeleteGraph(TextureData::Player2);
	DeleteGraph(TextureData::Player3);
	DeleteGraph(TextureData::Player4);
	DeleteGraph(TextureData::CharacterFlame);
	DeleteGraph(TextureData::Skill_Name1);
	DeleteGraph(TextureData::Skill_Name2);
	DeleteGraph(TextureData::Skill_Name3);
	DeleteGraph(TextureData::Skill_Name4);
	DeleteGraph(TextureData::Skill_Name5);
	DeleteGraph(TextureData::Skill_Name6);
	DeleteGraph(TextureData::Skill_Desc1);
	DeleteGraph(TextureData::Skill_Desc2);
	DeleteGraph(TextureData::Skill_Desc3);
	DeleteGraph(TextureData::Skill_Desc4);
	DeleteGraph(TextureData::Skill_Desc5);
	DeleteGraph(TextureData::Skill_Desc6);
	DeleteGraph(TextureData::Icon);
	DeleteGraph(TextureData::SetCursor1);
	DeleteGraph(TextureData::SetCursor2);
	DeleteGraph(TextureData::SetCursor3);
	DeleteGraph(TextureData::SetCursor4);
	DeleteGraph(TextureData::Cursor1_1);
	DeleteGraph(TextureData::Cursor1_2);
	DeleteGraph(TextureData::Cursor1_3);
	DeleteGraph(TextureData::Cursor1_4);
	DeleteGraph(TextureData::Cursor2_1);
	DeleteGraph(TextureData::Cursor2_2);
	DeleteGraph(TextureData::Cursor2_3);
	DeleteGraph(TextureData::Cursor2_4);
	DeleteGraph(TextureData::Cursor3_1);
	DeleteGraph(TextureData::Cursor3_2);
	DeleteGraph(TextureData::Cursor3_3);
	DeleteGraph(TextureData::Cursor3_4);
	DeleteGraph(TextureData::Cursor4_1);
	DeleteGraph(TextureData::Cursor4_2);
	DeleteGraph(TextureData::Cursor4_3);
	DeleteGraph(TextureData::Cursor4_4);
	DeleteGraph(TextureData::StageSelect);

	return true;
}