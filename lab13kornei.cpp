// lab13kornei.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "state.h"
#include "memento.h"
#include "observer.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
//State - задаем три состояния и проверяем переходы из одного состояния в другое
	printf("State\n\n");
	weatherContext *a = new weatherContext;
	weatherContext *b = new weatherContext;
	weatherContext *c = new weatherContext;
	a->setWeatherState(new rainState());
	b->setWeatherState(new rainState());
	c->setWeatherState(new hailState());
	printf("Участок 1\n");
	a->count();
	printf("\nУчасток 2\n");
	b->count();
	printf("\nУчасток 3\n");
	c->count();
	printf("\nMemento\n\n");
//Memento - запоминаем информацию о реке и потом ее возвращаем
	Memorier *stay = new Memorier();
	stay->init(1, 2, 3);
	stay->get();
	stay->createMemPoint();
	stay->init(3, 4, 5);
	stay->get();
	stay->init(50, 60, 70);
	stay->resetState();
	stay->get();
//Observer - привязываем наблюдателя к информации о льде на участке, обновляем инфу
	printf("\nObserver\n\n");
	concreteDrift *exter = new concreteDrift();
	concreteObserver *viewi = new concreteObserver();
	exter->attach(viewi);
	exter->setState(-4);
	exter->setState(-8);
	_getch();
	return 0;
}

