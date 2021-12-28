#include "stdafx.h"

int s;

void highRainState::setReactions(weatherContext *t)
{
	printf("Реакция на ливень\n");
}

void weatherState::setReactions(weatherContext *t)
{
	printf("Реакция на дождь: сильно?\n");
	scanf("%i", &s);
	if (s > 5)
		t->setWeatherState(new highRainState());
}

void highWindState::setReactions(weatherContext *t)
{
	printf("Реакция на ветер\n");
}

void weatherState::setReactions(weatherContext *t)
{
	printf("Реакция на град\n");
	printf("Погода успокоилась?");
	scanf("%i", &s);
	if (s < 0)
		t->setWeatherState(new highWindState());
}

