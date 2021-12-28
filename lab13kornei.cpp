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
//State - ������ ��� ��������� � ��������� �������� �� ������ ��������� � ������
	printf("State\n\n");
	weatherContext *a = new weatherContext;
	weatherContext *b = new weatherContext;
	weatherContext *c = new weatherContext;
	a->setWeatherState(new rainState());
	b->setWeatherState(new rainState());
	c->setWeatherState(new hailState());
	printf("������� 1\n");
	a->count();
	printf("\n������� 2\n");
	b->count();
	printf("\n������� 3\n");
	c->count();
	printf("\nMemento\n\n");
//Memento - ���������� ���������� � ���� � ����� �� ����������
	Memorier *stay = new Memorier();
	stay->init(1, 2, 3);
	stay->get();
	stay->createMemPoint();
	stay->init(3, 4, 5);
	stay->get();
	stay->init(50, 60, 70);
	stay->resetState();
	stay->get();
//Observer - ����������� ����������� � ���������� � ���� �� �������, ��������� ����
	printf("\nObserver\n\n");
	concreteDrift *exter = new concreteDrift();
	concreteObserver *viewi = new concreteObserver();
	exter->attach(viewi);
	exter->setState(-4);
	exter->setState(-8);
	_getch();
	return 0;
}

