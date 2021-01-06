#include "../common.h"

int m_timer;
int cursor;

int CursorPos[2];

int NowChoise;

int SelectPlayer;

int CursorPos1[2] = { 476, 161 };
int CursorPos2[2] = { 639, 161 };
int CursorPos3[2] = { 476, 324 };
int CursorPos4[2] = { 639, 324 };
int CursorPos5[2] = { 476, 485 };
int CursorPos6[2] = { 639, 485 };

int set1;
int set2;
int set3;
int set4;

SelectCharacterScene::SelectCharacterScene()
{
	SelectPlayer = 1;
	SceneBase::Choice_Min = 1;
	SceneBase::Choice_Max = 6;
	SceneBase::Choice = Choice_Min;

	set1 = 0;
	set2 = 0;
	set3 = 0;
	set4 = 0;

	TextureData::BackGround_BLUE	= LoadGraph("res/haikei_blue.png");

	TextureData::Enter = LoadGraph("res/enter.png");
	TextureData::Esc = LoadGraph("res/esc.png");

	TextureData::CharacterSelect	= LoadGraph("res/キャラ選択.png");

	TextureData::Character1			= LoadGraph("res/花火.png");
	TextureData::Character2			= LoadGraph("res/力こそパワー.png");
	TextureData::Character3			= LoadGraph("res/インビジブルショット.png");
	TextureData::Character4			= LoadGraph("res/神の一手.png");
	TextureData::Character5			= LoadGraph("res/ヘビーショット.png");
	TextureData::Character6			= LoadGraph("res/マグネット.png");

	TextureData::Player1			= LoadGraph("res/1P.png");
	TextureData::Player2			= LoadGraph("res/2P.png");
	TextureData::Player3			= LoadGraph("res/3P.png");
	TextureData::Player4			= LoadGraph("res/4P.png");

	TextureData::CharacterFlame		= LoadGraph("res/プレイヤー枠.png");
	TextureData::Skill_Name1		= LoadGraph("res/スキルアイコン_花火.png");
	TextureData::Skill_Name2		= LoadGraph("res/スキルアイコン_力こそパワー.png");
	TextureData::Skill_Name3		= LoadGraph("res/スキルアイコン_インビジブルショット.png");
	TextureData::Skill_Name4		= LoadGraph("res/スキルアイコン_神の一手.png");
	TextureData::Skill_Name5		= LoadGraph("res/スキルアイコン_ヘビーショット.png");
	TextureData::Skill_Name6		= LoadGraph("res/スキルアイコン_マグネット.png");
	TextureData::Skill_Desc1		= LoadGraph("res/スキル説明_花火png.png");
	TextureData::Skill_Desc2		= LoadGraph("res/スキル説明_力こそパワー.png");
	TextureData::Skill_Desc3		= LoadGraph("res/スキル説明_インビッジブルショット.png");
	TextureData::Skill_Desc4		= LoadGraph("res/スキル説明_神の一手.png");
	TextureData::Skill_Desc5		= LoadGraph("res/スキル説明_ヘビーショット.png");
	TextureData::Skill_Desc6		= LoadGraph("res/スキル説明_マグネット.png");
	TextureData::Icon				= LoadGraph("res/キャラクター一覧.png");

	TextureData::Cursor1_1			= LoadGraph("res/キャラ選択中枠1ｐ_1.png");
	TextureData::Cursor1_2			= LoadGraph("res/キャラ選択中枠1ｐ_2.png");
	TextureData::Cursor1_3			= LoadGraph("res/キャラ選択中枠1ｐ_3.png");
	TextureData::Cursor1_4			= LoadGraph("res/キャラ選択中枠1ｐ_4.png");

	TextureData::Cursor2_1			= LoadGraph("res/キャラ選択中枠2ｐ_1.png");
	TextureData::Cursor2_2			= LoadGraph("res/キャラ選択中枠2ｐ_2.png");
	TextureData::Cursor2_3			= LoadGraph("res/キャラ選択中枠2ｐ_3.png");
	TextureData::Cursor2_4			= LoadGraph("res/キャラ選択中枠2ｐ_4.png");

	TextureData::Cursor3_1			= LoadGraph("res/キャラ選択中枠3ｐ_1.png");
	TextureData::Cursor3_2			= LoadGraph("res/キャラ選択中枠3ｐ_2.png");
	TextureData::Cursor3_3			= LoadGraph("res/キャラ選択中枠3ｐ_3.png");
	TextureData::Cursor3_4			= LoadGraph("res/キャラ選択中枠3ｐ_4.png");
	
	TextureData::Cursor4_1			= LoadGraph("res/キャラ選択中枠4ｐ_1.png");
	TextureData::Cursor4_2			= LoadGraph("res/キャラ選択中枠4ｐ_2.png");
	TextureData::Cursor4_3			= LoadGraph("res/キャラ選択中枠4ｐ_3.png");
	TextureData::Cursor4_4			= LoadGraph("res/キャラ選択中枠4ｐ_4.png");

	TextureData::SetCursor1			= LoadGraph("res/キャラ確定枠１ｐ.png");
	TextureData::SetCursor2			= LoadGraph("res/キャラ確定枠２ｐ.png");
	TextureData::SetCursor3			= LoadGraph("res/キャラ確定枠３ｐ.png");
	TextureData::SetCursor4			= LoadGraph("res/キャラ確定枠４ｐ.png");
}

