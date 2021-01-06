#include "SceneBase.h"

int SceneBase::VolumePer;

int SceneBase::Choice_Min;
int SceneBase::Choice_Max;
int SceneBase::Choice;

int SceneBase::People_Max;

int SceneBase::Stage;

float SceneBase::back_posx1;
float SceneBase::back_posy1;
float SceneBase::back_posx2;
float SceneBase::back_posy2;
float SceneBase::back_posx3;
float SceneBase::back_posy3;
float SceneBase::back_posx4;
float SceneBase::back_posy4;
float SceneBase::back_posx5;
float SceneBase::back_posy5;
float SceneBase::back_posx6;
float SceneBase::back_posy6;

float SceneBase::scroll_speedx;
float SceneBase::scroll_speedy;

SceneBase::SceneBase()
	: m_Step(0)
{
	VolumePer = 50;
}

SceneBase::~SceneBase()
{
	
}
