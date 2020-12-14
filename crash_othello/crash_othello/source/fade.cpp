#include "common.h"


void Fade::InitFade(FadeType fade_type)
{
	switch (fade_type)
	{
	case kFadeOut:
		alpha = 0;
		break;
	case kFadeIn:
		alpha = 255;
		break;
	}

	initCheck_Fade = true;
}

bool Fade::MakeToFluctuateAlpha(FadeType fade_type, FadeSpeed fade_speed)
{
	switch (fade_type)
	{
	case kFadeOut:
		alpha += fade_speed;
		break;
	case kFadeIn:
		alpha -= fade_speed;
		break;
	default:
		return true;
		break;
	}

	if (alpha == 255 || alpha == 0)
	{
		return false;
	}

	return true;
}

FadeStatus Fade::RunFade(FadeType fade_type, FadeSpeed fade_speed)
{
	if (fade_type == kFadeNot)
	{
		return kDonotFade;
	}

	if (!initCheck_Fade)
	{
		InitFade(fade_type);
	}

	if (MakeToFluctuateAlpha(fade_type, fade_speed) == false)
	{
		initCheck_Fade = false;
		if (fade_type == kFadeIn)
		{
			return kFinishedFadeIn;
		}
		else if (fade_type == kFadeOut)
		{
			return kFinishedFadeOut;
		}

	}
	else
	{
		return kDoingFade;
	}
}

void Fade::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
}