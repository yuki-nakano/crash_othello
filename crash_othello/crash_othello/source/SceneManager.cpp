#include "./common.h"

//staticなメンバ変数を初期化
SceneID SceneManager::m_NextSceneID = SceneID_Invalid;

SceneManager::SceneManager()
	:m_pScene(nullptr)
{
	//最初に実行するシーンを作成する
	SetNextScene(SceneID_Title);
	m_pScene = create_NextScene();
}

SceneManager::~SceneManager()
{
	delete m_pScene;
	m_pScene = nullptr;
}

void SceneManager::Exec()
{
	if (m_pScene == nullptr)
	{
		return;
	}

	m_pScene->Exec();
	if (m_pScene->IsEnd())
	{
		delete m_pScene;
		m_pScene = create_NextScene();
	}
}

void SceneManager::Draw()
{
	if (m_pScene == nullptr)
	{
		return;
	}

	m_pScene->Draw();
}

void SceneManager::SetNextScene(SceneID next_)
{
	m_NextSceneID = next_;
}

SceneBase* SceneManager::create_NextScene()
{
	SceneBase* next = nullptr;
	switch (m_NextSceneID)
	{
		//ここにそれぞれSceneBaseを継承した派生クラスをnewする処理を書く
		//シーンの増減があってもヘッダのインクルードとここ以外に変更は必要ない
	case SceneID_Title:
		next = new TitleScene();
		break;
	case SceneID_Option:
		next = new OptionScene();
		break;
	case SceneID_Description:
		next = new DescriptionScene();
		break;
	case SceneID_SelectNumberOfPeople:
		next = new SelectNumberOfPeopleScene();
		break;
	case SceneID_SelectCharacter:
		next = new SelectCharacterScene();
		break;
	case SceneID_SelectStage:
		next = new SelectStageScene();
		break;
	case SceneID_Play:
		next = new PlayScene();
		break;
	case SceneID_CheckSkill:
		next = new CheckSkillScene();
		break;
	case SceneID_Result:
		next = new ResultScene();
		break;
	case SceneID_Outcome:
		next = new OutComeScene();
		break;
	case SceneID_BacktoTitle:
		next = new BackToTitleScene();
		break;
	default:
		break;
	}
	return next;
}