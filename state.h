int s;

class weatherState {
public:
	virtual void setReactions() = 0;
};

class weatherContext {
	weatherState *currentState;
public:
	void setWeatherState(weatherState *wev)
	{
		currentState = wev;
	}
	void count()
	{
		if (currentState)
			currentState->setReactions();
	}
};

class highRainState : public weatherState {
public:
	void setReactions()
	{
		printf("����� ������\n");
	}
};

class rainState : public weatherState {
public:
	void setReactions()
	{
		weatherContext *t = new weatherContext;
		printf("����� �����: ������? ");
		scanf("%i", &s);
		if (s > 5)
		{
			highRainState *k = new highRainState();
			t->setWeatherState(k);
			t->count();
		}
	}
};


class highWindState : public weatherState {
public:
	void setReactions()
	{
		printf("����� �����\n");
	}
};

class hailState : public weatherState {
public:
	void setReactions()
	{
		weatherContext *t = new weatherContext;
		printf("����� ����\n");
		printf("������ �����������? ");
		scanf("%i", &s);
		if (s < 0)
		{
			highWindState *k = new highWindState();
			t->setWeatherState(k);
			t->count();
		}
	}
};