SelectCharacterScene::~SelectCharacterScene()
{	

}	

void SelectCharacterScene::Exec()
{	
	if (IsKeyPushed(KEY_INPUT_ESCAPE))
	{
		SceneManager::SetNextScene(SceneID_SelectNumberOfPeople);
	}

	m_timer++;
	if (m_timer >= 80)
	{
		m_timer = 0;
	}

	//カーソルのアニメーション用
	if (m_timer >= 0 && m_timer <= 19)
	{
		cursor = 1;
	}
	else if(m_timer >= 20 && m_timer <= 39)
	{
		cursor = 2;
	}
	else if(m_timer >= 40 && m_timer <= 59)
	{
		cursor = 3;
	}
	else
	{
		cursor = 4;
	}

	//カーソルの移動用
	if (IsKeyPushed(KEY_INPUT_UP))
	{
		if (Choice >= 3)
		{
			Choice -= 2;
		}
	}
	else if (IsKeyPushed(KEY_INPUT_DOWN))
	{
		if (Choice <= 4)
		{
			Choice += 2;
		}
	}
	else if (IsKeyPushed(KEY_INPUT_RIGHT))
	{
		if ((Choice % 2) != 0 && Choice <= 5)
		{
			Choice += 1;
		}
	}
	else if (IsKeyPushed(KEY_INPUT_LEFT))
	{
		if ((Choice % 2) == 0 && Choice >= 2)
		{
			Choice -= 1;
		}
	}
	switch (Choice)
	{
	case 1:
		CursorPos[0] = CursorPos1[0];
		CursorPos[1] = CursorPos1[1];
		break;
	case 2:
		CursorPos[0] = CursorPos2[0];
		CursorPos[1] = CursorPos2[1];
		break;
	case 3:
		CursorPos[0] = CursorPos3[0];
		CursorPos[1] = CursorPos3[1];
		break;
	case 4:
		CursorPos[0] = CursorPos4[0];
		CursorPos[1] = CursorPos4[1];
		break;
	case 5:
		CursorPos[0] = CursorPos5[0];
		CursorPos[1] = CursorPos5[1];
		break;
	case 6:
		CursorPos[0] = CursorPos6[0];
		CursorPos[1] = CursorPos6[1];
		break;
	}

	//キャラクター変更用
	if (IsKeyPushed(KEY_INPUT_RETURN))
	{
		switch (Choice)
		{
		case 1:
			NowChoise = 1;
			break;
		case 2:
			NowChoise = 2;
			break;
		case 3:
			NowChoise = 3;
			break;
		case 4:
			NowChoise = 4;
			break;
		case 5:
			NowChoise = 5;
			break;
		case 6:
			NowChoise = 6;
			break;
		default:
			break;
		}
		switch (SelectPlayer)
		{
		case 1:
			P1.Character = NowChoise;
			SelectPlayer ++;
			break;
		case 2:
			if (P1.Character != NowChoise)
			{
				P2.Character = NowChoise;
				if (SceneBase::People_Max == 2)
				{
					SceneManager::SetNextScene(SceneID_SelectStage);
					SelectPlayer++;
				}
				else
				{
					SelectPlayer++;
				}
			}
			break;
		case 3:
			if (P1.Character != NowChoise && P2.Character != NowChoise)
			{
				P3.Character = NowChoise;
				SelectPlayer++;
			}
			break;
		case 4:
			if (P1.Character != NowChoise && P2.Character != NowChoise && P3.Character != NowChoise)
			{
				P4.Character = NowChoise;
				SceneManager::SetNextScene(SceneID_SelectStage);
				SelectPlayer++;
			}
			break;
		default:
			break;
		}
	}
}

