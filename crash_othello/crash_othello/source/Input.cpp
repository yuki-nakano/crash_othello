#include "common.h"

char keyStatus[256];
char previousKeyStatus[256];

void UpdateKeyStatus()
{
	for (int i = 0; i < 256; i++)
	{
		previousKeyStatus[i] = keyStatus[i];
	}

	GetHitKeyStateAll(keyStatus);
}

bool IsKeyPushed(int key)
{
	if (previousKeyStatus[key] == 0 && keyStatus[key] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsKeyHeld(int key)
{
	if (previousKeyStatus[key] == 1 && keyStatus[key] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsKeyRelesed(int key)
{
	if (previousKeyStatus[key] == 1 && keyStatus[key] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
