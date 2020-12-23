#include "SceneBase.h"

int SceneBase::VolumePer;

int SceneBase::Choice_Min;
int SceneBase::Choice_Max;
int SceneBase::Choice;

int SceneBase::People_Max;

int SceneBase::Stage;

SceneBase::SceneBase()
	: m_Step(0)
{
	VolumePer = 50;
}

SceneBase::~SceneBase()
{
	
}
