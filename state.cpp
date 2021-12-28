#include "stdafx.h"

int s;

void highRainState::setReactions(weatherContext *t)
{
	printf("������� �� ������\n");
}

void weatherState::setReactions(weatherContext *t)
{
	printf("������� �� �����: ������?\n");
	scanf("%i", &s);
	if (s > 5)
		t->setWeatherState(new highRainState());
}

void highWindState::setReactions(weatherContext *t)
{
	printf("������� �� �����\n");
}

void weatherState::setReactions(weatherContext *t)
{
	printf("������� �� ����\n");
	printf("������ �����������?");
	scanf("%i", &s);
	if (s < 0)
		t->setWeatherState(new highWindState());
}