void SelectCharacterScene::Draw()
{
	DrawGraph(0, 0, TextureData::BackGround_BLUE, false);

	DrawGraph(20, 20, TextureData::Enter, true);
	DrawGraph(1104, 20, TextureData::Esc, true);

	DrawGraph(340, 0, TextureData::CharacterSelect, true);
	DrawGraph(475, 160, TextureData::Icon, true);

	DrawGraph(20, 100, TextureData::CharacterFlame, true);
	DrawGraph(860, 100, TextureData::CharacterFlame, true);
	DrawGraph(20, 384, TextureData::CharacterFlame, true);
	DrawGraph(860, 384, TextureData::CharacterFlame, true);
	
	//スキル欄の座標
	//DrawGraph(20, 110, TextureData::Skill, true);
	//DrawGraph(860, 110, TextureData::Skill, true);
	//DrawGraph(20, 394, TextureData::Skill, true);
	//DrawGraph(860, 394, TextureData::Skill, true);

	if (IsKeyPushed(KEY_INPUT_RETURN))
	{
		switch (P1.Character)
		{
		case 1:
			set1 = 1;
			break;
		case 2:
			set1 = 2;
			break;
		case 3:
			set1 = 3;
			break;
		case 4:
			set1 = 4;
			break;
		case 5:
			set1 = 5;
			break;
		case 6:
			set1 = 6;
			break;
		default:
			break;
		}
		switch (P2.Character)
		{
		case 1:
			set2 = 1;
			break;
		case 2:
			set2 = 2;
			break;
		case 3:
			set2 = 3;
			break;
		case 4:
			set2 = 4;
			break;
		case 5:
			set2 = 5;
			break;
		case 6:
			set2 = 6;
			break;
		default:
			break;
		}
		switch (P3.Character)
		{
		case 1:
			set3 = 1;
			break;
		case 2:
			set3 = 2;
			break;
		case 3:
			set3 = 3;
			break;
		case 4:
			set3 = 4;
			break;
		case 5:
			set3 = 5;
			break;
		case 6:
			set3 = 6;
			break;
		default:
			break;
		}
		switch (P4.Character)
		{
		case 1:
			set4 = 1;
			break;
		case 2:
			set4 = 2;
			break;
		case 3:
			set4 = 3;
			break;
		case 4:
			set4 = 4;
			break;
		case 5:
			set4 = 5;
			break;
		case 6:
			set4 = 6;
			break;
		default:
			break;
		}
	}
	//1P
	switch (set1)
	{
	case 1:
		DrawGraph(CursorPos1[0], CursorPos1[1], TextureData::SetCursor1, true);
		DrawGraph(236, 110, TextureData::Character1, true);
		DrawGraph(20, 110, TextureData::Skill_Desc1, true);
		break;
	case 2:
		DrawGraph(CursorPos2[0], CursorPos2[1], TextureData::SetCursor1, true);
		DrawGraph(236, 110, TextureData::Character2, true);
		DrawGraph(20, 110, TextureData::Skill_Desc2, true);
		break;
	case 3:
		DrawGraph(CursorPos3[0], CursorPos3[1], TextureData::SetCursor1, true);
		DrawGraph(236, 110, TextureData::Character3, true);
		DrawGraph(20, 110, TextureData::Skill_Desc3, true);
		break;
	case 4:
		DrawGraph(CursorPos4[0], CursorPos4[1], TextureData::SetCursor1, true);
		DrawGraph(236, 110, TextureData::Character4, true);
		DrawGraph(20, 110, TextureData::Skill_Desc4, true);
		break;
	case 5:
		DrawGraph(CursorPos5[0], CursorPos5[1], TextureData::SetCursor1, true);
		DrawGraph(236, 110, TextureData::Character5, true);
		DrawGraph(20, 110, TextureData::Skill_Desc5, true);
		break;
	case 6:
		DrawGraph(CursorPos6[0], CursorPos6[1], TextureData::SetCursor1, true);
		DrawGraph(236, 110, TextureData::Character6, true);
		DrawGraph(20, 110, TextureData::Skill_Desc6, true);
		break;
	default:
		break;
	}
	//2P
	switch (set2)
	{
	case 1:
		DrawGraph(CursorPos1[0], CursorPos1[1], TextureData::SetCursor2, true);
		DrawGraph(1076, 110, TextureData::Character1, true);
		DrawGraph(860, 110, TextureData::Skill_Desc1, true);
		break;
	case 2:
		DrawGraph(CursorPos2[0], CursorPos2[1], TextureData::SetCursor2, true);
		DrawGraph(1076, 110, TextureData::Character2, true);
		DrawGraph(860, 110, TextureData::Skill_Desc2, true);
		break;
	case 3:
		DrawGraph(CursorPos3[0], CursorPos3[1], TextureData::SetCursor2, true);
		DrawGraph(1076, 110, TextureData::Character3, true);
		DrawGraph(860, 110, TextureData::Skill_Desc3, true);
		break;
	case 4:
		DrawGraph(CursorPos4[0], CursorPos4[1], TextureData::SetCursor2, true);
		DrawGraph(1076, 110, TextureData::Character4, true);
		DrawGraph(860, 110, TextureData::Skill_Desc4, true);
		break;
	case 5:
		DrawGraph(CursorPos5[0], CursorPos5[1], TextureData::SetCursor2, true);
		DrawGraph(1076, 110, TextureData::Character5, true);
		DrawGraph(860, 110, TextureData::Skill_Desc5, true);
		break;
	case 6:
		DrawGraph(CursorPos6[0], CursorPos6[1], TextureData::SetCursor2, true);
		DrawGraph(1076, 110, TextureData::Character6, true);
		DrawGraph(860, 110, TextureData::Skill_Desc6, true);
		break;
	default:
		break;
	}
	//3P
	switch (set3)
	{
	case 1:
		DrawGraph(CursorPos1[0], CursorPos1[1], TextureData::SetCursor3, true);
		DrawGraph(236, 394, TextureData::Character1, true);
		DrawGraph(20, 394, TextureData::Skill_Desc1, true);
		break;
	case 2:
		DrawGraph(CursorPos2[0], CursorPos2[1], TextureData::SetCursor3, true);
		DrawGraph(236, 394, TextureData::Character2, true);
		DrawGraph(20, 394, TextureData::Skill_Desc2, true);
		break;
	case 3:
		DrawGraph(CursorPos3[0], CursorPos3[1], TextureData::SetCursor3, true);
		DrawGraph(236, 394, TextureData::Character3, true);
		DrawGraph(20, 394, TextureData::Skill_Desc3, true);
		break;
	case 4:
		DrawGraph(CursorPos4[0], CursorPos4[1], TextureData::SetCursor3, true);
		DrawGraph(236, 394, TextureData::Character4, true);
		DrawGraph(20, 394, TextureData::Skill_Desc4, true);
		break;
	case 5:
		DrawGraph(CursorPos5[0], CursorPos5[1], TextureData::SetCursor3, true);
		DrawGraph(236, 394, TextureData::Character5, true);
		DrawGraph(20, 394, TextureData::Skill_Desc5, true);
		break;
	case 6:
		DrawGraph(CursorPos6[0], CursorPos6[1], TextureData::SetCursor3, true);
		DrawGraph(236, 394, TextureData::Character6, true);
		DrawGraph(20, 394, TextureData::Skill_Desc6, true);
		break;
	default:
		break;
	}
	//4P
	switch (set4)
	{
	case 1:
		DrawGraph(CursorPos1[0], CursorPos1[1], TextureData::SetCursor4, true);
		DrawGraph(1076, 394, TextureData::Character1, true);
		DrawGraph(860, 394, TextureData::Skill_Desc1, true);
		break;
	case 2:
		DrawGraph(CursorPos2[0], CursorPos2[1], TextureData::SetCursor4, true);
		DrawGraph(1076, 394, TextureData::Character2, true);
		DrawGraph(860, 394, TextureData::Skill_Desc2, true);
		break;
	case 3:
		DrawGraph(CursorPos3[0], CursorPos3[1], TextureData::SetCursor4, true);
		DrawGraph(1076, 394, TextureData::Character3, true);
		DrawGraph(860, 394, TextureData::Skill_Desc3, true);
		break;
	case 4:
		DrawGraph(CursorPos4[0], CursorPos4[1], TextureData::SetCursor4, true);
		DrawGraph(1076, 394, TextureData::Character4, true);
		DrawGraph(20, 110, TextureData::Skill_Desc4, true);
		break;
	case 5:
		DrawGraph(CursorPos5[0], CursorPos5[1], TextureData::SetCursor4, true);
		DrawGraph(1076, 394, TextureData::Character5, true);
		DrawGraph(860, 394, TextureData::Skill_Desc5, true);
		break;
	case 6:
		DrawGraph(CursorPos6[0], CursorPos6[1], TextureData::SetCursor4, true);
		DrawGraph(1076, 394, TextureData::Character6, true);
		DrawGraph(860, 394, TextureData::Skill_Desc6, true);
		break;
	default:
		break;
	}

	switch (cursor)
	{
	case 1:
		if (SelectPlayer == 1)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor1_1, true);
		}
		if (SelectPlayer == 2)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor2_1, true);
		}
		if (SelectPlayer == 3)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor3_1, true);
		}
		if (SelectPlayer == 4)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor4_1, true);
		}
		break;
	case 2:
		if (SelectPlayer == 1)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor1_2, true);
		}
		if (SelectPlayer == 2)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor2_2, true);
		}
		if (SelectPlayer == 3)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor3_2, true);
		}
		if (SelectPlayer == 4)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor4_2, true);
		}
		break;
	case 3:
		if (SelectPlayer == 1)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor1_3, true);
		}
		if (SelectPlayer == 2)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor2_3, true);
		}
		if (SelectPlayer == 3)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor3_3, true);
		}
		if (SelectPlayer == 4)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor4_3, true);
		}
		break;
	case 4:
		if (SelectPlayer == 1)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor1_4, true);
		}
		if (SelectPlayer == 2)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor2_4, true);
		}
		if (SelectPlayer == 3)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor3_4, true);
		}
		if (SelectPlayer == 4)
		{
			DrawGraph(CursorPos[0], CursorPos[1], TextureData::Cursor4_4, true);
		}
		break;
	}

	switch (SelectPlayer)
	{
	case 1:
		switch (Choice)
		{
		case 1:
			DrawGraph(236, 110, TextureData::Character1, true);
			DrawGraph(20, 110, TextureData::Skill_Desc1, true);
			break;
		case 2:
			DrawGraph(236, 110, TextureData::Character2, true);
			DrawGraph(20, 110, TextureData::Skill_Desc2, true);
			break;
		case 3:
			DrawGraph(236, 110, TextureData::Character3, true);
			DrawGraph(20, 110, TextureData::Skill_Desc3, true);
			break;
		case 4:
			DrawGraph(236, 110, TextureData::Character4, true);
			DrawGraph(20, 110, TextureData::Skill_Desc4, true);
			break;
		case 5:
			DrawGraph(236, 110, TextureData::Character5, true);
			DrawGraph(20, 110, TextureData::Skill_Desc5, true);
			break;
		case 6:
			DrawGraph(236, 110, TextureData::Character6, true);
			DrawGraph(20, 110, TextureData::Skill_Desc6, true);
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (Choice)
		{
		case 1:
			DrawGraph(1076, 110, TextureData::Character1, true);
			DrawGraph(860, 110, TextureData::Skill_Desc1, true);
			break;
		case 2:
			DrawGraph(1076, 110, TextureData::Character2, true);
			DrawGraph(860, 110, TextureData::Skill_Desc2, true);
			break;
		case 3:
			DrawGraph(1076, 110, TextureData::Character3, true);
			DrawGraph(860, 110, TextureData::Skill_Desc3, true);
			break;
		case 4:
			DrawGraph(1076, 110, TextureData::Character4, true);
			DrawGraph(860, 110, TextureData::Skill_Desc4, true);
			break;
		case 5:
			DrawGraph(1076, 110, TextureData::Character5, true);
			DrawGraph(860, 110, TextureData::Skill_Desc5, true);
			break;
		case 6:
			DrawGraph(1076, 110, TextureData::Character6, true);
			DrawGraph(860, 110, TextureData::Skill_Desc6, true);
			break;
		default:
			break;
		}
		break;
	case 3:
		switch (Choice)
		{
		case 1:
			DrawGraph(236, 394, TextureData::Character1, true);
			DrawGraph(20, 394, TextureData::Skill_Desc1, true);
			break;
		case 2:
			DrawGraph(236, 394, TextureData::Character2, true);
			DrawGraph(20, 394, TextureData::Skill_Desc2, true);
			break;
		case 3:
			DrawGraph(236, 394, TextureData::Character3, true);
			DrawGraph(20, 394, TextureData::Skill_Desc3, true);
			break;
		case 4:
			DrawGraph(236, 394, TextureData::Character4, true);
			DrawGraph(20, 394, TextureData::Skill_Desc4, true);
			break;
		case 5:
			DrawGraph(236, 394, TextureData::Character5, true);
			DrawGraph(20, 394, TextureData::Skill_Desc5, true);
			break;
		case 6:
			DrawGraph(236, 394, TextureData::Character6, true);
			DrawGraph(20, 394, TextureData::Skill_Desc6, true);
			break;
		default:
			break;
		}
		break;
	case 4:
		switch (Choice)
		{
		case 1:
			DrawGraph(1076, 394, TextureData::Character1, true);
			DrawGraph(860, 394, TextureData::Skill_Desc1, true);
			break;
		case 2:
			DrawGraph(1076, 394, TextureData::Character2, true);
			DrawGraph(860, 394, TextureData::Skill_Desc2, true);
			break;
		case 3:
			DrawGraph(1076, 394, TextureData::Character3, true);
			DrawGraph(860, 394, TextureData::Skill_Desc3, true);
			break;
		case 4:
			DrawGraph(1076, 394, TextureData::Character4, true);
			DrawGraph(860, 394, TextureData::Skill_Desc4, true);
			break;
		case 5:
			DrawGraph(1076, 394, TextureData::Character5, true);
			DrawGraph(860, 394, TextureData::Skill_Desc5, true);
			break;
		case 6:
			DrawGraph(1076, 394, TextureData::Character6, true);
			DrawGraph(860, 394, TextureData::Skill_Desc6, true);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
	DrawGraph(320, 284, TextureData::Player1, true);
	DrawGraph(1160, 284, TextureData::Player2, true);
	DrawGraph(320, 568, TextureData::Player3, true);
	DrawGraph(1160, 568, TextureData::Player4, true);

		//画面左上にデバッグ用の文字を黒で表示する
	DrawString(20, 20, "SelectCharacterScene", GetColor(0, 0, 0));
}

bool SelectCharacterScene::IsEnd() const
{
	if((IsKeyPushed(KEY_INPUT_RETURN) && SelectPlayer == 5) || (SceneBase::People_Max == 2 && SelectPlayer == 3) ||(IsKeyPushed(KEY_INPUT_ESCAPE)))
	{
		TextureData::DeleteTex();
		return true;
	}
}